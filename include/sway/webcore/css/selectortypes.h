#ifndef _SWAY_WEBCORE_CSS_SELECTORTYPES_H
#define _SWAY_WEBCORE_CSS_SELECTORTYPES_H

#include <sway/webcore/prereqs.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)
NAMESPACE_BEGIN(css)

enum class SelectorTypes_t : u32_t {
	kId,
	kCn
};

NAMESPACE_END(css)
NAMESPACE_END(webcore)
NAMESPACE_END(sway)

#endif // _SWAY_WEBCORE_CSS_SELECTORTYPES_H
