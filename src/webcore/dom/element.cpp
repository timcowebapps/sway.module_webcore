#include <sway/webcore/dom/element.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)
NAMESPACE_BEGIN(dom)

Element::Element(const emscripten::val & value)
	: _val(value) {
	// Empty
}

Element::~Element() {
	// Empty
}

Element Element::getParentElement() const {
	return _val["parentElement"].as<emscripten::val>();
}

Element Element::appendChild(const Element & child) {
	return _val.call<emscripten::val>("appendChild", child._val);
}

Element Element::replaceChild(Element newnode, Element oldnode) {
	return _val.call<emscripten::val>("replaceChild", newnode._val, oldnode._val);
}

Element Element::removeChild(const Element & child) {
	return _val.call<emscripten::val>("removeChild", child._val);
}

void Element::setInnerHtml(const std::string & htmlString) {
	_val.set("innerHTML", htmlString);
}

void Element::setAttribute(const std::string & key, const std::string & value) {
	_val.call<void>("setAttribute", emscripten::val(key), emscripten::val(value));
}

void Element::addClassName(const std::string & name) {
	_val["classList"].call<void>("add", emscripten::val(name));
}

std::string Element::toString() const {
	return _val.call<std::string>("toString");
}

NAMESPACE_END(dom)
NAMESPACE_END(webcore)
NAMESPACE_END(sway)
