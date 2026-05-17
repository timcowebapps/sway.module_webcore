#ifndef SWAY_WEBCORE_NODEELEMENTUPDATER_HPP
#define SWAY_WEBCORE_NODEELEMENTUPDATER_HPP

#include <sway/webcore/nodesynchronizer.hpp>
#include <sway/webcore/prereqs.hpp>

namespace sway::webcore {

class NodeElementUpdater : public core::Traverser {
public:
  NodeElementUpdater() = default;

  virtual ~NodeElementUpdater() = default;

  MTHD_OVERRIDE(u32_t visit(core::Visitable *guest));

  void forceUpdate();

private:
  NodeSynchronizer synchronizer_;
  std::deque<PendingNode> pendingUpdateNodes_;
};

}  // namespace sway::webcore

#endif
