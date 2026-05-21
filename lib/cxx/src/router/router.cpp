#include <sway/webcore/router/router.hpp>

namespace sway::webcore {

EMSCRIPTEN_BINDING_BEGIN(Router)
emscripten::class_<Router>("Router")
    .constructor()
    .function("addRoute", &Router::addRoute)
    .function("navigate", &Router::navigate);
EMSCRIPTEN_BINDING_END()

Router::~Router() { routes_.clear(); }

void Router::addRoute(const std::string &route, RouteCallback_t callback) {
  routes_.push_back((struct HttpRoute){.path = new Uri(route), .callback = callback});
}

void Router::navigate(const std::string &fragment) {
  emscripten::val history = emscripten::val::global("history");
  history.call<void>("replaceState", emscripten::val::object(), emscripten::val::global("document")["title"],
      emscripten::val(fragment.c_str()));

  emscripten::val location = emscripten::val::global("location");
  std::string pathname = location["pathname"].as<std::string>();

  for (auto route : routes_) {
    if (route.path->getPath() == pathname) {
      route.callback();
    }
  }
}

}  // namespace sway::webcore
