#include <sway/webcore/eventlistener.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)

EventListener::EventListener(EventCallback_t callback)
	: _callback(callback) {
	// Empty
}

void EventListener::handleEvent(emscripten::val value) {
	_callback(value);
}

NAMESPACE_END(webcore)
NAMESPACE_END(sway)
