#include <sway/webcore/treeupdater.h>
#include <sway/webcore/dom/htmldocument.h>
#include <sway/webcore/dom/htmlelement.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)

TreeUpdater::TreeUpdater() {
	// Empty
}

void TreeUpdater::visitOnEnter(TreeNodeElement * node) {
	if (!node->hasVisibled())
		return;

	TreeNodeElement * parent = (TreeNodeElement *) node->getParentNode();
	if (!parent->hasVisibled())
		return;

	EM_ASM({console.log("NODE_INDEX " + UTF8ToString($0) + " - " + UTF8ToString($1))}, node->getNodeId().c_str(), node->getNodeIndex().toString().c_str());

	if (parent) {
		RegionPtr_t region = parent->getRegionByNodeId(node->getNodeId());
		_pendingUpdateNodes.emplace_back(parent, node, region);
	}
}

void TreeUpdater::visitOnLeave(TreeNodeElement * node) {
	// Empty
}

void TreeUpdater::forceUpdate() {
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
