#ifndef _SWAY_WEBCORE_VIEW_VIEWCOMPONENT_H
#define _SWAY_WEBCORE_VIEW_VIEWCOMPONENT_H

#include <sway/webcore/dom/document.h>
#include <sway/webcore/dom/element.h>
#include <sway/webcore/eventtypes.h>
#include <sway/webcore/eventtarget.h>
#include <sway/webcore/eventhandler.h>
#include <sway/webcore/model/abstractmodel.h>
#include <sway/webcore/view/abstractview.h>
#include <sway/webcore/view/observer.h>
#include <sway/webcore/view/region.h>
#include <sway/webcore/view/viewcomponentoptions.h>
#include <sway/webcore/prereqs.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)
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

	void buildTemplate(const std::string & html);

	/*!
	 * \brief
	 *    Добавляет новый регион.
	 * 
	 * \param[in] name
	 *    Имя регион.
	 * 
	 * \param[in] options
	 *    Опции региона.
	 */
	void addRegion(const std::string & name, const RegionOptions & options);
	
	/*!
	 * \brief
	 *    Возвращает регион.
	 * 
	 * \param[in] name
	 *    Имя регион.
	 */
	RegionPtr_t getRegion(const std::string & name) const;

	/*!
	 * \brief
	 *    Возвращает имена регионов.
	 */
	RegionNameVec_t getRegionNames() const;

	void addEvent(const std::string & targetId, EventTypes_t type, emscripten::val callback);

	void addChildView(ViewComponent * child);
	void removeChildView(ViewComponent * child);

	/**
	 * \brief
	 *    Обновление представения.
	 */
	virtual void update() override;

	virtual void prerepaint();
	void repaint();

	emscripten::val getElement();

private:
	RegionMap_t _regions; /*!< Карта регионов. */
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
NAMESPACE_END(webcore)
NAMESPACE_END(sway)

#endif // _SWAY_WEBCORE_VIEW_VIEWCOMPONENT_H
