#ifndef _SWAY_WEBCORE_BASE_TREENODEELEMENT_H
#define _SWAY_WEBCORE_BASE_TREENODEELEMENT_H

#include <sway/webcore/eventtypes.h>
#include <sway/webcore/eventtarget.h>
#include <sway/webcore/eventhandler.h>

#include <sway/webcore/base/treenodeelementcreateinfo.h>
#include <sway/webcore/base/regioncreateinfo.h>
#include <sway/webcore/base/region.h>
#include <sway/webcore/prereqs.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)
NAMESPACE_BEGIN(base)


typedef std::shared_ptr<RegionMixin> RegionMixinPtr_t;
typedef std::map<std::string, RegionMixinPtr_t> RegionMixinMap_t;
typedef RegionMixinMap_t::const_iterator RegionMixinIterator_t;
typedef std::vector<std::string> RegionMixinNameVec_t;

class ITreeVisitor;

class TreeNodeElement
	: public core::containers::HierarchyNode {
public:

#pragma region "Static methods"

	static void registerEmscriptenClass(lpcstr_t classname);

#pragma endregion // Static methods

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

#pragma endregion // Constructor / Destructor

#pragma region "IVisitable > HierarchyNode implementation"

	using core::containers::HierarchyNode::accept;

	virtual void accept(ITreeVisitor * visitor);

#pragma endregion // IVisitable > HierarchyNode

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
	RegionMixinPtr_t getRegion(const std::string & name) const;

	RegionMixinPtr_t getRegionByNodeId(const std::string & nodeId) const;

	RegionMixinMap_t getRegions();

	/*!
	 * \brief
	 *    Возвращает имена регионов.
	 */
	RegionMixinNameVec_t getRegionNames() const;

#pragma endregion // General methods

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

	std::string getHtmlElementClasses() const;

	void setHtmlElementClasses(const std::string & classes);

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

#pragma endregion // Getters / Setters

private:
	RegionMixinMap_t _regions; /*!< Карта регионов. */
	std::vector<EventHandler> _handlers;
	std::string _htmlElementTagname; /*!< Имя тега. */
	std::string _htmlElementClasses;
	std::string _htmlElementId; /*!< Уникальный идентификатор. */
	std::string _htmlContent;
	bool _visibled;
};

NAMESPACE_END(base)
NAMESPACE_END(webcore)
NAMESPACE_END(sway)

#endif // _SWAY_WEBCORE_BASE_TREENODEELEMENT_H
