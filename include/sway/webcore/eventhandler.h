#ifndef _SWAY_WEBCORE_EVENTHANDLER_H
#define _SWAY_WEBCORE_EVENTHANDLER_H

#include <sway/webcore/eventtypes.h>
#include <sway/webcore/eventtarget.h>
#include <sway/webcore/prereqs.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)

struct EventHandler {
	std::string targetId;
	webcore::EventTarget * target;
	webcore::EventTypes_t type;
};

NAMESPACE_END(webcore)
NAMESPACE_END(sway)

#endif // _SWAY_WEBCORE_EVENTHANDLER_H
