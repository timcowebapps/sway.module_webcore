#include <sway/webcore/view/itemview.h>
#include <sway/webcore/view/itemviewcomponentwrapper.h>
#include <sway/webcore/base/treeupdater.h>
#include <sway/webcore/model/observable.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)
NAMESPACE_BEGIN(view)

void AItemView::registerEmscriptenClass(lpcstr_t classname) {
	emscripten::class_<AItemView, emscripten::base<base::TreeNode>>(classname)
		.allow_subclass<AItemViewComponentWrapper>("AItemViewComponentWrapper", emscripten::constructor<core::containers::TreeNodePtr_t, std::string, base::TreeNodeElementCreateInfo>())
		.constructor<core::containers::TreeNodePtr_t, std::string, base::TreeNodeElementCreateInfo>()
		.function("initialize", emscripten::optional_override([](AItemView & self) {
			return self.AItemView::initialize();
		}))
		.function("onDataChanged", emscripten::optional_override([](AItemView & self) {
			return self.AItemView::onDataChanged();
		}))
		.function("getModel", &AItemView::getModel, emscripten::allow_raw_pointers())
		.function("setModel", &AItemView::setModel, emscripten::allow_raw_pointers());
}

AItemView::AItemView(core::containers::TreeNodePtr_t parent,
	//const core::containers::TreeNodeIndex & nodeIndex,
	const std::string & nodeId, const base::TreeNodeElementCreateInfo & createInfo)
	: base::TreeNode(parent, core::containers::TreeNodeIndex(), nodeId, createInfo)
	, _model(nullptr) {
	// Empty
}

AItemView::AItemView(core::containers::TreeNodePtr_t parent,
	const core::containers::TreeNodeIndex & nodeIndex,
	const std::string & nodeId, const base::TreeNodeElementCreateInfo & createInfo)
	: base::TreeNode(parent, nodeIndex, nodeId, createInfo)
	, _model(nullptr) {
	// Empty
}

AItemView::~AItemView() {
	//	Empty
}

void AItemView::accept(base::ITreeVisitor * visitor) {
	visitor->visit(this);
	for (core::containers::TreeNodePtr_t node : getChildren())
		static_cast<AItemView *>(node)->accept(visitor);
}

void AItemView::initialize() {
	// Empty
}

void AItemView::onDataChanged() {
	//EM_ASM({console.log("ON_ENTRY_CHANGED " + UTF8ToString($0))}, getNodeId().c_str());
}

model::Observable * AItemView::getModel() {
	return _model;
}

void AItemView::setModel(model::Observable * model) {
	_model = model;
	_model->registerObserver(this);
}

NAMESPACE_END(base)
NAMESPACE_END(webcore)
NAMESPACE_END(sway)
