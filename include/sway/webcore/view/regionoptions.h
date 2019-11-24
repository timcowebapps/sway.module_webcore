#ifndef _SWAY_WEBCORE_VIEW_REGIONOPTIONS_H
#define _SWAY_WEBCORE_VIEW_REGIONOPTIONS_H

#include <sway/webcore/prereqs.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)
NAMESPACE_BEGIN(view)

struct RegionOptions {
	std::string elementId;
	bool replace;
};

NAMESPACE_END(view)
NAMESPACE_END(webcore)
NAMESPACE_END(sway)

#endif // _SWAY_WEBCORE_VIEW_REGIONOPTIONS_H
