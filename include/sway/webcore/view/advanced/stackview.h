#ifndef _SWAY_WEBCORE_VIEW_ADVANCED_STACKVIEW_H
#define _SWAY_WEBCORE_VIEW_ADVANCED_STACKVIEW_H

#include <sway/webcore/base/treenode.h>
#include <sway/webcore/prereqs.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)
NAMESPACE_BEGIN(view)
NAMESPACE_BEGIN(advanced)

class StackView
	: public base::TreeNode {

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
	StackView(core::containers::TreeNodePtr_t parent,
		//const core::containers::TreeNodeIndex & nodeIndex,
		const std::string & nodeId, const base::TreeNodeElementCreateInfo & createInfo);

	/*!
	 * \brief
	 *    Виртуальный деструктор класса.
	 */
	virtual ~StackView() = default;

	#pragma endregion // Constructor / Destructor

	virtual void accept(base::ITreeVisitor * visitor);

	#pragma region General methods

	void addItem(base::TreeNode * item);
	void handleItemAdded(const core::containers::TreeNodeIndex & nodeIndex);

	void removeItem(base::TreeNode * item);

	#pragma endregion // General methods

	#pragma region Getters / Setters

	u32_t getCurrentItem();

	void setCurrentItem(u32_t nodeIdex);

	#pragma endregion // Getters / Setters

private:
	u32_t _current = 0;
};

NAMESPACE_END(advanced)
NAMESPACE_END(view)
NAMESPACE_END(webcore)
NAMESPACE_END(sway)

#endif // _SWAY_WEBCORE_VIEW_ADVANCED_STACKVIEW_H
