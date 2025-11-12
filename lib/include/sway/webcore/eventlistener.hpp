#ifndef SWAY_WEBCORE_EVENTLISTENER_HPP
#define SWAY_WEBCORE_EVENTLISTENER_HPP

#include <sway/webcore/prereqs.hpp>

namespace sway::webcore {

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

}  // namespace sway::webcore

#endif
