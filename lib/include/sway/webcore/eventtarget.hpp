#ifndef SWAY_WEBCORE_EVENTTARGET_HPP
#define SWAY_WEBCORE_EVENTTARGET_HPP

#include <sway/webcore/eventlistener.hpp>
#include <sway/webcore/prereqs.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)

class EventTarget {
public:
  EventTarget(EventCallback_t callback);

  ~EventTarget();

  void addEventListener(const std::string &targetId, const std::string &type);

  void setCallback(EventCallback_t callback);

private:
  TargetEventVec_t events_;
#ifdef EMSCRIPTEN_PLATFORM
  emscripten::val listener_;
#endif
};

NAMESPACE_END(webcore)
NAMESPACE_END(sway)

#endif
