#ifndef SWAY_WEBCORE_PENDINGNODE_HPP
#define SWAY_WEBCORE_PENDINGNODE_HPP

#include <sway/webcore/prereqs.hpp>
#include <sway/webcore/region.hpp>
#include <sway/webcore/treenodeelement.hpp>
#include <sway/webcore/treenodeelementupdatekind.hpp>

namespace sway::webcore {

struct PendingNode {
  std::pair<std::string, TreeNodeElement *> element;
  TreeNodeElement *parentElement;
  std::shared_ptr<Region> region;

  PendingNode(TreeNodeElement *parent, TreeNodeElement *node, std::shared_ptr<Region> region)
      : element(std::make_pair(Representation<core::NodeIndex>::get(node->getNodeIndex()).c_str(), node))
      , parentElement(parent)
      , region(region) {}
};

}  // namespace sway::webcore

#endif
