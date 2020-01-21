#include <sway/webcore/nodesynchronizer.h>
#include <sway/webcore/region.h>
#include <sway/webcore/dom/htmldocument.h>
#include <sway/webcore/dom/htmlelement.h>
#include <sway/webcore/dom/htmlbuilder.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)

NodeSynchronizer::NodeSynchronizer() {
	_htmlBuilder = new dom::HtmlBuilder();
}

NodeSynchronizer::~NodeSynchronizer() {
	SAFE_DELETE(_htmlBuilder);
}

void NodeSynchronizer::insertNode(PendingNode node) {
	dom::HtmlElement parentHtmlElement = dom::HtmlDocument::getElementById(node.parentElement->getHtmlElementId());
	if (parentHtmlElement._val.isNull())
		return;

	if (node.region) {
		dom::HtmlElement regionHtmlElement =  dom::HtmlDocument::getElementById(node.region.get()->getHtmlElementId());
		if (regionHtmlElement._val.isNull())
			return;

		if (node.region->hasHtmlElementReplaced()) {
			auto parentRegionHtmlElement = regionHtmlElement.getParentElement();
			parentRegionHtmlElement.replaceChild(_htmlBuilder->createHtmlElement(node.element.second), regionHtmlElement);
		}
		else {
			parentHtmlElement.appendChild(_htmlBuilder->createHtmlElement(node.element.second));
		}
	}
	else {
		parentHtmlElement.appendChild(_htmlBuilder->createHtmlElement(node.element.second));
	}

	node.element.second->bindEvents();
}

void NodeSynchronizer::removeNode(PendingNode node) {
	if (node.region && !node.region->hasAttached())
		return;

	dom::HtmlElement current = dom::HtmlDocument::getElementById(node.element.second->getHtmlElementId());
	if (current._val.isNull())
		return;

	dom::HtmlElement parent = current.getParentElement();
	if (parent._val.isNull())
		return;

	if (node.region) {
		dom::HtmlElement regionHtmlElement =  dom::HtmlDocument::getElementById(node.region.get()->getHtmlElementId());
		if (regionHtmlElement._val.isNull())
			return;

		if (node.region->hasHtmlElementReplaced()) {
			auto parentRegionHtmlElement = regionHtmlElement.getParentElement();
			parentRegionHtmlElement.replaceChild(_htmlBuilder->createHtmlElement(node.element.second), regionHtmlElement);
		}
		else {
			parent.removeChild(current);
		}
	}
	else {
		parent.removeChild(current);
	}
}

void NodeSynchronizer::applyPendingUpdate(PendingNode node) {
	// remove and re-insert the node
	removeNode(node);
	insertNode(node);
}

NAMESPACE_END(webcore)
NAMESPACE_END(sway)
