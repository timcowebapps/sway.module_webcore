#ifndef SWAY_WEBCORE_NODEELEMENTMOUNTER_HPP
#define SWAY_WEBCORE_NODEELEMENTMOUNTER_HPP

#include <sway/webcore/nodesynchronizer.hpp>
#include <sway/webcore/prereqs.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)

class NodeElementMounter : public core::utils::Traverser {
public:
  NodeElementMounter() = default;

  virtual ~NodeElementMounter() = default;

  MTHD_OVERRIDE(u32_t visit(core::utils::Visitable *guest));

  void forceUpdate();

private:
  NodeSynchronizer synchronizer_;
  std::deque<PendingNode> pendingUpdateNodes_;
};

NAMESPACE_END(webcore)
NAMESPACE_END(sway)

#endif
