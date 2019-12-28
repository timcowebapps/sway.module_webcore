#include <sway/webcore/view/itemview.h>
#include <sway/webcore/view/itemviewcomponentwrapper.h>
#include <sway/webcore/base/treeupdater.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)
NAMESPACE_BEGIN(view)

void AItemView::registerEmscriptenClass(lpcstr_t classname) {
	emscripten::class_<AItemView, emscripten::base<base::TreeNodeElement>>(classname)
		.allow_subclass<AItemViewComponentWrapper>("AItemViewComponentWrapper", emscripten::constructor<core::containers::HierarchyNodePtr_t, std::string, base::TreeNodeElementCreateInfo>())
		.constructor<core::containers::HierarchyNodePtr_t, std::string, base::TreeNodeElementCreateInfo>()
		.function("initialize", emscripten::optional_override([](AItemView & self) {
			return self.AItemView::initialize();
		}))
		.function("update", emscripten::optional_override([](AItemView & self) {
			return self.AItemView::update();
		}))
		.function("getModel", &AItemView::getModel, emscripten::allow_raw_pointers())
		.function("setModel", &AItemView::setModel, emscripten::allow_raw_pointers());
}

AItemView::AItemView(core::containers::HierarchyNodePtr_t parent,
	//const core::containers::HierarchyNodeIndex & nodeIndex,
	const std::string & nodeId, const base::TreeNodeElementCreateInfo & createInfo)
	: base::TreeNodeElement(parent, core::containers::HierarchyNodeIndex(), nodeId, createInfo)
	, _model(nullptr) {
	// Empty
}

AItemView::AItemView(core::containers::HierarchyNodePtr_t parent,
	const core::containers::HierarchyNodeIndex & nodeIndex,
	const std::string & nodeId, const base::TreeNodeElementCreateInfo & createInfo)
	: base::TreeNodeElement(parent, nodeIndex, nodeId, createInfo)
	, _model(nullptr) {
	// Empty
}

AItemView::~AItemView() {
	//	Empty
}

void AItemView::accept(base::ITreeVisitor * visitor) {
	visitor->visitOnEnter(this);

	for (core::containers::HierarchyNodePtr_t node : getChildren())
		static_cast<AItemView *>(node)->accept(visitor);
}

void AItemView::initialize() {
	// Empty
}

void AItemView::update() {
	//EM_ASM({console.log("ON_ENTRY_CHANGED " + UTF8ToString($0))}, getNodeId().c_str());
}

core::utilities::Observable * AItemView::getModel() {
	return _model;
}

void AItemView::setModel(core::utilities::Observable * model) {
	_model = model;
	_model->registerObserver(this);
}

NAMESPACE_END(base)
NAMESPACE_END(webcore)
NAMESPACE_END(sway)
