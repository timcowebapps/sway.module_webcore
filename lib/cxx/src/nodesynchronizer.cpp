#include <sway/webcore/dom/htmlbuilder.hpp>
#include <sway/webcore/dom/htmldocument.hpp>
#include <sway/webcore/dom/htmlelement.hpp>
#include <sway/webcore/nodesynchronizer.hpp>
#include <sway/webcore/region.hpp>

namespace sway::webcore {

NodeSynchronizer::NodeSynchronizer() { htmlBuilder_ = new HtmlBuilder(); }

NodeSynchronizer::~NodeSynchronizer() { core::safeDelete<HtmlBuilder *>(htmlBuilder_); }

void NodeSynchronizer::insertNode(PendingNode node) {
  HtmlElementTypedefs::SharedPtr_t parentHtmlElement =
      HtmlDocument::getElementById(node.parentElement->getHtmlElementId());
  if (parentHtmlElement->getJsValue().isNull()) {
    return;
  }

  if (node.region) {
    HtmlElementTypedefs::SharedPtr_t regionHtmlElement =
        HtmlDocument::getElementById(node.region.get()->getHtmlElementId());
    if (regionHtmlElement->getJsValue().isNull()) {
      return;
    }

    if (node.region->hasHtmlElementReplaced()) {
      auto parentRegionHtmlElement = regionHtmlElement->getParentElement();
      parentRegionHtmlElement->replaceChild(
          htmlBuilder_->createHtmlElement(node.element.second), std::move(regionHtmlElement));
    } else {
      parentHtmlElement->appendChild(htmlBuilder_->createHtmlElement(node.element.second));
    }
  } else {
    parentHtmlElement->appendChild(htmlBuilder_->createHtmlElement(node.element.second));
  }

  node.element.second->bindEvents();
}

void NodeSynchronizer::removeNode(PendingNode node) {
  if (node.region && !node.region->hasAttached()) {
    return;
  }

  HtmlElementTypedefs::SharedPtr_t current = HtmlDocument::getElementById(node.element.second->getHtmlElementId());
  if (current->getJsValue().isNull()) {
    return;
  }

  HtmlElement *parent = dynamic_cast<HtmlElement *>(current->getParentElement().get());
  if (parent->getJsValue().isNull()) {
    return;
  }

  if (node.region) {
    HtmlElementTypedefs::SharedPtr_t regionHtmlElement =
        HtmlDocument::getElementById(node.region.get()->getHtmlElementId());
    if (regionHtmlElement->getJsValue().isNull()) {
      return;
    }

    if (node.region->hasHtmlElementReplaced()) {
      auto parentRegionHtmlElement = regionHtmlElement->getParentElement();
      parentRegionHtmlElement->replaceChild(
          htmlBuilder_->createHtmlElement(node.element.second), std::move(regionHtmlElement));
    } else {
      parent->removeChild(std::move(current));
    }
  } else {
    parent->removeChild(std::move(current));
  }
}

void NodeSynchronizer::applyPendingUpdate(PendingNode node) {
  // remove and re-insert the node
  removeNode(node);
  insertNode(node);
}

}  // namespace sway::webcore
