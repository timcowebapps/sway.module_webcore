#ifndef _SWAY_WEBCORE_APPLICATION_H
#define _SWAY_WEBCORE_APPLICATION_H

#include <sway/webcore/dom/document.h>
#include <sway/webcore/dom/element.h>
#include <sway/webcore/mvc/view/viewcomponent.h>
#include <sway/webcore/prereqs.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)

class Application {
public:

	#pragma region Constructor / Destructor

	/*!
	 * \brief
	 *    Конструктор класса.
	 *    Выполняет инициализацию нового экземпляра класса.
	 */
	Application(const std::string & elementId, mvc::view::ViewComponent * view);

	/*!
	 * \brief
	 *    Деструктор класса.
	 */
	~Application();

	#pragma endregion // Constructor / Destructor

	void start();

private:
	mvc::view::ViewComponent * _view; /*!< Представление. */
};

NAMESPACE_END(webcore)
NAMESPACE_END(sway)

#endif // _SWAY_WEBCORE_APPLICATION_H
