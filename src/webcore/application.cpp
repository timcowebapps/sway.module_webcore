#include <sway/webcore/application.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)

Application::Application(const std::string & elementId) {
	_treeUpdater = new base::TreeUpdater();
	_tree = new core::containers::Tree();
	_tree->attachListener(this);
	_tree->setRootNode(
		_root = new view::AItemView(nullptr, core::containers::TreeNodeIndex({ 0 }), elementId,
			(base::TreeNodeElementCreateInfo) {
				.tagname = "div",
				.id = elementId
			}
		)
	);
}

Application::~Application() {
	SAFE_DELETE(_root);
	SAFE_DELETE(_tree);
	SAFE_DELETE(_treeUpdater);
}

void Application::onNodeUpdated(core::containers::TreeNodePtr_t child) {
	base::TreeNode * element = (base::TreeNode *) child;
	EM_ASM({console.log("NODE_UPDATE_ID " + UTF8ToString($0))}, child->getNodeId().c_str());

	if (element)
		element->accept(_treeUpdater);

	_treeUpdater->forceUpdate();
}

void Application::onNodeAdded(const core::containers::TreeNodeIndex & nodeIndex) {
	base::TreeNode * element = (base::TreeNode *) _tree->find(nodeIndex.getParent());
	EM_ASM({console.log("_NODE_ID " + UTF8ToString($0))}, nodeIndex.toString().c_str());

	if (element)
		element->accept(_treeUpdater);

	_treeUpdater->forceUpdate();
}

void Application::onNodeRemoved(core::containers::TreeNodePtr_t parent, core::containers::TreeNodePtr_t child) {
	// Empty
}

base::TreeNode * Application::getRoot() {
	return _root;
}

NAMESPACE_END(webcore)
NAMESPACE_END(sway)
