#include <sway/webcore/base/treenodeelement.h>
#include <sway/webcore/base/treeupdater.h>
#include <sway/webcore/base/treevisitor.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)
NAMESPACE_BEGIN(base)

void TreeNodeElement::registerEmscriptenClass(lpcstr_t classname) {
	emscripten::class_<TreeNodeElement, emscripten::base<core::containers::TreeNodeBase>>(classname)
		//.constructor<TreeNodeElementCreateInfo>()
		.function("accept", &TreeNodeElement::accept, emscripten::allow_raw_pointers(), emscripten::pure_virtual())
		.function("addRegion", &TreeNodeElement::addRegion)
		.function("getRegion", &TreeNodeElement::getRegion, emscripten::allow_raw_pointers())
		.function("getRegionNames", &TreeNodeElement::getRegionNames)
		.function("addEvent", &TreeNodeElement::addEvent, emscripten::allow_raw_pointers())
		.function("bindEvents", &TreeNodeElement::bindEvents)
		.function("getHtmlElementTagname", &TreeNodeElement::getHtmlElementTagname)
		.function("setHtmlElementTagname", &TreeNodeElement::setHtmlElementTagname)
		.function("getHtmlElementId", &TreeNodeElement::getHtmlElementId)
		.function("setHtmlElementId", &TreeNodeElement::setHtmlElementId)
		.function("getHtmlContent", &TreeNodeElement::getHtmlContent)
		.function("setHtmlContent", &TreeNodeElement::setHtmlContent);
}

TreeNodeElement::TreeNodeElement(core::containers::TreeNodePtr_t parent,
	const core::containers::TreeNodeIndex & nodeIndex,
	const std::string & nodeId, const TreeNodeElementCreateInfo & createInfo)
	: core::containers::TreeNodeBase(parent, nodeIndex, nodeId)
	, _htmlElementTagname(createInfo.tagname)
	, _htmlElementId(createInfo.id)
	, _visibled(true) {
	// Empty
}

void TreeNodeElement::addRegion(const std::string & name, const RegionCreateInfo & createInfo) {
	_regions.insert(std::make_pair(name,
		std::make_shared<RegionMixin>(getHostTree(), getNodeIndex(), createInfo)));
}

RegionMixinPtr_t TreeNodeElement::getRegion(const std::string & name) const {
	RegionMixinIterator_t iter = _regions.find(name);
	if (iter != _regions.end())
		return iter->second;

	return nullptr;
}

RegionMixinPtr_t TreeNodeElement::getRegionByNodeId(const std::string & nodeId) const {
	for (auto iter = _regions.begin(); iter != _regions.end(); ++iter) {
		RegionMixinPtr_t region = iter->second;
		if (region->getAttachedNodeId() == nodeId)
			return region;
	}

	return nullptr;
}

RegionMixinMap_t TreeNodeElement::getRegions() {
	return _regions;
}

RegionMixinNameVec_t TreeNodeElement::getRegionNames() const {
	RegionMixinNameVec_t keys;
	std::transform(_regions.begin(), _regions.end(), std::back_inserter(keys),
		[](const RegionMixinMap_t::value_type & pair) {
			return pair.first;
		}
	);

	return keys;
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

NAMESPACE_END(base)
NAMESPACE_END(webcore)
NAMESPACE_END(sway)
