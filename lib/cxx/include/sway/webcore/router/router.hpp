#ifndef SWAY_WEBCORE_ROUTER_ROUTER_HPP
#define SWAY_WEBCORE_ROUTER_ROUTER_HPP

#include <sway/emscriptenmacros.hpp>
#include <sway/webcore/prereqs.hpp>
#include <sway/webcore/router/httproute.hpp>

namespace sway::webcore {

class Router {
  DECLARE_EMSCRIPTEN_BINDING()

public:
  Router() = default;

  ~Router();

  void addRoute(const std::string &route, RouteCallback_t callback);

  void navigate(const std::string &fragment);

private:
  std::vector<HttpRoute> routes_;
};

}  // namespace sway::webcore

#endif
