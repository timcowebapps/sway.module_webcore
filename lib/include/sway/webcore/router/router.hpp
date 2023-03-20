#ifndef SWAY_WEBCORE_ROUTER_ROUTER_HPP
#define SWAY_WEBCORE_ROUTER_ROUTER_HPP

#include <sway/webcore/prereqs.hpp>
#include <sway/webcore/router/httproute.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)
NAMESPACE_BEGIN(router)

class Router {
public:
  static void registerEmClass();

  Router() = default;

  ~Router();

  void addRoute(const std::string &route, RouteCallback_t callback);

  void navigate(const std::string &fragment);

private:
  std::vector<HttpRoute> routes_;
};

NAMESPACE_END(router)
NAMESPACE_END(webcore)
NAMESPACE_END(sway)

#endif
