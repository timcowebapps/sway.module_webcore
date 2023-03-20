#include <sway/webcore/region.hpp>
#include <sway/webcore/treenodeelement.hpp>

#include <memory>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)

void Region::registerEmClass() {
#ifdef EMSCRIPTEN_PLATFORM
  emscripten::class_<Region>("Region")
      .constructor<core::container::Hierarchy *, core::container::NodeIdx, RegionCreateInfo>()
      .smart_ptr<std::shared_ptr<Region>>("RegionSmartPtr")
      .function("attachView", &Region::attachView, emscripten::allow_raw_pointers())
      .function("detachView", &Region::detachView, emscripten::allow_raw_pointers())
      .function("getHtmlElementId", &Region::getHtmlElementId);
#endif
}

Region::Region(std::shared_ptr<TreeNodeElement> parent, const RegionCreateInfo &createInfo)
    : parent_(parent)
    , htmlElementId_(createInfo.id)
    , htmlElementReplace_(createInfo.replace)
    , attached_(false) {}

void Region::attachView(std::shared_ptr<TreeNodeElement> node) {
  attachedNodeIdx_ = node->getNodeIdx();
  parent_->addChildNode(node);
  attached_ = true;
}

void Region::detachView(TreeNodeElement *node) {
  if (attached_) {
    std::shared_ptr<core::container::Node> other_ptr(node);
    core::container::Hierarchy::findNode(node->getParentNode().value(), parent_->getNodeIdx())
        .value()
        ->removeChildNode(other_ptr);
    attached_ = false;
  }
}

core::container::NodeIdx Region::getAttachedNodeIdx() const { return attachedNodeIdx_; }

std::string Region::getHtmlElementId() const { return htmlElementId_; }

bool Region::hasHtmlElementReplaced() const { return htmlElementReplace_; }

bool Region::hasAttached() const { return attached_; }

NAMESPACE_END(webcore)
NAMESPACE_END(sway)
