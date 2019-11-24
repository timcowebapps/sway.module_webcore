#ifndef _SWAY_WEBCORE_VIEW_VIEWCOMPONENTOPTIONS_H
#define _SWAY_WEBCORE_VIEW_VIEWCOMPONENTOPTIONS_H

#include <sway/webcore/prereqs.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)
NAMESPACE_BEGIN(view)

struct ViewComponentOptions {
	std::string id;
	std::string tagname;
	std::string classname;
	std::string htmlString;

	ViewComponentOptions()
		: tagname("div") {
		// Empty
	}
};

NAMESPACE_END(view)
NAMESPACE_END(webcore)
NAMESPACE_END(sway)

#endif // _SWAY_WEBCORE_VIEW_VIEWCOMPONENTOPTIONS_H
