#ifndef SWAY_WEBCORE_DOM_HTMLDOCUMENT_HPP
#define SWAY_WEBCORE_DOM_HTMLDOCUMENT_HPP

#include <sway/webcore/dom/htmlelement.hpp>
#include <sway/webcore/prereqs.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)
NAMESPACE_BEGIN(dom)

class HtmlDocument {
public:
  static HtmlElement createElement(const std::string &tagname) {
#ifdef _EMSCRIPTEN
    return emscripten::val::global("document").call<emscripten::val>("createElement", emscripten::val(tagname));
#else
    return HtmlElement();
#endif
  }

  static HtmlElement getElementById(const std::string &id) {
#ifdef _EMSCRIPTEN
    return emscripten::val::global("document").call<emscripten::val>("getElementById", id);
#else
    return HtmlElement();
#endif
  }

  static HtmlElement getElementBySelector(const std::string &selector) {
#ifdef _EMSCRIPTEN
    return emscripten::val::global("document").call<emscripten::val>("querySelector", selector);
#else
    return HtmlElement();
#endif
  }
};

NAMESPACE_END(dom)
NAMESPACE_END(webcore)
NAMESPACE_END(sway)

#endif
