#include <sway/webcore/region.h>
#include <sway/webcore/treenodeelement.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)

void Region::registerEmscriptenClass(lpcstr_t classname) {
	emscripten::class_<Region>(classname)
		.constructor<core::containers::Hierarchy *, core::containers::HierarchyNodeIndex, RegionCreateInfo>()
		.smart_ptr<RegionPtr_t>(core::misc::format("%sSmartPtr", classname).c_str())
		.function("attachView", &Region::attachView, emscripten::allow_raw_pointers())
		.function("detachView", &Region::detachView, emscripten::allow_raw_pointers())
		.function("getHtmlElementId", &Region::getHtmlElementId);
}

Region::Region(core::containers::Hierarchy * tree,
	const core::containers::HierarchyNodeIndex & parentNodeIndex, const RegionCreateInfo & createInfo)
	: _tree(tree)
	, _parentNodeIndex(parentNodeIndex)
	, _htmlElementId(createInfo.id)
	, _htmlElementReplace(createInfo.replace)
	, _attached(false) {
	// Empty
}

void Region::attachView(TreeNodeElement * node) {
	_attachedNodeId = node->getNodeId();
	_attached = _tree->find(_parentNodeIndex)->addChild(node).isValid();
}

void Region::detachView(TreeNodeElement * node) {
	if (_attached) {
		_tree->find(_parentNodeIndex)->removeChild(node);
		_attached = false;
	}
}

std::string Region::getAttachedNodeId() const {
	return _attachedNodeId;
}

std::string Region::getHtmlElementId() const {
	return _htmlElementId;
}

bool Region::hasHtmlElementReplaced() const {
	return _htmlElementReplace;
}

bool Region::hasAttached() const {
	return _attached;
}

NAMESPACE_END(webcore)
NAMESPACE_END(sway)
