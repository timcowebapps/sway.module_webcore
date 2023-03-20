#include <sway/webcore/treenodeelement.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)

EMSCRIPTEN_BINDING_BEGIN(TreeNodeElement)
#ifdef EMSCRIPTEN_PLATFORM
emscripten::class_<TreeNodeElement, emscripten::base<core::container::Node>>("TreeNodeElement")
    .constructor<core::container::Node *, core::container::NodeIdx, TreeNodeElementDescriptor>()
    .function("addRegion", &TreeNodeElement::addRegion)
    .function("getRegion", &TreeNodeElement::getRegion, emscripten::allow_raw_pointers())
    .function("addEvent", &TreeNodeElement::addEvent, emscripten::allow_raw_pointers())
    .function("bindEvents", &TreeNodeElement::bindEvents)
    .function("getHtmlElementTagname", &TreeNodeElement::getHtmlElementTagname)
    .function("setHtmlElementTagname", &TreeNodeElement::setHtmlElementTagname)
    .function("getHtmlElementClasses", &TreeNodeElement::getHtmlElementClasses)
    .function("setHtmlElementClasses", &TreeNodeElement::setHtmlElementClasses)
    .function("getHtmlElementId", &TreeNodeElement::getHtmlElementId)
    .function("setHtmlElementId", &TreeNodeElement::setHtmlElementId)
    .function("getHtmlContent", &TreeNodeElement::getHtmlContent)
    .function("setHtmlContent", &TreeNodeElement::setHtmlContent);
#endif
EMSCRIPTEN_BINDING_END()

TreeNodeElement::TreeNodeElement(const TreeNodeElementDescriptor &createInfo)
    : htmlElementTagname_(createInfo.tagname)
    , htmlElementId_(createInfo.id) {}

void TreeNodeElement::addRegion(const std::string &name, const RegionCreateInfo &createInfo) {
  regions_.insert(std::make_pair(name, std::make_shared<Region>(sharedFrom<TreeNodeElement>(this), createInfo)));
}

auto TreeNodeElement::getRegion(const std::string &name) const -> std::shared_ptr<Region> {
  RegionMapIterator_t iter = regions_.find(name);
  if (iter != regions_.end()) {
    return iter->second;
  }

  return nullptr;
}

auto TreeNodeElement::getRegionByNodeIdx(const core::container::NodeIdx &nodeIdx) const -> std::shared_ptr<Region> {
  for (auto const &item : regions_) {
    auto region = item.second;
    if (region->getAttachedNodeIdx().equal(nodeIdx)) {
      return region;
    }
  }

  return nullptr;
}

auto TreeNodeElement::getRegions() -> RegionMap_t { return regions_; }

void TreeNodeElement::addEvent(const std::string &targetId, const std::string &type
#ifdef EMSCRIPTEN_PLATFORM
    ,
    emscripten::val callback
#endif
) {
#ifdef EMSCRIPTEN_PLATFORM
  handlers_.push_back(
      (struct EventHandler){.targetId = targetId, .target = new EventTarget([](emscripten::val) {}), .type = type});

  handlers_.back().target->setCallback(callback);
#endif
}

void TreeNodeElement::bindEvents() {
  for (EventHandler event : handlers_) {
    event.target->addEventListener(event.targetId, event.type);
  }
}

auto TreeNodeElement::getHtmlElementTagname() const -> std::string { return htmlElementTagname_; }

void TreeNodeElement::setHtmlElementTagname(const std::string &tagname) { htmlElementTagname_ = tagname; }

auto TreeNodeElement::getHtmlElementClasses() const -> std::vector<std::string> { return htmlElementClasses_; }

void TreeNodeElement::setHtmlElementClasses(const std::vector<std::string> &classes) { htmlElementClasses_ = classes; }

auto TreeNodeElement::getHtmlElementId() const -> std::string { return htmlElementId_; }

void TreeNodeElement::setHtmlElementId(const std::string &id) { htmlElementId_ = id; }

auto TreeNodeElement::getHtmlContent() const -> std::string { return htmlContent_; }

void TreeNodeElement::setHtmlContent(const std::string &content) { htmlContent_ = content; }

NAMESPACE_END(webcore)
NAMESPACE_END(sway)
