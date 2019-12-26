#include <sway/webcore/view/advanced/stackview.h>
#include <sway/webcore/base/treeupdater.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)
NAMESPACE_BEGIN(view)
NAMESPACE_BEGIN(advanced)

void StackView::registerEmscriptenClass(lpcstr_t classname) {
	emscripten::class_<StackView, emscripten::base<base::TreeNode>>(classname)
		.constructor<core::containers::TreeNodePtr_t, std::string, base::TreeNodeElementCreateInfo>()
		.function("addItem", &StackView::addItem, emscripten::allow_raw_pointers())
		.function("removeItem", &StackView::removeItem, emscripten::allow_raw_pointers())
		.function("getCurrentItem", &StackView::getCurrentItem)
		.function("setCurrentItem", &StackView::setCurrentItem);
}

StackView::StackView(core::containers::TreeNodePtr_t parent,
	//const core::containers::TreeNodeIndex & nodeIndex,
	const std::string & nodeId, const base::TreeNodeElementCreateInfo & createInfo)
	: base::TreeNode(parent, core::containers::TreeNodeIndex(), nodeId, createInfo) {
	// Empty
}

void StackView::accept(base::ITreeVisitor * visitor) {
	visitor->visit(this);

	for (core::containers::TreeNodePtr_t node : getChildren())
		static_cast<StackView *>(node)->accept(visitor);
}

void StackView::addItem(base::TreeNode * item) {
	item->getOwned()->setVisible(false);
	add(item, std::bind(&StackView::handleItemAdded, this, std::placeholders::_1));
}

void StackView::handleItemAdded(const core::containers::TreeNodeIndex & nodeIndex) {
	EM_ASM({console.log("STACK_VIEW ITEM ADDED")});
}

void StackView::removeItem(base::TreeNode * item) {
	removeChild(item);
}

u32_t StackView::getCurrentItem() {
	return _current;
}

void StackView::setCurrentItem(u32_t nodeIdex) {
	_current = nodeIdex;

	for (core::containers::TreeNodePtr_t child : getChildren())
		static_cast<TreeNode *>(child)->getOwned()->setVisible(false);

	TreeNode * item = getChildAt<TreeNode *>(nodeIdex);
	item->getOwned()->setVisible(true);

	for (core::containers::TreeListener * listener : getHostTree()->getListeners())
		listener->onNodeUpdated(item);
}

NAMESPACE_END(advanced)
NAMESPACE_END(view)
NAMESPACE_END(webcore)
NAMESPACE_END(sway)
