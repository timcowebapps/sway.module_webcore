#include <sway/webcore/dom/htmlelement.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)
NAMESPACE_BEGIN(dom)

HtmlElement::HtmlElement()
#ifdef EMSCRIPTEN_PLATFORM
    : val_(emscripten::val::null())
#endif
{
}

#ifdef EMSCRIPTEN_PLATFORM
HtmlElement::HtmlElement(const emscripten::val &value)
    : val_(value) {}
#endif

HtmlElement HtmlElement::getParentElement() const {
#ifdef EMSCRIPTEN_PLATFORM
  return val_["parentElement"].as<emscripten::val>();
#else
  return HtmlElement();
#endif
}

HtmlElement HtmlElement::appendChild(const HtmlElement &child) {
#ifdef EMSCRIPTEN_PLATFORM
  return val_.call<emscripten::val>("appendChild", child.val_);
#else
  return HtmlElement();
#endif
}

HtmlElement HtmlElement::replaceChild(HtmlElement newnode, HtmlElement oldnode) {
#ifdef EMSCRIPTEN_PLATFORM
  return val_.call<emscripten::val>("replaceChild", newnode.val_, oldnode.val_);
#else
  return HtmlElement();
#endif
}

HtmlElement HtmlElement::removeChild(const HtmlElement &child) {
#ifdef EMSCRIPTEN_PLATFORM
  return val_.call<emscripten::val>("removeChild", child.val_);
#else
  return HtmlElement();
#endif
}

void HtmlElement::setInnerContent(const std::string &content, bool dirty) {
#ifdef EMSCRIPTEN_PLATFORM
  val_.set(core::misc::format("inner%s", dirty ? "HTML" : "Text"), content);
#endif
}

void HtmlElement::setAttribute(const std::string &key, const std::string &value) {
#ifdef EMSCRIPTEN_PLATFORM
  val_.call<void>("setAttribute", emscripten::val(key), emscripten::val(value));
#endif
}

void HtmlElement::addClassName(const std::string &className) {
  if (className.empty()) {
    return;
  }

#ifdef EMSCRIPTEN_PLATFORM
  val_["classList"].call<void>("add", emscripten::val(className));
#endif
}

std::string HtmlElement::toString() const {
#ifdef EMSCRIPTEN_PLATFORM
  return val_.call<std::string>("toString");
#else
  return "";
#endif
}

NAMESPACE_END(dom)
NAMESPACE_END(webcore)
NAMESPACE_END(sway)
