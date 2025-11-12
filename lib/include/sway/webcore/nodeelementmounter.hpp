#ifndef SWAY_WEBCORE_NODEELEMENTMOUNTER_HPP
#define SWAY_WEBCORE_NODEELEMENTMOUNTER_HPP

#include <sway/webcore/nodesynchronizer.hpp>
#include <sway/webcore/prereqs.hpp>

namespace sway::webcore {

class NodeElementMounter : public core::Traverser {
public:
  NodeElementMounter() = default;

  virtual ~NodeElementMounter() = default;

  MTHD_OVERRIDE(u32_t visit(core::Visitable *guest));

  void forceUpdate();

private:
  NodeSynchronizer synchronizer_;
  std::deque<PendingNode> pendingUpdateNodes_;
};

}  // namespace sway::webcore

#endif
