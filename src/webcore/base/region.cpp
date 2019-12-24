#include <sway/webcore/base/region.h>
#include <sway/webcore/base/treenode.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)
NAMESPACE_BEGIN(base)

void RegionMixin::registerEmscriptenClass(lpcstr_t classname) {
	emscripten::class_<RegionMixin>(classname)
		.constructor<core::containers::Tree *, core::containers::TreeNodeIndex, RegionCreateInfo>()
		.smart_ptr<RegionMixinPtr_t>(core::misc::format("%sSmartPtr", classname).c_str())
		.function("attachView", &RegionMixin::attachView, emscripten::allow_raw_pointers())
		.function("detachView", &RegionMixin::detachView, emscripten::allow_raw_pointers())
		.function("getHtmlElementId", &RegionMixin::getHtmlElementId);
}

RegionMixin::RegionMixin(core::containers::Tree * tree,
	const core::containers::TreeNodeIndex & parentNodeIndex, const RegionCreateInfo & createInfo)
	: _tree(tree)
	, _parentNodeIndex(parentNodeIndex)
	, _htmlElementId(createInfo.id)
	, _htmlElementReplace(createInfo.replace)
	, _attached(false) {
	// Empty
}

void RegionMixin::attachView(TreeNode * node) {
	_attachedNodeId = node->getNodeId();
	_attached = _tree->find(_parentNodeIndex)->addChild(node).isValid();
}

void RegionMixin::detachView(TreeNode * node) {
	if (_attached) {
		_tree->find(_parentNodeIndex)->removeChild(node);
		_attached = false;
	}
}

std::string RegionMixin::getAttachedNodeId() const {
	return _attachedNodeId;
}

std::string RegionMixin::getHtmlElementId() const {
	return _htmlElementId;
}

bool RegionMixin::hasHtmlElementReplaced() const {
	return _htmlElementReplace;
}

bool RegionMixin::hasAttached() const {
	return _attached;
}

NAMESPACE_END(base)
NAMESPACE_END(webcore)
NAMESPACE_END(sway)
