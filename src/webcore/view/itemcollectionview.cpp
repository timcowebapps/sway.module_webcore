#include <sway/webcore/view/itemcollectionview.h>
#include <sway/webcore/view/itemcollectionviewcomponentwrapper.h>
#include <sway/webcore/view/itemview.h>
#include <sway/webcore/base/treeupdater.h>
#include <sway/webcore/model/abstractitemmodel.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)
NAMESPACE_BEGIN(view)

void AItemCollectionView::registerEmscriptenClass(lpcstr_t classname) {
	emscripten::class_<AItemCollectionView, emscripten::base<base::TreeNode>>(classname)
		.allow_subclass<AItemCollectionViewComponentWrapper>("AItemCollectionViewComponentWrapper", emscripten::constructor<core::containers::TreeNodePtr_t, std::string, base::TreeNodeElementCreateInfo>())
		.constructor<core::containers::TreeNodePtr_t, std::string, base::TreeNodeElementCreateInfo>()
		.function("initialize", emscripten::optional_override([](AItemCollectionView & self) {
			return self.AItemCollectionView::initialize();
		}))
		.function("onDataChanged", emscripten::optional_override([](AItemCollectionView & self) {
			return self.AItemCollectionView::onDataChanged();
		}))
		.function("makeItem", &AItemCollectionView::makeItem, emscripten::allow_raw_pointers())
		.function("getModel", &AItemCollectionView::getModel, emscripten::allow_raw_pointers())
		.function("setModel", &AItemCollectionView::setModel, emscripten::allow_raw_pointers());
}

AItemCollectionView::AItemCollectionView(core::containers::TreeNodePtr_t parent,
	//const core::containers::TreeNodeIndex & nodeIndex,
	const std::string & nodeId, const base::TreeNodeElementCreateInfo & createInfo)
	: base::TreeNode(parent, core::containers::TreeNodeIndex(), nodeId, createInfo)
	, _model(nullptr) {
	// Empty
}

void AItemCollectionView::initialize() {
	// Empty
}

void AItemCollectionView::onDataChanged() {
	// Empty
}

void AItemCollectionView::makeItem(u32_t index, base::TreeNode * child) {
	auto collection = static_cast<model::AbstractItemCollection *>(getModel());
	auto item = static_cast<AItemView *>(child);
	item->setNodeId(core::misc::format("%s_%i", item->getNodeId().c_str(), index));
	item->setModel(collection->getItem(index));
	item->initialize();
	addChild(item);
}

void AItemCollectionView::accept(base::ITreeVisitor * visitor) {
	visitor->visit(this);
	for (core::containers::TreeNodePtr_t node : getChildren())
		static_cast<AItemCollectionView *>(node)->accept(visitor);
}

model::Observable * AItemCollectionView::getModel() {
	return _model;
}

void AItemCollectionView::setModel(model::Observable * model) {
	_model = model;
	_model->registerObserver(this);
}

NAMESPACE_END(view)
NAMESPACE_END(webcore)
NAMESPACE_END(sway)
