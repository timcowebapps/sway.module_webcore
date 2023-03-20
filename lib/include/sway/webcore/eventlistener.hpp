#ifndef SWAY_WEBCORE_EVENTLISTENER_HPP
#define SWAY_WEBCORE_EVENTLISTENER_HPP

#include <sway/webcore/prereqs.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)

class EventListener {
public:
  EventListener(EventCallback_t callback);

  void handleEvent(
#ifdef EMSCRIPTEN_PLATFORM
      emscripten::val value
#endif
  );

public:
  EventCallback_t callback_;
};

NAMESPACE_END(webcore)
NAMESPACE_END(sway)

#endif
