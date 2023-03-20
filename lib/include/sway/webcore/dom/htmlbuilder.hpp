#ifndef SWAY_WEBCORE_DOM_HTMLBUILDER_HPP
#define SWAY_WEBCORE_DOM_HTMLBUILDER_HPP

#include <sway/webcore/dom/htmlelement.hpp>
#include <sway/webcore/prereqs.hpp>
#include <sway/webcore/treenodeelement.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)
NAMESPACE_BEGIN(dom)

class HtmlBuilder {
public:
  HtmlBuilder() = default;

  virtual ~HtmlBuilder() = default;

  auto createHtmlElement(TreeNodeElement *element) -> HtmlElement;
};

NAMESPACE_END(dom)
NAMESPACE_END(webcore)
NAMESPACE_END(sway)

#endif
