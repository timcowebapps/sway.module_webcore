#ifndef SWAY_WEBCORE_NODESYNCHRONIZER_HPP
#define SWAY_WEBCORE_NODESYNCHRONIZER_HPP

#include <sway/webcore/dom/htmlbuilder.hpp>
#include <sway/webcore/pendingnode.hpp>
#include <sway/webcore/prereqs.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)

class NodeSynchronizer {
public:
  NodeSynchronizer();
  virtual ~NodeSynchronizer();

  void insertNode(PendingNode node);

  void removeNode(PendingNode node);

  void applyPendingUpdate(PendingNode node);

private:
  dom::HtmlBuilder *htmlBuilder_;
};

NAMESPACE_END(webcore)
NAMESPACE_END(sway)

#endif
