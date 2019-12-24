#ifndef _SWAY_WEBCORE_BASE_PENDINGNODE_H
#define _SWAY_WEBCORE_BASE_PENDINGNODE_H

#include <sway/webcore/dom/htmldocument.h>
#include <sway/webcore/base/treenodeelementupdatekind.h>
#include <sway/webcore/base/treenode.h>
#include <sway/webcore/base/treenodeelement.h>
#include <sway/webcore/base/region.h>
#include <sway/webcore/prereqs.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)
NAMESPACE_BEGIN(base)

struct PendingNode {
	std::pair<std::string, TreeNodeElement *> element;
	TreeNodeElement * parentElement;
	RegionMixinPtr_t region;

	PendingNode(TreeNodeElement * parent, TreeNode * node, RegionMixinPtr_t region)
		: element(std::make_pair(node->getNodeId(), node->getOwned()))
		, parentElement(parent)
		, region(region) {
		// Empty
	}
};

typedef std::deque<PendingNode> PendingList;

NAMESPACE_END(base)
NAMESPACE_END(webcore)
NAMESPACE_END(sway)

#endif // _SWAY_WEBCORE_BASE_PENDINGNODE_H
