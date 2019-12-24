#include <sway/webcore/base/treenode.h>
#include <sway/webcore/base/treeupdater.h>
#include <sway/webcore/base/treevisitor.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)
NAMESPACE_BEGIN(base)

void TreeNode::registerEmscriptenClass(lpcstr_t classname) {
	emscripten::class_<TreeNode, emscripten::base<core::containers::TreeNodeBase>>(classname)
		//.constructor<core::containers::TreeNodeBase, std::string, TreeNodeElementCreateInfo>()
		.function("accept", &TreeNode::accept, emscripten::allow_raw_pointers(), emscripten::pure_virtual())
		.function("addRegion", &TreeNode::addRegion)
		.function("getRegion", &TreeNode::getRegion, emscripten::allow_raw_pointers())
		.function("getRegionNames", &TreeNode::getRegionNames)
		.function("getOwned", &TreeNode::getOwned, emscripten::allow_raw_pointers());
}

TreeNode::TreeNode(core::containers::TreeNodePtr_t parent,
	const core::containers::TreeNodeIndex & nodeIndex,
	const std::string & nodeId, const TreeNodeElementCreateInfo & createInfo)
	: core::containers::TreeNodeBase(parent, nodeIndex, nodeId) {
	_element = new TreeNodeElement(createInfo);
	_element->setTreeNode(this);
}

TreeNode::~TreeNode() {
	SAFE_DELETE(_element);
}

void TreeNode::addRegion(const std::string & name, const RegionCreateInfo & createInfo) {
	_regions.insert(std::make_pair(name,
		std::make_shared<RegionMixin>(getHostTree(), getNodeIndex(), createInfo)));
}

RegionMixinPtr_t TreeNode::getRegion(const std::string & name) const {
	RegionMixinIterator_t iter = _regions.find(name);
	if (iter != _regions.end())
		return iter->second;

	return nullptr;
}

RegionMixinPtr_t TreeNode::getRegionByNodeId(const std::string & nodeId) const {
	for (auto iter = _regions.begin(); iter != _regions.end(); ++iter) {
		RegionMixinPtr_t region = iter->second;
		if (region->getAttachedNodeId() == nodeId)
			return region;
	}

	return nullptr;
}

RegionMixinMap_t TreeNode::getRegions() {
	return _regions;
}

RegionMixinNameVec_t TreeNode::getRegionNames() const {
	RegionMixinNameVec_t keys;
	std::transform(_regions.begin(), _regions.end(), std::back_inserter(keys),
		[](const RegionMixinMap_t::value_type & pair) {
			return pair.first;
		}
	);

	return keys;
}

TreeNodeElement * TreeNode::getOwned() {
	return _element;
}

NAMESPACE_END(base)
NAMESPACE_END(webcore)
NAMESPACE_END(sway)
