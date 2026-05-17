#include <sway/core/utilities/visitor/traverseractions.hpp>
#include <sway/webcore/dom/htmldocument.hpp>
#include <sway/webcore/dom/htmlelement.hpp>
#include <sway/webcore/nodeelementmounter.hpp>

namespace sway::webcore {

auto NodeElementMounter::visit(core::Visitable *guest) -> u32_t {
  auto *node = static_cast<TreeNodeElement *>(guest);
  auto parentOptional = node->getParentNode();
  if (!parentOptional.has_value()) {
    return core::toBase(core::TraverserAction::Enum::ABORT);
  }

  auto parent = static_cast<TreeNodeElement *>(parentOptional.value().get());
  auto region = parent->getRegionByNodeIdx(node->getNodeIndex());

  pendingUpdateNodes_.emplace_back(parent, node, region);

#ifdef EMSCRIPTEN_PLATFORM
  //  if (!parentNodeElem)
  //  	return core::TraversarAction_t::Enum::ABORT;

  // EM_ASM(
  //     {
  //         console.groupCollapsed("ELEMENT " + UTF8ToString($0));
  //         console.log("NODE_INDEX " + UTF8ToString($1));
  //         console.groupEnd();
  //     },
  //     node->getNodeUid().c_str(), std::to_string<core::NodeIndex>(node->getNodeIndex()).c_str());

  // if (parentNodeElem) {
  //     auto region = parentNodeElem->getRegionByNodeId(node->getNodeUid());
  //     pendingUpdateNodes_.emplace_back(parentNodeElem, (TreeNodeElement *)node, region);
  // }
#endif

  return core::toBase(core::TraverserAction::Enum::CONTINUE);
}

void NodeElementMounter::forceUpdate() {
  const size_t numUpdates = pendingUpdateNodes_.size();
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
