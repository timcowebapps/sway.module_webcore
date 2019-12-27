#ifndef _SWAY_WEBCORE_BASE_REGION_H
#define _SWAY_WEBCORE_BASE_REGION_H

#include <sway/webcore/base/regioncreateinfo.h>
#include <sway/webcore/prereqs.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)
NAMESPACE_BEGIN(base)

class TreeNodeElement;
class RegionMixin {
public:

	#pragma region Static methods

	static void registerEmscriptenClass(lpcstr_t classname);

	#pragma endregion // Static methods

	#pragma region Constructor / Destructor

	/*!
	 * \brief
	 *    Конструктор класса.
	 *    Выполняет инициализацию нового экземпляра класса.
	 * 
	 * \param[in] options
	 *    Опции представления.
	 */
	RegionMixin(core::containers::Tree * tree, const core::containers::TreeNodeIndex & parentNodeIndex, const RegionCreateInfo & createInfo);

	/*!
	 * \brief
	 *    Виртуальный деструктор класса.
	 */
	virtual ~RegionMixin() = default;

	#pragma endregion // Constructor / Destructor

	void attachView(TreeNodeElement * node);

	void detachView(TreeNodeElement * node);

	std::string getAttachedNodeId() const;

	std::string getHtmlElementId() const;

	bool hasHtmlElementReplaced() const;
	bool hasAttached() const;

private:
	core::containers::Tree * _tree;
	core::containers::TreeNodeIndex _parentNodeIndex;
	std::string _htmlElementId;
	std::string _attachedNodeId;
	bool _htmlElementReplace;
	bool _attached;
};

NAMESPACE_END(base)
NAMESPACE_END(webcore)
NAMESPACE_END(sway)

#endif // _SWAY_WEBCORE_BASE_REGION_H
