#include <sway/webcore/control/layout.h>
#include <sway/webcore/base/treeupdater.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)
NAMESPACE_BEGIN(control)

void Layout::registerEmscriptenClass(lpcstr_t classname) {
	emscripten::class_<Layout, emscripten::base<base::TreeNodeElement>>(classname)
		.constructor<core::containers::HierarchyNodePtr_t, std::string, base::TreeNodeElementCreateInfo>();
}

Layout::Layout(core::containers::HierarchyNodePtr_t parent,
	const std::string & nodeId, const base::TreeNodeElementCreateInfo & createInfo)
	: base::TreeNodeElement(parent, core::containers::HierarchyNodeIndex(), nodeId, createInfo) {
	// Empty
}

NAMESPACE_END(control)
NAMESPACE_END(webcore)
NAMESPACE_END(sway)