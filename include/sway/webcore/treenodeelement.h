#ifndef _SWAY_WEBCORE_TREENODEELEMENT_H
#define _SWAY_WEBCORE_TREENODEELEMENT_H

#include <sway/webcore/css/selector.h>
#include <sway/webcore/eventtarget.h>
#include <sway/webcore/eventhandler.h>
#include <sway/webcore/treenodeelementcreateinfo.h>
#include <sway/webcore/regioncreateinfo.h>
#include <sway/webcore/region.h>
#include <sway/webcore/prereqs.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)

typedef std::shared_ptr<Region> RegionPtr_t;
typedef std::map<std::string, RegionPtr_t> RegionMap_t;
typedef RegionMap_t::const_iterator RegionMapIterator_t;

class ITreeVisitor;

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
	TreeNodeElement(core::containers::HierarchyNodePtr_t parent, const core::containers::HierarchyNodeIndex & nodeIndex,
		const std::string & nodeId, const TreeNodeElementCreateInfo & createInfo);

	/*!
	 * \brief
	 *    Виртуальный деструктор класса.
	 */
	virtual ~TreeNodeElement() = default;

#pragma endregion

#pragma region "IVisitable > HierarchyNode implementation"

	using core::containers::HierarchyNode::accept;

	virtual void accept(ITreeVisitor * visitor);

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

	void addEvent(const std::string & targetId, const std::string & type, emscripten::val callback);

	void bindEvents();

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

	bool hasVisibled() const;

	void setVisible(bool value);

#pragma endregion

private:
	RegionMap_t _regions; /*!< Карта регионов. */
	std::vector<EventHandler> _handlers;
	std::string _htmlElementTagname; /*!< Имя тега. */
	std::vector<std::string> _htmlElementClasses;
	std::string _htmlElementId; /*!< Уникальный идентификатор. */
	std::string _htmlContent;
	bool _visibled;
};

NAMESPACE_END(webcore)
NAMESPACE_END(sway)

#endif // _SWAY_WEBCORE_TREENODEELEMENT_H
