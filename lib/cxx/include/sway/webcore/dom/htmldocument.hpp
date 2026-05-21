#ifndef SWAY_WEBCORE_DOM_HTMLDOCUMENT_HPP
#define SWAY_WEBCORE_DOM_HTMLDOCUMENT_HPP

#include <sway/emscriptenmacros.hpp>
#include <sway/webcore/dom/htmlelement.hpp>
#include <sway/webcore/prereqs.hpp>

namespace sway::webcore {

class HtmlDocument {
  DECLARE_EMSCRIPTEN_BINDING()

public:
  static auto createElement(const std::string &tagname) -> HtmlElementTypedefs::SharedPtr_t;

  static auto getElementById(const std::string &id) -> HtmlElementTypedefs::SharedPtr_t;

  static auto getElementBySelector(const std::string &selector) -> HtmlElement;
};

}  // namespace sway::webcore

#endif
