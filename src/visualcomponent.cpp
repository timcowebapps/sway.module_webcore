#include <sway/webcore/visualcomponent.h>
#include <sway/webcore/base/treeupdater.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)

void AVisualComponent::registerEmscriptenClass(lpcstr_t classname) {
	emscripten::class_<AVisualComponent, emscripten::base<base::TreeNodeElement>>(classname)
		.constructor<core::containers::HierarchyNodePtr_t,
			core::containers::HierarchyNodeIndex, std::string, base::TreeNodeElementCreateInfo>()
		.function("getModel", &AVisualComponent::getModel, emscripten::allow_raw_pointers())
		.function("setModel", &AVisualComponent::setModel, emscripten::allow_raw_pointers());
}

AVisualComponent::AVisualComponent(core::containers::HierarchyNodePtr_t parent,
	const core::containers::HierarchyNodeIndex & nodeIndex,
	const std::string & nodeId, const base::TreeNodeElementCreateInfo & createInfo)
	: base::TreeNodeElement(parent, nodeIndex, nodeId, createInfo) {
	// Empty
}

void AVisualComponent::accept(base::ITreeVisitor * visitor) {
	visitor->visitOnEnter(this);

	for (core::containers::HierarchyNodePtr_t node : getChildren())
		static_cast<AVisualComponent *>(node)->accept(visitor);
}

void AVisualComponent::initialize() {
	// Empty
}

void AVisualComponent::update() {
	// Empty
}

core::utilities::Observable * AVisualComponent::getModel() {
	return _model;
}

void AVisualComponent::setModel(core::utilities::Observable * model) {
	_model = model;
	_model->registerObserver(this);
}

NAMESPACE_END(webcore)
NAMESPACE_END(sway)
