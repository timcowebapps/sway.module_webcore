#include <sway/webcore/dom/htmlelement.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)
NAMESPACE_BEGIN(dom)

HtmlElement::HtmlElement()
#ifdef _EMSCRIPTEN
    : val_(emscripten::val::null())
#endif
{
}

#ifdef _EMSCRIPTEN
HtmlElement::HtmlElement(const emscripten::val &value)
    : val_(value) {
}
#endif

HtmlElement HtmlElement::getParentElement() const {
#ifdef _EMSCRIPTEN
  return val_["parentElement"].as<emscripten::val>();
#else
  return HtmlElement();
#endif
}

HtmlElement HtmlElement::appendChild(const HtmlElement &child) {
#ifdef _EMSCRIPTEN
  return val_.call<emscripten::val>("appendChild", child.val_);
#else
  return HtmlElement();
#endif
}

HtmlElement HtmlElement::replaceChild(HtmlElement newnode, HtmlElement oldnode) {
#ifdef _EMSCRIPTEN
  return val_.call<emscripten::val>("replaceChild", newnode.val_, oldnode.val_);
#else
  return HtmlElement();
#endif
}

HtmlElement HtmlElement::removeChild(const HtmlElement &child) {
#ifdef _EMSCRIPTEN
  return val_.call<emscripten::val>("removeChild", child.val_);
#else
  return HtmlElement();
#endif
}

void HtmlElement::setInnerContent(const std::string &content, bool dirty) {
#ifdef _EMSCRIPTEN
  val_.set(core::misc::format("inner%s", dirty ? "HTML" : "Text"), content);
#endif
}

void HtmlElement::setAttribute(const std::string &key, const std::string &value) {
#ifdef _EMSCRIPTEN
  val_.call<void>("setAttribute", emscripten::val(key), emscripten::val(value));
#endif
}

void HtmlElement::addClassName(const std::string &className) {
  if ( className.empty() ) {
    return;
  }

#ifdef _EMSCRIPTEN
  val_["classList"].call<void>("add", emscripten::val(className));
#endif
}

std::string HtmlElement::toString() const {
#ifdef _EMSCRIPTEN
  return val_.call<std::string>("toString");
#else
  return "";
#endif
}

NAMESPACE_END(dom)
NAMESPACE_END(webcore)
NAMESPACE_END(sway)
