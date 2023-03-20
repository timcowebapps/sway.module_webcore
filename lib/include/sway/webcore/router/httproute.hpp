#ifndef SWAY_WEBCORE_ROUTER_HTTPROUTE_HPP
#define SWAY_WEBCORE_ROUTER_HTTPROUTE_HPP

#include <sway/webcore/prereqs.hpp>
#include <sway/webcore/router/uri.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)
NAMESPACE_BEGIN(router)

#ifdef EMSCRIPTEN_PLATFORM
using RouteCallback_t = emscripten::val;
#else
using RouteCallback_t = std::function<void()>;
#endif

struct HttpRoute {
  Uri *path;
  RouteCallback_t callback;
};

NAMESPACE_END(router)
NAMESPACE_END(webcore)
NAMESPACE_END(sway)

#endif
