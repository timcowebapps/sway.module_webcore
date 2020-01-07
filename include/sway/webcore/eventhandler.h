#ifndef _SWAY_WEBCORE_EVENTHANDLER_H
#define _SWAY_WEBCORE_EVENTHANDLER_H

#include <sway/webcore/eventtarget.h>
#include <sway/webcore/prereqs.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)

struct EventHandler {
	std::string type; /* Тип события. */
	std::string targetId;
	webcore::EventTarget * target;
};

NAMESPACE_END(webcore)
NAMESPACE_END(sway)

#endif // _SWAY_WEBCORE_EVENTHANDLER_H
