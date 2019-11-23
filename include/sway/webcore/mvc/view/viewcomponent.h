#ifndef _SWAY_WEBCORE_MVC_VIEW_VIEWCOMPONENT_H
#define _SWAY_WEBCORE_MVC_VIEW_VIEWCOMPONENT_H

#include <sway/webcore/dom/document.h>
#include <sway/webcore/dom/element.h>
#include <sway/webcore/eventtypes.h>
#include <sway/webcore/eventtarget.h>
#include <sway/webcore/eventhandler.h>
#include <sway/webcore/mvc/model/abstractmodel.h>
#include <sway/webcore/mvc/view/abstractview.h>
#include <sway/webcore/mvc/view/observer.h>
#include <sway/webcore/mvc/view/region.h>
#include <sway/webcore/mvc/view/viewcomponentoptions.h>
#include <sway/webcore/prereqs.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)
NAMESPACE_BEGIN(mvc)
NAMESPACE_BEGIN(view)

class ViewComponent : public TAbstractView<model::AbstractModel> {
public:

	#pragma region Constructor / Destructor

	/*!
	 * \brief
	 *    Конструктор класса.
	 *    Выполняет инициализацию нового экземпляра класса.
	 * 
	 * \param[in] name
	 *    Имя представления.
	 * 
	 * \param[in] options
	 *    Опции представления.
	 */
	ViewComponent(const std::string & name, const ViewComponentOptions & options);

	/*!
	 * \brief
	 *    Деструктор класса.
	 */
	virtual ~ViewComponent();

	#pragma endregion // Constructor / Destructor

	/**
	 * \brief
	 *    Обновление представения.
	 */
	virtual void update() override;

	void addChildView(ViewComponent * child);
	void removeChildView(ViewComponent * child);

	virtual void prerepaint();
	void repaint();

	/*!
	 * \brief
	 *    Устанавливает регион.
	 * 
	 * \param[in] model
	 *    Регион.
	 */
	void setRegion(RegionPtr_t region);

	/*!
	 * \brief
	 *    Возвращает регион.
	 */
	RegionPtr_t getRegion();

	emscripten::val getElement();

	void addEvent(const std::string & targetId, EventTypes_t type, emscripten::val callback);

private:
	RegionPtr_t _region; /*!< Регион. */
	bool _regionSetted;
	dom::Element _domElement;
	std::vector<EventHandler> _handlers;
};

class ViewComponentWrapper : public emscripten::wrapper<ViewComponent> {
public:
	EMSCRIPTEN_WRAPPER(ViewComponentWrapper)

	void prerepaint() {
		return call<void>("prerepaint");
	}
};

NAMESPACE_END(view)
NAMESPACE_END(mvc)
NAMESPACE_END(webcore)
NAMESPACE_END(sway)

#endif // _SWAY_WEBCORE_MVC_VIEW_VIEWCOMPONENT_H
