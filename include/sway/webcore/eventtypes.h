#ifndef _SWAY_WEBCORE_EVENTTYPES_H
#define _SWAY_WEBCORE_EVENTTYPES_H

#include <sway/core.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)

enum class EventTypes_t : u32_t {
	kClick,
	kMouseOver,
	kMouseOut
};

NAMESPACE_END(webcore)
NAMESPACE_END(sway)

#include <sway/webcore/eventtypes.inl>

#endif // _SWAY_WEBCORE_EVENTTYPES_H
