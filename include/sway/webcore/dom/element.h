#ifndef _SWAY_WEBCORE_DOM_ELEMENT_H
#define _SWAY_WEBCORE_DOM_ELEMENT_H

#include <sway/webcore/prereqs.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)
NAMESPACE_BEGIN(dom)

class Element {
public:
	/*!
	 * \brief
	 *    Конструктор класса.
	 *    Выполняет инициализацию нового экземпляра класса.
	 */
	Element(const emscripten::val & value);

	/*!
	 * \brief
	 *    Деструктор класса.
	 */
	~Element();

	Element getParentElement() const;

	Element appendChild(const Element & child);

	Element replaceChild(Element newnode, Element oldnode);

	Element removeChild(const Element & child);

	void setInnerHtml(const std::string & htmlString);

	void setAttribute(const std::string & key, const std::string & value);

	void addClassName(const std::string & name);

	std::string toString() const;

	operator emscripten::val() const { return _val; }

	emscripten::val _val;
};

NAMESPACE_END(dom)
NAMESPACE_END(webcore)
NAMESPACE_END(sway)

#endif // _SWAY_WEBCORE_DOM_ELEMENT_H
