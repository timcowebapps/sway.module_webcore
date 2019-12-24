#ifndef _SWAY_WEBCORE_BASE_TreeNode_H
#define _SWAY_WEBCORE_BASE_TreeNode_H

#include <sway/webcore/base/treenodeelementcreateinfo.h>
#include <sway/webcore/base/treenodeelement.h>
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

class TreeNode
	: public core::containers::TreeNodeBase {

public:

	#pragma region Static methods

	static void registerEmscriptenClass(lpcstr_t classname);

	#pragma endregion // Static methods

	#pragma region Constructor / Destructor

	/*!
	 * \brief
	 *    Конструктор класса.
	 *    Выполняет инициализацию нового экземпляра класса.
	 */
	TreeNode(core::containers::TreeNodePtr_t parent, const core::containers::TreeNodeIndex & nodeIndex,
		const std::string & nodeId, const TreeNodeElementCreateInfo & createInfo);

	/*!
	 * \brief
	 *    Виртуальный деструктор класса.
	 */
	virtual ~TreeNode();

	#pragma endregion // Constructor / Destructor

	#pragma region Pure virtual methods

	//IVisitable
	virtual void accept(ITreeVisitor * visitor) = 0;

	#pragma endregion // Pure virtual methods

	#pragma region General methods

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

	#pragma region Getters / Setters

	TreeNodeElement * getOwned();

	#pragma endregion // Getters / Setters

private:
	RegionMixinMap_t _regions; /*!< Карта регионов. */
	TreeNodeElement * _element;
};

NAMESPACE_END(base)
NAMESPACE_END(webcore)
NAMESPACE_END(sway)

#endif // _SWAY_WEBCORE_BASE_TreeNode_H
