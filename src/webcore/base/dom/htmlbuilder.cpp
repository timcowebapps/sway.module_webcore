#include <sway/webcore/base/dom/htmlbuilder.h>
#include <sway/webcore/base/dom/htmldocument.h>
#include <sway/webcore/base/dom/htmlelement.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)
NAMESPACE_BEGIN(base)
NAMESPACE_BEGIN(dom)

HtmlBuilder::HtmlBuilder() {
	// Empty
}

HtmlElement HtmlBuilder::createHtmlElement(TreeNodeElement * element) {
	auto htmlElement = HtmlDocument::createElement(element->getHtmlElementTagname());
	htmlElement.setAttribute("id", element->getHtmlElementId());
	htmlElement.setInnerContent(element->getHtmlContent());
	return htmlElement;
}

NAMESPACE_END(dom)
NAMESPACE_END(base)
NAMESPACE_END(webcore)
NAMESPACE_END(sway)
