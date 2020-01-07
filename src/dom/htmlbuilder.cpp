#include <sway/webcore/dom/htmlbuilder.h>
#include <sway/webcore/dom/htmldocument.h>
#include <sway/webcore/dom/htmlelement.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)
NAMESPACE_BEGIN(dom)

HtmlBuilder::HtmlBuilder() {
	// Empty
}

HtmlElement HtmlBuilder::createHtmlElement(TreeNodeElement * element) {
	auto htmlElement = HtmlDocument::createElement(element->getHtmlElementTagname());
	for (u32_t i = 0; i < element->getHtmlElementClasses().size(); ++i)
		htmlElement.addClassName(element->getHtmlElementClasses()[i]);

	htmlElement.setAttribute("id", element->getHtmlElementId());
	htmlElement.setInnerContent(element->getHtmlContent());
	return htmlElement;
}

NAMESPACE_END(dom)
NAMESPACE_END(webcore)
NAMESPACE_END(sway)
