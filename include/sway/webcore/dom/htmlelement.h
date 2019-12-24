#ifndef _SWAY_WEBCORE_DOM_HTMLELEMENT_H
#define _SWAY_WEBCORE_DOM_HTMLELEMENT_H

#include <sway/webcore/prereqs.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)
NAMESPACE_BEGIN(dom)

class HtmlElement {
public:
	/*!
	 * \brief
	 *    Конструктор класса.
	 *    Выполняет инициализацию нового экземпляра класса.
	 */
	HtmlElement();

	/*!
	 * \brief
	 *    Конструктор класса.
	 *    Выполняет инициализацию нового экземпляра класса.
	 */
	HtmlElement(const emscripten::val & value);

	/*!
	 * \brief
	 *    Деструктор класса.
	 */
	~HtmlElement();

	HtmlElement getParentElement() const;

	HtmlElement appendChild(const HtmlElement & child);

	HtmlElement replaceChild(HtmlElement newnode, HtmlElement oldnode);

	HtmlElement removeChild(const HtmlElement & child);

	void setInnerHtml(const std::string & content);

	void setAttribute(const std::string & key, const std::string & value);

	void addClassName(const std::string & name);

	std::string toString() const;

	operator emscripten::val() const { return _val; }

	emscripten::val _val;
};

NAMESPACE_END(dom)
NAMESPACE_END(webcore)
NAMESPACE_END(sway)

#endif // _SWAY_WEBCORE_DOM_HTMLELEMENT_H
