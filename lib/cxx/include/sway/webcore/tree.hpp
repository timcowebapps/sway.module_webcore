#ifndef SWAY_WEBCORE_TREE_HPP
#define SWAY_WEBCORE_TREE_HPP

#include <sway/webcore/css/selector.hpp>
#include <sway/webcore/eventhandler.hpp>
#include <sway/webcore/eventtarget.hpp>
#include <sway/webcore/prereqs.hpp>
#include <sway/webcore/region.hpp>
#include <sway/webcore/regioncreateinfo.hpp>
#include <sway/webcore/treenodeelementdescriptor.hpp>

namespace sway::webcore {

class TreeListener {
  DECLARE_EMSCRIPTEN_BINDING()

  virtual void onNodeAdded(const core::NodeIndex &nodeIdx);

  virtual void onNodeRemoved(core::Node parent, core::Node child);

  virtual void onNodeUpdated(const core::NodeIndex &nodeIdx);
};

class Tree : public core::Hierarchy {
  DECLARE_EMSCRIPTEN_BINDING()

public:
  Tree();

  virtual ~Tree() = default;
};

}  // namespace sway::webcore

#endif
