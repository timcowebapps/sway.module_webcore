#include <sway/webcore/dom/htmldocument.hpp>
#include <sway/webcore/dom/htmlelement.hpp>
#include <sway/webcore/nodeelementmounter.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)

u32_t NodeElementMounter::visit(core::utils::Visitable *guest) {
  auto *node = static_cast<core::container::Node *>(guest);
  auto parentNode = node->getParentNode();
  if ( parentNode != std::nullopt ) {
    auto *parentNodeElem = (TreeNodeElement *)parentNode.value().get();
    auto region = parentNodeElem->getRegionByNodeIdx(node->getNodeIdx());

    pendingUpdateNodes_.emplace_back(
        (struct PendingNode){ .element = std::make_pair("node->getNodeUid()", parentNodeElem),
            .parentElement = (TreeNodeElement *)node,
            .region = region });
  }

#ifdef _EMSCRIPTEN
  //  if (!parentNodeElem)
  //  	return core::container::TraversalAction_t::Abort;

  // EM_ASM(
  //     {
  //         console.groupCollapsed("ELEMENT " + UTF8ToString($0));
  //         console.log("NODE_INDEX " + UTF8ToString($1));
  //         console.groupEnd();
  //     },
  //     node->getNodeUid().c_str(), std::to_string<core::container::NodeIdx>(node->getNodeIdx()).c_str());

  // if (parentNodeElem) {
  //     auto region = parentNodeElem->getRegionByNodeId(node->getNodeUid());
  //     pendingUpdateNodes_.emplace_back(parentNodeElem, (TreeNodeElement *)node, region);
  // }
#endif

  return core::detail::toUnderlying(core::utils::Traverser::Action::CONTINUE);
}

void NodeElementMounter::forceUpdate() {
  const size_t numUpdates = pendingUpdateNodes_.size();
  if ( numUpdates == 0 ) {
    return;
  }

  // std::reverse(pendingUpdateNodes_.begin(), pendingUpdateNodes_.end());

  while ( !pendingUpdateNodes_.empty() ) {
    PendingNode pendingNode = pendingUpdateNodes_.front();
    synchronizer_.applyPendingUpdate(pendingNode);
    pendingUpdateNodes_.erase(std::remove_if(pendingUpdateNodes_.begin(), pendingUpdateNodes_.end(),
                                  [&](PendingNode node) { return node.element.first == pendingNode.element.first; }),
        pendingUpdateNodes_.end());
  }
}

NAMESPACE_END(webcore)
NAMESPACE_END(sway)
