#include <sway/webcore/base/treeupdater.h>
#include <sway/webcore/base/treenode.h>
#include <sway/webcore/dom/htmldocument.h>
#include <sway/webcore/dom/htmlelement.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)
NAMESPACE_BEGIN(base)

TreeUpdater::TreeUpdater() {
	// Empty
}

TreeUpdater::~TreeUpdater() {
	// Empty
}

void TreeUpdater::visit(TreeNode * node) {
	if (!node->getOwned()->hasVisibled())
		return;

	TreeNode * parent = (TreeNode *) node->getParentNode();
	if (!parent->getOwned()->hasVisibled())
		return;

	EM_ASM({console.log("NODE_INDEX " + UTF8ToString($0) + " - " + UTF8ToString($1))}, node->getNodeId().c_str(), node->getNodeIndex().toString().c_str());

	if (parent) {
		RegionMixinPtr_t region = parent->getRegionByNodeId(node->getNodeId());
		_pendingUpdateNodes.emplace_back(parent->getOwned(), node, region);
	}
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

NAMESPACE_END(base)
NAMESPACE_END(webcore)
NAMESPACE_END(sway)
