#ifndef SWAY_WEBCORE_TREE_HPP
#define SWAY_WEBCORE_TREE_HPP

#include <sway/webcore/css/selector.hpp>
#include <sway/webcore/eventhandler.hpp>
#include <sway/webcore/eventtarget.hpp>
#include <sway/webcore/prereqs.hpp>
#include <sway/webcore/region.hpp>
#include <sway/webcore/regioncreateinfo.hpp>
#include <sway/webcore/treenodeelementdescriptor.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)

class TreeListener {
  virtual void onNodeAdded(const core::container::NodeIdx &nodeIdx);

  virtual void onNodeRemoved(core::container::Node parent, core::container::Node child);

  virtual void onNodeUpdated(const core::container::NodeIdx &nodeIdx);
};

class Tree : public core::container::Hierarchy {
public:
  Tree();
  virtual ~Tree() = default;
};

NAMESPACE_END(webcore)
NAMESPACE_END(sway)

#endif
