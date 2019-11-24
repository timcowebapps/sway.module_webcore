#ifndef _SWAY_WEBCORE_ROUTER_ROUTERHELPER_H
#define _SWAY_WEBCORE_ROUTER_ROUTERHELPER_H

#include <sway/webcore/prereqs.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)
NAMESPACE_BEGIN(router)

class RouterHelper {
public:
	static void registerClass(lpcstr_t name);
};

NAMESPACE_END(router)
NAMESPACE_END(webcore)
NAMESPACE_END(sway)

#endif // _SWAY_WEBCORE_ROUTER_ROUTERHELPER_H
