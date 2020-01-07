#include <sway/webcore/treenodeelement.h>
#include <sway/webcore/treeupdater.h>
#include <sway/webcore/treevisitor.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)

void TreeNodeElement::registerEmscriptenClass(lpcstr_t classname) {
	emscripten::class_<TreeNodeElement, emscripten::base<core::containers::HierarchyNode>>(classname)
		.function("accept", &TreeNodeElement::accept, emscripten::allow_raw_pointers(), emscripten::pure_virtual())
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
}

TreeNodeElement::TreeNodeElement(core::containers::HierarchyNodePtr_t parent,
	const core::containers::HierarchyNodeIndex & nodeIndex,
	const std::string & nodeId, const TreeNodeElementCreateInfo & createInfo)
	: core::containers::HierarchyNode(parent, nodeIndex, nodeId)
	, _htmlElementTagname(createInfo.tagname)
	, _htmlElementId(createInfo.id)
	, _visibled(true) {

	_selectorGroup.push_back(Selector(
		core::detail::toUnderlying(SelectorTypes_t::kId), createInfo.id));
}

void TreeNodeElement::accept(ITreeVisitor * visitor) {
	// Empty
}

void TreeNodeElement::addRegion(const std::string & name, const RegionCreateInfo & createInfo) {
	_regions.insert(std::make_pair(name,
		std::make_shared<RegionMixin>(getHostTree(), getNodeIndex(), createInfo)));
}

RegionPtr_t TreeNodeElement::getRegion(const std::string & name) const {
	RegionMapIterator_t iter = _regions.find(name);
	if (iter != _regions.end())
		return iter->second;

	return nullptr;
}

RegionPtr_t TreeNodeElement::getRegionByNodeId(const std::string & nodeId) const {
	for (auto iter = _regions.begin(); iter != _regions.end(); ++iter) {
		RegionPtr_t region = iter->second;
		if (region->getAttachedNodeId() == nodeId)
			return region;
	}

	return nullptr;
}

RegionMap_t TreeNodeElement::getRegions() {
	return _regions;
}

SelectorGroup_t TreeNodeElement::getSelectorGroup() {
	return _selectorGroup;
}

void TreeNodeElement::addEvent(const std::string & targetId, const std::string & type, emscripten::val callback) {
	_handlers.push_back((struct EventHandler) {
		.targetId = targetId,
		.target = new EventTarget([](emscripten::val) { /* Empty */ }),
		.type = type
	});

	_handlers.back().target->setCallback(callback);
}

void TreeNodeElement::bindEvents() {
	for (int i = 0; i < _handlers.size(); ++i) {
		EventHandler event = _handlers[i];
		event.target->addEventListener(event.targetId, event.type/*stringize(event.type)*/);
	}
}

std::string TreeNodeElement::getHtmlElementTagname() const {
	return _htmlElementTagname;
}

void TreeNodeElement::setHtmlElementTagname(const std::string & tagname) {
	_htmlElementTagname = tagname;
}

std::vector<std::string> TreeNodeElement::getHtmlElementClasses() const {
	return _htmlElementClasses;
}

void TreeNodeElement::setHtmlElementClasses(const std::vector<std::string> & classes) {
	_htmlElementClasses = classes;
}

std::string TreeNodeElement::getHtmlElementId() const {
	return _htmlElementId;
}

void TreeNodeElement::setHtmlElementId(const std::string & id) {
	_htmlElementId = id;
}

std::string TreeNodeElement::getHtmlContent() const {
	return _htmlContent;
}

void TreeNodeElement::setHtmlContent(const std::string & content) {
	_htmlContent = content;
}

bool TreeNodeElement::hasVisibled() const {
	return _visibled;
}

void TreeNodeElement::setVisible(bool value) {
	_visibled = value;
}

NAMESPACE_END(webcore)
NAMESPACE_END(sway)
