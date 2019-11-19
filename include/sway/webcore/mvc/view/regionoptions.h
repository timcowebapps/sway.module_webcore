#ifndef _SWAY_WEBCORE_MVC_VIEW_REGIONOPTIONS_H
#define _SWAY_WEBCORE_MVC_VIEW_REGIONOPTIONS_H

#include <sway/webcore/prereqs.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)
NAMESPACE_BEGIN(mvc)
NAMESPACE_BEGIN(view)

struct RegionOptions {
	std::string elementId;
	bool replace;
};

NAMESPACE_END(view)
NAMESPACE_END(mvc)
NAMESPACE_END(webcore)
NAMESPACE_END(sway)

#endif // _SWAY_WEBCORE_MVC_VIEW_REGIONOPTIONS_H
