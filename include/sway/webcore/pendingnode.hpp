#ifndef SWAY_WEBCORE_PENDINGNODE_HPP
#define SWAY_WEBCORE_PENDINGNODE_HPP

#include <sway/webcore/prereqs.hpp>
#include <sway/webcore/region.hpp>
#include <sway/webcore/treenodeelement.hpp>
#include <sway/webcore/treenodeelementupdatekind.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)

struct PendingNode {
  std::pair<std::string, TreeNodeElement *> element;
  TreeNodeElement *parentElement;
  std::shared_ptr<Region> region;

  // PendingNode(TreeNodeElement *parent, TreeNodeElement *node, std::shared_ptr<Region> region)
  //     : element(std::make_pair("node->getNodeUid()", node))
  //     , parentElement(parent)
  //     , region(region) {}
};

NAMESPACE_END(webcore)
NAMESPACE_END(sway)

#endif
