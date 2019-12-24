#include <sway/webcore/dom/htmlbuilder.h>
#include <sway/webcore/dom/htmldocument.h>
#include <sway/webcore/dom/htmlelement.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)
NAMESPACE_BEGIN(dom)

HtmlBuilder::HtmlBuilder() {
	// Empty
}

HtmlElement HtmlBuilder::createHtmlElement(base::TreeNodeElement * element) {
	auto htmlElement = dom::HtmlDocument::createElement(element->getHtmlElementTagname());
	htmlElement.setAttribute("id", element->getHtmlElementId());
	//htmlElement.setAttribute("data-node-id", node.nodeId);
	htmlElement.setInnerHtml(element->getHtmlContent());
	return htmlElement;
}

NAMESPACE_END(dom)
NAMESPACE_END(webcore)
NAMESPACE_END(sway)
