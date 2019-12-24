#include <sway/webcore/dom/htmlelement.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)
NAMESPACE_BEGIN(dom)

HtmlElement::HtmlElement()
	: _val(emscripten::val::null()) {
	// Empty
}

HtmlElement::HtmlElement(const emscripten::val & value)
	: _val(value) {
	// Empty
}

HtmlElement::~HtmlElement() {
	// Empty
}

HtmlElement HtmlElement::getParentElement() const {
	return _val["parentElement"].as<emscripten::val>();
}

HtmlElement HtmlElement::appendChild(const HtmlElement & child) {
	return _val.call<emscripten::val>("appendChild", child._val);
}

HtmlElement HtmlElement::replaceChild(HtmlElement newnode, HtmlElement oldnode) {
	return _val.call<emscripten::val>("replaceChild", newnode._val, oldnode._val);
}

HtmlElement HtmlElement::removeChild(const HtmlElement & child) {
	return _val.call<emscripten::val>("removeChild", child._val);
}

void HtmlElement::setInnerHtml(const std::string & content) {
	_val.set("innerHTML", content);
}

void HtmlElement::setAttribute(const std::string & key, const std::string & value) {
	_val.call<void>("setAttribute", emscripten::val(key), emscripten::val(value));
}

void HtmlElement::addClassName(const std::string & name) {
	_val["classList"].call<void>("add", emscripten::val(name));
}

std::string HtmlElement::toString() const {
	return _val.call<std::string>("toString");
}

NAMESPACE_END(dom)
NAMESPACE_END(webcore)
NAMESPACE_END(sway)
