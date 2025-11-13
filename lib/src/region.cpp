#include <sway/webcore/region.hpp>
#include <sway/webcore/treenodeelement.hpp>

#include <memory>

namespace sway::webcore {

EMSCRIPTEN_BINDING_BEGIN(Region)
#ifdef EMSCRIPTEN_PLATFORM
emscripten::class_<Region>("Region")
    .constructor<std::shared_ptr<TreeNodeElement>, RegionCreateInfo>()
    .smart_ptr<std::shared_ptr<Region>>("RegionSmartPtr")
    .function("attachView", &Region::attachView, emscripten::allow_raw_pointers())
    .function("detachView", &Region::detachView, emscripten::allow_raw_pointers())
    .function("getHtmlElementId", &Region::getHtmlElementId);
#endif
EMSCRIPTEN_BINDING_END()

Region::Region(std::shared_ptr<TreeNodeElement> parent, const RegionCreateInfo &createInfo)
    : parent_(parent)
    , htmlElementId_(createInfo.id)
    , htmlElementReplace_(createInfo.replace)
    , attached_(false) {}

void Region::attachView(std::shared_ptr<TreeNodeElement> node) {
  attachedNodeIdx_ = node->getNodeIndex();
  parent_->addChildNode(node);
  attached_ = true;
}

void Region::detachView(TreeNodeElement *node) {
  if (attached_) {
    std::shared_ptr<core::Node> other_ptr(node);
    core::Hierarchy::findNode(node->getParentNode().value(), parent_->getNodeIndex())
        .value()
        ->removeChildNode(other_ptr);
    attached_ = false;
  }
}

auto Region::getAttachedNodeIdx() const -> core::NodeIndex { return attachedNodeIdx_; }

auto Region::getHtmlElementId() const -> std::string { return htmlElementId_; }

auto Region::hasHtmlElementReplaced() const -> bool { return htmlElementReplace_; }

auto Region::hasAttached() const -> bool { return attached_; }

}  // namespace sway::webcore
