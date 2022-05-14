#include <sway/webcore/css/selectors/cnselector.hpp>
#include <sway/webcore/dom/htmlbuilder.hpp>
#include <sway/webcore/dom/htmldocument.hpp>
#include <sway/webcore/dom/htmlelement.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)
NAMESPACE_BEGIN(dom)

HtmlElement HtmlBuilder::createHtmlElement(TreeNodeElement *element) {
  auto htmlElement = HtmlDocument::createElement(element->getHtmlElementTagname());
  htmlElement.setAttribute("id", element->getHtmlElementId());
  for ( std::string cn : element->getHtmlElementClasses() ) {
    htmlElement.addClassName(cn);
  }

  htmlElement.setInnerContent(element->getHtmlContent());
  return htmlElement;
}

NAMESPACE_END(dom)
NAMESPACE_END(webcore)
NAMESPACE_END(sway)
