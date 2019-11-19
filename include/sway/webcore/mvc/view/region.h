#ifndef _SWAY_WEBCORE_MVC_VIEW_REGION_H
#define _SWAY_WEBCORE_MVC_VIEW_REGION_H

#include <sway/webcore/dom/document.h>
#include <sway/webcore/dom/element.h>
#include <sway/webcore/mvc/view/regionoptions.h>
#include <sway/webcore/prereqs.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)
NAMESPACE_BEGIN(mvc)
NAMESPACE_BEGIN(view)

class View;
class Region {
public:
	static RegionPtr_t create(const RegionOptions & options);

	/*!
	 * \brief
	 *    Конструктор класса.
	 *    Выполняет инициализацию нового экземпляра класса.
	 * 
	 * \param[in] options
	 *    Опции региона.
	 */
	Region(const RegionOptions & options);

	/*!
	 * \brief
	 *    Деструктор класса.
	 */
	~Region();

	/*!
	 * \brief
	 *    Повторная инициализации региона.
	 */
	void reinitialize();

	/*!
	 * \brief
	 *    Возвращает HTML элемент.
	 */
	emscripten::val getElement() const;

	void attachView(ViewComponent * view);

	void detachView(ViewComponent * view);

private:
	dom::Element _domElement;
	bool _elementAttached;
	std::string _elementId;
	bool _replace;
};

NAMESPACE_END(view)
NAMESPACE_END(mvc)
NAMESPACE_END(webcore)
NAMESPACE_END(sway)

#endif // _SWAY_WEBCORE_MVC_VIEW_REGION_H
