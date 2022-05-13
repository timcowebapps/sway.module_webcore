#include <sway/webcore/eventlistener.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)

EventListener::EventListener(EventCallback_t callback)
    : callback_(callback) {
}

void EventListener::handleEvent(
#ifdef _EMSCRIPTEN
    emscripten::val value
#endif
) {
#ifdef _EMSCRIPTEN
  callback_(value);
#endif
}

NAMESPACE_END(webcore)
NAMESPACE_END(sway)
