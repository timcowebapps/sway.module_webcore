#ifndef _SWAY_WEBCORE_PENDINGNODE_H
#define _SWAY_WEBCORE_PENDINGNODE_H

#include <sway/webcore/treenodeelementupdatekind.h>
#include <sway/webcore/treenodeelement.h>
#include <sway/webcore/region.h>
#include <sway/webcore/prereqs.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)

struct PendingNode {
	std::pair<std::string, TreeNodeElement *> element;
	TreeNodeElement * parentElement;
	RegionPtr_t region;

	PendingNode(TreeNodeElement * parent, TreeNodeElement * node, RegionPtr_t region)
		: element(std::make_pair(node->getNodeUid(), node))
		, parentElement(parent)
		, region(region) {
		// Empty
	}
};

typedef std::deque<PendingNode> PendingList;

NAMESPACE_END(webcore)
NAMESPACE_END(sway)

#endif // _SWAY_WEBCORE_PENDINGNODE_H
