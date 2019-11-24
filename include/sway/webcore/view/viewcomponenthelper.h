#ifndef _SWAY_WEBCORE_VIEW_VIEWCOMPONENTHELPER_H
#define _SWAY_WEBCORE_VIEW_VIEWCOMPONENTHELPER_H

#include <sway/webcore/prereqs.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)
NAMESPACE_BEGIN(view)

class ViewComponentHelper {
public:
	static void registerClassOptions(lpcstr_t name);
	static void registerClass(lpcstr_t name);
};

NAMESPACE_END(view)
NAMESPACE_END(webcore)
NAMESPACE_END(sway)

#endif // _SWAY_WEBCORE_VIEW_VIEWCOMPONENTHELPER_H
