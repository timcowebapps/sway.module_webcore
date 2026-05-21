#ifndef SWAY_WEBCORE_DOM_HTMLBUILDER_HPP
#define SWAY_WEBCORE_DOM_HTMLBUILDER_HPP

#include <sway/webcore/dom/htmlelement.hpp>
#include <sway/webcore/prereqs.hpp>
#include <sway/webcore/treenodeelement.hpp>

namespace sway::webcore {

class HtmlBuilder {
public:
  HtmlBuilder() = default;

  virtual ~HtmlBuilder() = default;

  auto createHtmlElement(TreeNodeElement *element) -> HtmlElementTypedefs::SharedPtr_t;
};

}  // namespace sway::webcore

#endif
