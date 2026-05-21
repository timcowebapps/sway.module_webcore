#include <sway/webcore/css/selectors/cnselector.hpp>
#include <sway/webcore/dom/htmlbuilder.hpp>
#include <sway/webcore/dom/htmldocument.hpp>
#include <sway/webcore/dom/htmlelement.hpp>

namespace sway::webcore {

auto HtmlBuilder::createHtmlElement(TreeNodeElement *element) -> HtmlElementTypedefs::SharedPtr_t {
  auto htmlElement = HtmlDocument::createElement(element->getHtmlElementTagname());
  htmlElement->setAttribute("id", element->getHtmlElementId());
  for (std::string cn : element->getHtmlElementClasses()) {
    htmlElement->addClassName(cn);
  }

  htmlElement->setInnerContent(element->getHtmlContent());
  return htmlElement;
}

}  // namespace sway::webcore
