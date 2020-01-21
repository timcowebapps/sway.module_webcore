#include <sway/webcore/nodeelementmounter.h>
#include <sway/webcore/dom/htmldocument.h>
#include <sway/webcore/dom/htmlelement.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)

NodeElementMounter::NodeElementMounter() {
	// Empty
}

core::containers::TraversalAction_t NodeElementMounter::visit(core::containers::HierarchyNode * node) {
	TreeNodeElement * parent = (TreeNodeElement *) node->getParentNode();
	// if (!parent)
	// 	return core::containers::TraversalAction_t::Abort;

	EM_ASM({
		console.groupCollapsed("ELEMENT " + UTF8ToString($0));
		console.log("NODE_INDEX " + UTF8ToString($1));
		console.groupEnd();
	}, node->getNodeUid().c_str(), std::to_string<core::containers::HierarchyNodeIdx>(node->getNodeIdx()).c_str());

	if (parent) {
		RegionPtr_t region = parent->getRegionByNodeId(node->getNodeUid());
		_pendingUpdateNodes.emplace_back(parent, (TreeNodeElement *) node, region);
	}

	return core::containers::TraversalAction_t::Continue;
}

void NodeElementMounter::forceUpdate() {
	const size_t numUpdates = _pendingUpdateNodes.size();
	if (numUpdates == 0)
		return;

	//std::reverse(_pendingUpdateNodes.begin(), _pendingUpdateNodes.end());

	while (!_pendingUpdateNodes.empty()) {
		PendingNode pendingNode = _pendingUpdateNodes.front();
		_synchronizer.applyPendingUpdate(pendingNode);
		_pendingUpdateNodes.erase(
			std::remove_if(_pendingUpdateNodes.begin(), _pendingUpdateNodes.end(), [&](PendingNode node) {
				return node.element.first == pendingNode.element.first;
			}), _pendingUpdateNodes.end()
		);
	}
}

NAMESPACE_END(webcore)
NAMESPACE_END(sway)
