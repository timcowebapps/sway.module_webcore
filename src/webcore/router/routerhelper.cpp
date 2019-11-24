#include <sway/webcore/router/routerhelper.h>
#include <sway/webcore/router/router.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)
NAMESPACE_BEGIN(router)

void RouterHelper::registerClass(lpcstr_t name) {
	emscripten::class_<Router>(name)
		.constructor()
		.function("addRoute", &Router::addRoute)
		.function("navigate", &Router::navigate);
}

NAMESPACE_END(router)
NAMESPACE_END(webcore)
NAMESPACE_END(sway)
