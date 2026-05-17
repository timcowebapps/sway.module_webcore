#include <sway/webcore/dom/htmlbuilder.hpp>
#include <sway/webcore/dom/htmldocument.hpp>
#include <sway/webcore/dom/htmlelement.hpp>
#include <sway/webcore/nodesynchronizer.hpp>
#include <sway/webcore/region.hpp>

namespace sway::webcore {

NodeSynchronizer::NodeSynchronizer() { htmlBuilder_ = new HtmlBuilder(); }

NodeSynchronizer::~NodeSynchronizer() { core::safeDelete<HtmlBuilder *>(htmlBuilder_); }

void NodeSynchronizer::insertNode(PendingNode node) {
  HtmlElement parentHtmlElement = HtmlDocument::getElementById(node.parentElement->getHtmlElementId());
  // if (parentHtmlElement.val_.isNull())
  //     return;

  // if (node.region) {
  //     HtmlElement regionHtmlElement =
  //     HtmlDocument::getElementById(node.region.get()->getHtmlElementId()); if
  //     (regionHtmlElement.val_.isNull()) {
  //         return;
  //     }

  //     if (node.region->hasHtmlElementReplaced()) {
  //         auto parentRegionHtmlElement = regionHtmlElement.getParentElement();
  //         parentRegionHtmlElement.replaceChild(
  //             htmlBuilder_->createHtmlElement(node.element.second), regionHtmlElement);
  //     } else {
  //         parentHtmlElement.appendChild(htmlBuilder_->createHtmlElement(node.element.second));
  //     }
  // } else {
  //     parentHtmlElement.appendChild(htmlBuilder_->createHtmlElement(node.element.second));
  // }

  // node.element.second->bindEvents();
}

void NodeSynchronizer::removeNode(PendingNode node) {
  // if (node.region && !node.region->hasAttached()) {
  //     return;
  // }

  // HtmlElement current = HtmlDocument::getElementById(node.element.second->getHtmlElementId());
  // if (current.val_.isNull()) {
  //     return;
  // }

  // HtmlElement parent = current.getParentElement();
  // if (parent.val_.isNull()) {
  //     return;
  // }

  // if (node.region) {
  //     HtmlElement regionHtmlElement =
  //     HtmlDocument::getElementById(node.region.get()->getHtmlElementId()); if
  //     (regionHtmlElement.val_.isNull()) {
  //         return;
  //     }

  //     if (node.region->hasHtmlElementReplaced()) {
  //         auto parentRegionHtmlElement = regionHtmlElement.getParentElement();
  //         parentRegionHtmlElement.replaceChild(
  //             htmlBuilder_->createHtmlElement(node.element.second), regionHtmlElement);
  //     } else {
  //         parent.removeChild(current);
  //     }
  // } else {
  //     parent.removeChild(current);
  // }
}

void NodeSynchronizer::applyPendingUpdate(PendingNode node) {
  // remove and re-insert the node
  removeNode(node);
  insertNode(node);
}

}  // namespace sway::webcore
