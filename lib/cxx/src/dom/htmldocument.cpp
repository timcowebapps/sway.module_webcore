#include <sway/webcore/dom/htmldocument.hpp>

namespace sway::webcore {

EMSCRIPTEN_BINDING_BEGIN(HtmlDocument)
emscripten::class_<HtmlDocument>("HtmlDocument")
    .class_function("createElement", &HtmlDocument::createElement)
    .class_function("getElementById", &HtmlDocument::getElementById)
    .class_function("getElementBySelector", &HtmlDocument::getElementBySelector);
EMSCRIPTEN_BINDING_END()

auto HtmlDocument::createElement(const std::string &tagname) -> HtmlElementTypedefs::SharedPtr_t {
  emscripten::val element =
      emscripten::val::global("document").call<emscripten::val>("createElement", emscripten::val(tagname));
  return std::unique_ptr<HtmlElement>(new HtmlElement(element));
}

auto HtmlDocument::getElementById(const std::string &id) -> HtmlElementTypedefs::SharedPtr_t {
  emscripten::val element = emscripten::val::global("document").call<emscripten::val>("getElementById", id);
  if (element.isNull() || element.isUndefined()) {
    return std::unique_ptr<HtmlElement>(new HtmlElement());
  }

  return std::unique_ptr<HtmlElement>(new HtmlElement(element));
}

auto HtmlDocument::getElementBySelector(const std::string &selector) -> HtmlElement {
  emscripten::val element = emscripten::val::global("document").call<emscripten::val>("querySelector", selector);
  if (element.isNull() || element.isUndefined()) {
    return HtmlElement();
  }

  return HtmlElement(element);
}

}  // namespace sway::webcore
