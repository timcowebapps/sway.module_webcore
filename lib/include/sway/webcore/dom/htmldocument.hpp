#ifndef SWAY_WEBCORE_DOM_HTMLDOCUMENT_HPP
#define SWAY_WEBCORE_DOM_HTMLDOCUMENT_HPP

#include <sway/webcore/dom/htmlelement.hpp>
#include <sway/webcore/prereqs.hpp>

namespace sway::webcore {

class HtmlDocument {
public:
  static auto createElement(const std::string &tagname) -> HtmlElement {
#ifdef EMSCRIPTEN_PLATFORM
    return emscripten::val::global("document").call<emscripten::val>("createElement", emscripten::val(tagname));
#else
    return HtmlElement();
#endif
  }

  static auto getElementById(const std::string &id) -> HtmlElement {
#ifdef EMSCRIPTEN_PLATFORM
    return emscripten::val::global("document").call<emscripten::val>("getElementById", id);
#else
    return HtmlElement();
#endif
  }

  static auto getElementBySelector(const std::string &selector) -> HtmlElement {
#ifdef EMSCRIPTEN_PLATFORM
    return emscripten::val::global("document").call<emscripten::val>("querySelector", selector);
#else
    return HtmlElement();
#endif
  }
};

}  // namespace sway::webcore

#endif
