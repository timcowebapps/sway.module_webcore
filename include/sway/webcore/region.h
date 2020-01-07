#ifndef _SWAY_WEBCORE_REGION_H
#define _SWAY_WEBCORE_REGION_H

#include <sway/webcore/regioncreateinfo.h>
#include <sway/webcore/prereqs.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)

class TreeNodeElement;
class Region {
public:

	#pragma region Static methods

	static void registerEmscriptenClass(lpcstr_t classname);

	#pragma endregion

	#pragma region "Constructor / Destructor"

	/*!
	 * \brief
	 *    Конструктор класса.
	 *    Выполняет инициализацию нового экземпляра класса.
	 * 
	 * \param[in] options
	 *    Опции представления.
	 */
	Region(core::containers::Hierarchy * tree, const core::containers::HierarchyNodeIndex & parentNodeIndex, const RegionCreateInfo & createInfo);

	/*!
	 * \brief
	 *    Виртуальный деструктор класса.
	 */
	virtual ~Region() = default;

	#pragma endregion

	void attachView(TreeNodeElement * node);

	void detachView(TreeNodeElement * node);

	std::string getAttachedNodeId() const;

	std::string getHtmlElementId() const;

	bool hasHtmlElementReplaced() const;
	bool hasAttached() const;

private:
	core::containers::Hierarchy * _tree;
	core::containers::HierarchyNodeIndex _parentNodeIndex;
	std::string _htmlElementId;
	std::string _attachedNodeId;
	bool _htmlElementReplace;
	bool _attached;
};

NAMESPACE_END(webcore)
NAMESPACE_END(sway)

#endif // _SWAY_WEBCORE_REGION_H
