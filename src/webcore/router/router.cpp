#include <sway/webcore/router/router.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)
NAMESPACE_BEGIN(router)

void Router::registerEmscriptenClass(lpcstr_t name) {
	emscripten::class_<Router>(name)
		.constructor()
		.function("addRoute", &Router::addRoute)
		.function("navigate", &Router::navigate);
}

Router::Router() {
	// Empty
}

Router::~Router() {
	_routes.clear();
}

void Router::addRoute(const std::string & route, emscripten::val callback) {
	_routes.push_back((struct HttpRoute) {
		.path = new Uri(route),
		.callback = callback
	});
}

void Router::navigate(const std::string & fragment) {
	emscripten::val history = emscripten::val::global("history");
	history.call<void>("replaceState",
		emscripten::val::object(),
		emscripten::val::global("document")["title"],
		emscripten::val(fragment.c_str()));

	emscripten::val location = emscripten::val::global("location");
	std::string pathname = location["pathname"].as<std::string>();

	for (auto route : _routes) {
		if (route.path->getPath() == pathname)
			route.callback();
	}
}

NAMESPACE_END(router)
NAMESPACE_END(webcore)
NAMESPACE_END(sway)
