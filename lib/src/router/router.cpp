#include <sway/webcore/router/router.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)
NAMESPACE_BEGIN(router)

void Router::registerEmClass() {
#ifdef _EMSCRIPTEN
  emscripten::class_<Router>("Router")
      .constructor()
      .function("addRoute", &Router::addRoute)
      .function("navigate", &Router::navigate);
#endif
}

Router::~Router() {
  routes_.clear();
}

void Router::addRoute(const std::string &route, RouteCallback_t callback) {
  routes_.push_back((struct HttpRoute){ .path = new Uri(route), .callback = callback });
}

void Router::navigate(const std::string &fragment) {
#ifdef _EMSCRIPTEN
  emscripten::val history = emscripten::val::global("history");
  history.call<void>("replaceState", emscripten::val::object(), emscripten::val::global("document")["title"],
      emscripten::val(fragment.c_str()));

  emscripten::val location = emscripten::val::global("location");
  std::string pathname = location["pathname"].as<std::string>();

  for ( auto route : routes_ ) {
    if ( route.path->getPath() == pathname ) {
      route.callback();
    }
  }
#endif
}

NAMESPACE_END(router)
NAMESPACE_END(webcore)
NAMESPACE_END(sway)
