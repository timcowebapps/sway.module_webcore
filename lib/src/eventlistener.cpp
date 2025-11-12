#include <sway/webcore/eventlistener.hpp>

namespace sway::webcore {

EventListener::EventListener(EventCallback_t callback)
    : callback_(callback) {}

void EventListener::handleEvent(
#ifdef EMSCRIPTEN_PLATFORM
    emscripten::val value
#endif
) {
#ifdef EMSCRIPTEN_PLATFORM
  callback_(value);
#endif
}

}  // namespace sway::webcore
