#include <sway/webcore/view/advanced/layoutelement.h>
#include <sway/webcore/base/treeupdater.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)
NAMESPACE_BEGIN(view)
NAMESPACE_BEGIN(advanced)

void LayoutElement::registerEmscriptenClass(lpcstr_t classname) {
	emscripten::class_<LayoutElement, emscripten::base<base::TreeNodeElement>>(classname)
		.constructor<base::TreeNodeElementCreateInfo>();
}

LayoutElement::LayoutElement(const base::TreeNodeElementCreateInfo & createInfo)
	: base::TreeNodeElement(createInfo) {
	// Empty
}

NAMESPACE_END(advanced)
NAMESPACE_END(view)
NAMESPACE_END(webcore)
NAMESPACE_END(sway)
