#ifndef _SWAY_WEBCORE_VIEW_ADVANCED_STACKVIEW_H
#define _SWAY_WEBCORE_VIEW_ADVANCED_STACKVIEW_H

#include <sway/webcore/base/treenodeelement.h>
#include <sway/webcore/prereqs.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)
NAMESPACE_BEGIN(view)
NAMESPACE_BEGIN(advanced)

class LayoutElement
	: public base::TreeNodeElement {

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
	LayoutElement(const base::TreeNodeElementCreateInfo & createInfo);

	/*!
	 * \brief
	 *    Виртуальный деструктор класса.
	 */
	virtual ~LayoutElement() = default;

	#pragma endregion // Constructor / Destructor

private:
};

NAMESPACE_END(advanced)
NAMESPACE_END(view)
NAMESPACE_END(webcore)
NAMESPACE_END(sway)

#endif // _SWAY_WEBCORE_VIEW_ADVANCED_STACKVIEW_H
