#include <sway/webcore/dom/htmldocument.hpp>
#include <sway/webcore/dom/htmlelement.hpp>
#include <sway/webcore/nodeelementupdater.hpp>

namespace sway::webcore {

EMSCRIPTEN_BINDING_BEGIN(NodeElementUpdater)
emscripten::class_<NodeElementUpdater, emscripten::base<core::Traverser>>("NodeElementUpdater")
    .smart_ptr<std::shared_ptr<NodeElementUpdater>>("NodeElementUpdaterSmartPtr")
    .constructor<>()
    .function("forceUpdate", &NodeElementUpdater::forceUpdate);
EMSCRIPTEN_BINDING_END()

auto NodeElementUpdater::visit(core::typedefs::VisitablePtr_t guest) -> u32_t {
  auto *node = static_cast<TreeNodeElement *>(guest);
  core::NodeOptionalSharedPtr_t parentOpt = node->getParentNode();
  if (!parentOpt.has_value()) {
    return core::toBase(core::TraverserAction::Enum::ABORT);
  }

  TreeNodeElement *parent = (TreeNodeElement *)parentOpt.value().get();

  EM_ASM(
      {
        console.groupCollapsed("ELEMENT " + UTF8ToString($0));
        console.log("NODE_INDEX " + UTF8ToString($1));
        console.groupEnd();
      },
      node->getHtmlElementId().c_str(), Representation<core::NodeIndex>::get(node->getNodeIndex()).c_str());

  if (parent) {
    auto region = parent->getRegionByNodeIdx(node->getNodeIndex());
    pendingUpdateNodes_.emplace_back(parent, node, region);
  }

  return core::toBase(core::TraverserAction::Enum::CONTINUE);
}

void NodeElementUpdater::forceUpdate() {
  const size_t numUpdates = pendingUpdateNodes_.size();
  EM_ASM_INT({ console.log("NUM UPDATES " + $0); }, numUpdates);

  if (numUpdates == 0) {
    return;
  }

  // std::reverse(pendingUpdateNodes_.begin(), pendingUpdateNodes_.end());

  while (!pendingUpdateNodes_.empty()) {
    PendingNode pendingNode = pendingUpdateNodes_.front();
    synchronizer_.applyPendingUpdate(pendingNode);
    pendingUpdateNodes_.erase(std::remove_if(pendingUpdateNodes_.begin(), pendingUpdateNodes_.end(),
                                  [&](PendingNode node) { return node.element.first == pendingNode.element.first; }),
        pendingUpdateNodes_.end());
  }
}

}  // namespace sway::webcore
