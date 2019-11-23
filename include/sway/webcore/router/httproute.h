#ifndef _SWAY_WEBCORE_ROUTER_HTTPROUTE_H
#define _SWAY_WEBCORE_ROUTER_HTTPROUTE_H

#include <sway/webcore/router/uri.h>
#include <sway/webcore/prereqs.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)
NAMESPACE_BEGIN(router)

typedef std::function<void()> RouteCallback_t;

struct HttpRoute {
	Uri * path;
	RouteCallback_t callback;
};

NAMESPACE_END(router)
NAMESPACE_END(webcore)
NAMESPACE_END(sway)

#endif // _SWAY_WEBCORE_ROUTER_HTTPROUTE_H
