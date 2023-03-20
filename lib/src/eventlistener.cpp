#include <sway/webcore/eventlistener.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)

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

NAMESPACE_END(webcore)
NAMESPACE_END(sway)
