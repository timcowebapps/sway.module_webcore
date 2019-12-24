#ifndef _SWAY_WEBCORE_DOM_HTMLBUILDER_H
#define _SWAY_WEBCORE_DOM_HTMLBUILDER_H

#include <sway/webcore/dom/htmlelement.h>
#include <sway/webcore/base/treenodeelement.h>
#include <sway/webcore/prereqs.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)
NAMESPACE_BEGIN(dom)

class HtmlBuilder {
public:

	#pragma region Constructor / Destructor

	/*!
	 * \brief
	 *    Конструктор класса.
	 *    Выполняет инициализацию нового экземпляра класса.
	 */
	HtmlBuilder();

	/*!
	 * \brief
	 *    Виртуальный деструктор класса.
	 */
	virtual ~HtmlBuilder() = default;

	#pragma endregion // Constructor / Destructor

	HtmlElement createHtmlElement(base::TreeNodeElement * element);

private:
};

NAMESPACE_END(dom)
NAMESPACE_END(webcore)
NAMESPACE_END(sway)

#endif // _SWAY_WEBCORE_DOM_HTMLBUILDER_H
