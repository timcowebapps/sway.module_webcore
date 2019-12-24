#ifndef _SWAY_WEBCORE_ROUTER_ROUTER_H
#define _SWAY_WEBCORE_ROUTER_ROUTER_H

#include <sway/webcore/router/httproute.h>
#include <sway/webcore/prereqs.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)
NAMESPACE_BEGIN(router)

class Router {
public:

	#pragma region Static methods

	static void registerEmscriptenClass(lpcstr_t name);

	#pragma endregion // Static methods

	#pragma region Constructor / Destructor

	/*!
	 * \brief
	 *    Конструктор класса.
	 *    Выполняет инициализацию нового экземпляра класса.
	 */
	Router();

	/*!
	 * \brief
	 *    Деструктор класса.
	 */
	~Router();

	#pragma endregion // Constructor / Destructor

	#pragma region Public Methods

	void addRoute(const std::string & route, emscripten::val callback);

	void navigate(const std::string & fragment);

	#pragma endregion // Public Methods

private:
	std::vector<HttpRoute> _routes;
};

NAMESPACE_END(router)
NAMESPACE_END(webcore)
NAMESPACE_END(sway)

#endif // _SWAY_WEBCORE_ROUTER_ROUTER_H
