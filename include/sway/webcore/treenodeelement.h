#ifndef _SWAY_WEBCORE_TREENODEELEMENT_H
#define _SWAY_WEBCORE_TREENODEELEMENT_H

#include <sway/webcore/css/selector.h>
#include <sway/webcore/eventtarget.h>
#include <sway/webcore/eventhandler.h>
#include <sway/webcore/treenodeelementdescriptor.h>
#include <sway/webcore/regioncreateinfo.h>
#include <sway/webcore/region.h>
#include <sway/webcore/prereqs.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)

class TreeNodeElement
	: public core::containers::HierarchyNode {
public:

#pragma region "Static methods"

	static void registerEmscriptenClass(lpcstr_t classname);

#pragma endregion

#pragma region "Constructor / Destructor"

	/*!
	 * \brief
	 *    Конструктор класса.
	 *    Выполняет инициализацию нового экземпляра класса.
	 */
	TreeNodeElement(core::containers::HierarchyNode * parent,
		const core::containers::HierarchyNodeIdx & nodeIdx, const TreeNodeElementDescriptor & createInfo);

	/*!
	 * \brief
	 *    Виртуальный деструктор класса.
	 */
	virtual ~TreeNodeElement() = default;

#pragma endregion

#pragma region "General methods"

	/*!
	 * \brief
	 *    Добавляет новый регион.
	 * 
	 * \param[in] name
	 *    Имя регион.
	 * 
	 * \param[in] createInfo
	 *    Опции региона.
	 */
	void addRegion(const std::string & name, const RegionCreateInfo & createInfo);

	/*!
	 * \brief
	 *    Возвращает регион.
	 * 
	 * \param[in] name
	 *    Имя регион.
	 */
	RegionPtr_t getRegion(const std::string & name) const;

	RegionPtr_t getRegionByNodeId(const std::string & nodeId) const;

	RegionMap_t getRegions();

#pragma endregion

#pragma region "Events"

	void addEvent(const std::string & targetId, const std::string & type, emscripten::val callback);

	void bindEvents();

#pragma endregion

#pragma region "Getters / Setters"

	/*!
	 * \brief
	 *    Возвращает имя тега.
	 */
	std::string getHtmlElementTagname() const;

	/*!
	 * \brief
	 *    Устанавливает имя тега.
	 * 
	 * \param[in] tagname
	 *    Имя тега.
	 */
	void setHtmlElementTagname(const std::string & tagname);

	std::vector<std::string> getHtmlElementClasses() const;

	void setHtmlElementClasses(const std::vector<std::string> & classes);

	/*!
	 * \brief
	 *    Возвращает уникальный идентификатор.
	 */
	std::string getHtmlElementId() const;

	/*!
	 * \brief
	 *    Устанавливает уникальный идентификатор.
	 * 
	 * \param[in] id
	 *    Уникальный идентификатор.
	 */
	void setHtmlElementId(const std::string & id);

	std::string getHtmlContent() const;

	void setHtmlContent(const std::string & content);

#pragma endregion

private:
	RegionMap_t _regions; /*!< Карта регионов. */
	std::vector<EventHandler> _handlers;
	std::string _htmlElementTagname; /*!< Имя тега. */
	std::vector<std::string> _htmlElementClasses;
	std::string _htmlElementId; /*!< Уникальный идентификатор. */
	std::string _htmlContent;
};

NAMESPACE_END(webcore)
NAMESPACE_END(sway)

#endif // _SWAY_WEBCORE_TREENODEELEMENT_H
