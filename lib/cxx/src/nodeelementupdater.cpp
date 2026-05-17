#include <sway/webcore/dom/htmldocument.hpp>
#include <sway/webcore/dom/htmlelement.hpp>
#include <sway/webcore/nodeelementupdater.hpp>

namespace sway::webcore {

auto NodeElementUpdater::visit(core::typedefs::VisitablePtr_t guest) -> u32_t {
  auto *node = static_cast<TreeNodeElement *>(guest);
  core::NodeOptionalSharedPtr_t parentOpt = node->getParentNode();
  if (!parentOpt.has_value()) {
    return core::toBase(core::TraverserAction::Enum::ABORT);
  }

  TreeNodeElement *parent = (TreeNodeElement *)parentOpt.value().get();

  // EM_ASM(
  //     {
  //         console.groupCollapsed("ELEMENT " + UTF8ToString($0));
  //         console.log("NODE_INDEX " + UTF8ToString($1));
  //         console.groupEnd();
  //     },
  //     guest->getNodeUid().c_str(), std::to_string<core::NodeIndex>(guest->getNodeIndex()).c_str());

  if (parent) {
    auto region = parent->getRegionByNodeIdx(node->getNodeIndex());
    pendingUpdateNodes_.emplace_back(parent, node, region);
  }

  return core::toBase(core::TraverserAction::Enum::CONTINUE);
}

void NodeElementUpdater::forceUpdate() {
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
