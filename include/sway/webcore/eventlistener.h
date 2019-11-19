#ifndef _SWAY_WEBCORE_EVENTLISTENER_H
#define _SWAY_WEBCORE_EVENTLISTENER_H

#include <sway/webcore/prereqs.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)

class EventListener {
public:
	EventListener(EventCallback_t callback);

	void handleEvent(emscripten::val value);

public:
	EventCallback_t _callback;
};

NAMESPACE_END(webcore)
NAMESPACE_END(sway)

#endif // _SWAY_WEBCORE_EVENTLISTENER_H
