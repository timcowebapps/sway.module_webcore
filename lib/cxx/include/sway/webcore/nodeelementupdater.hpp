#ifndef SWAY_WEBCORE_NODEELEMENTUPDATER_HPP
#define SWAY_WEBCORE_NODEELEMENTUPDATER_HPP

#include <sway/webcore/nodesynchronizer.hpp>
#include <sway/webcore/prereqs.hpp>

namespace sway::webcore {

class NodeElementUpdater : public core::Traverser {
  DECLARE_EMSCRIPTEN_BINDING()

public:
  NodeElementUpdater() = default;

  virtual ~NodeElementUpdater() = default;

  auto visit(core::Visitable *guest) -> u32_t override;

  void forceUpdate();

private:
  NodeSynchronizer synchronizer_;
  std::deque<PendingNode> pendingUpdateNodes_;
};

}  // namespace sway::webcore

#endif
