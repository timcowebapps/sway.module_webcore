#include <sway/webcore/dom/htmldocument.hpp>
#include <sway/webcore/dom/htmlelement.hpp>
#include <sway/webcore/nodeelementupdater.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)

u32_t NodeElementUpdater::visit(core::utils::Visitable *guest) {
  // TreeNodeElement *parent = (TreeNodeElement *)guest->getParentNode();
  //  if (!parent)
  //  	return core::container::TraversalAction_t::Abort;

  // EM_ASM(
  //     {
  //         console.groupCollapsed("ELEMENT " + UTF8ToString($0));
  //         console.log("NODE_INDEX " + UTF8ToString($1));
  //         console.groupEnd();
  //     },
  //     guest->getNodeUid().c_str(), std::to_string<core::container::NodeIdx>(guest->getNodeIdx()).c_str());

  // if (parent) {
  //     auto region = parent->getRegionByNodeId("guest->getNodeUid()");
  //     pendingUpdateNodes_.emplace_back(parent, (TreeNodeElement *)guest, region);
  // }

  return core::detail::toUnderlying(core::utils::Traverser::Action::CONTINUE);
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

NAMESPACE_END(webcore)
NAMESPACE_END(sway)
