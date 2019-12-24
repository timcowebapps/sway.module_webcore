#include <sway/webcore.h>
#include <sway/webcore/model/abstractitemmodel.h>
#include <sway/webcore/model/abstractitemcollection.h>
#include <sway/webcore/router/router.h>

#include <sway/webcore/base/region.h>
#include <sway/webcore/base/treenodeelement.h>
#include <sway/webcore/base/treenode.h>
#include <sway/webcore/view/itemview.h>
#include <sway/webcore/view/itemcollectionview.h>
#include <sway/webcore/view/advanced/stackview.h>
#include <sway/webcore/base/treeupdater.h>
#include <sway/webcore/application.h>

using namespace sway;
using namespace sway::webcore;

EMSCRIPTEN_BINDINGS(vector) {
	emscripten::register_vector<emscripten::val>("VectorVal");
	emscripten::register_vector<std::string>("VectorString");
	emscripten::register_vector<int>("VectorInt");
} // vector

EMSCRIPTEN_BINDINGS(event_types) {
	emscripten::enum_<EventTypes_t>("EventTypes_t")
		.value("kClick", EventTypes_t::kClick)
		.value("kMouseOver", EventTypes_t::kMouseOver)
		.value("kMouseOut", EventTypes_t::kMouseOut);
} // event_types

EMSCRIPTEN_BINDINGS(event_listener) {
	emscripten::class_<EventListener>("EventListener")
		.function<void>("handleEvent", &EventListener::handleEvent);
} // event_listener

EMSCRIPTEN_BINDINGS(models) {
	emscripten::class_<model::Observable>("Observable")
		.constructor()
		.function("registerObserver", &model::Observable::registerObserver, emscripten::allow_raw_pointers())
		.function("notifyPropertyChanged", &model::Observable::notifyPropertyChanged);

	model::AbstractItemModel::registerEmscriptenClass("AbstractItemModel");
	model::AbstractItemCollection::registerEmscriptenClass("AbstractItemCollection");
} // models

EMSCRIPTEN_BINDINGS(views) {
	emscripten::class_<core::containers::TreeListener>("TreeListener")
		.function("onNodeAdded", &core::containers::TreeListener::onNodeAdded, emscripten::allow_raw_pointers())
		.function("onNodeRemoved", &core::containers::TreeListener::onNodeRemoved, emscripten::allow_raw_pointers());

	emscripten::class_<core::containers::Tree>("Tree")
		.constructor()
		.function("attachListener", &core::containers::Tree::attachListener, emscripten::allow_raw_pointers())
		.function("detachListener", &core::containers::Tree::detachListener, emscripten::allow_raw_pointers())
		.function("getRootNode", &core::containers::Tree::getRootNode, emscripten::allow_raw_pointers())
		.function("setRootNode", &core::containers::Tree::setRootNode, emscripten::allow_raw_pointers())
		.function("getListeners", &core::containers::Tree::getListeners, emscripten::allow_raw_pointers());

	emscripten::class_<core::containers::TreeNodeIndex>("TreeNodeIndex")
		.constructor<std::vector<s32_t>>()
		.constructor<core::containers::TreeNodeIndex, s32_t>()
		.function("getParent", &core::containers::TreeNodeIndex::getParent, emscripten::allow_raw_pointers())
		.function("getDepth", &core::containers::TreeNodeIndex::getDepth)
		.function("isValid", &core::containers::TreeNodeIndex::isValid)
		.function("toString", &core::containers::TreeNodeIndex::toString);

	emscripten::class_<core::containers::TreeNodeBase>("TreeNodeBase")
		.constructor<core::containers::TreeNodePtr_t, core::containers::TreeNodeIndex, std::string>()
		.function("addChild", &core::containers::TreeNodeBase::addChild, emscripten::allow_raw_pointers())
		.function("findChild", &core::containers::TreeNodeBase::findChild, emscripten::allow_raw_pointers())
		.function("getChild", &core::containers::TreeNodeBase::getChild, emscripten::allow_raw_pointers())
		.function("hasChild", &core::containers::TreeNodeBase::hasChild)
		.function("getParentNode", &core::containers::TreeNodeBase::getParentNode, emscripten::allow_raw_pointers())
		.function("setParentNode", &core::containers::TreeNodeBase::setParentNode, emscripten::allow_raw_pointers())
		.function("getNodeId", &core::containers::TreeNodeBase::getNodeId)
		.function("setNodeId", &core::containers::TreeNodeBase::setNodeId);

	emscripten::class_<base::ITreeVisitor>("ITreeVisitor")
		.function("visit", &base::ITreeVisitor::visit, emscripten::allow_raw_pointers());

	emscripten::class_<base::TreeUpdater, emscripten::base<base::ITreeVisitor>>("TreeUpdater")
		.constructor()
		.function("forceUpdate", &base::TreeUpdater::forceUpdate);

	emscripten::value_object<base::TreeNodeElementCreateInfo>("TreeNodeElementCreateInfo")
		.field("tagname", &base::TreeNodeElementCreateInfo::tagname)
		.field("id", &base::TreeNodeElementCreateInfo::id);

	emscripten::value_object<base::RegionCreateInfo>("RegionCreateInfo")
		.field("id", &base::RegionCreateInfo::id)
		.field("replace", &base::RegionCreateInfo::replace);

	base::RegionMixin::registerEmscriptenClass("RegionMixin");
	base::TreeNodeElement::registerEmscriptenClass("TreeNodeElement");
	base::TreeNode::registerEmscriptenClass("TreeNode");
	view::AItemView::registerEmscriptenClass("AItemView");
	view::AItemCollectionView::registerEmscriptenClass("AItemCollectionView");
	view::advanced::StackView::registerEmscriptenClass("StackView");
} // views

EMSCRIPTEN_BINDINGS(controllers) {
	emscripten::class_<controller::AbstractController>("AbstractController")
		.constructor<model::AbstractItemModel *>()
		.function("getModel", &controller::AbstractController::getModel, emscripten::allow_raw_pointers());
} // controllers

EMSCRIPTEN_BINDINGS(router) {
	router::Router::registerEmscriptenClass("Router");
} // router

EMSCRIPTEN_BINDINGS(application) {
	emscripten::class_<Application>("Application")
		.constructor<std::string>()
		.function("getRoot", &Application::getRoot, emscripten::allow_raw_pointers());
} // application

int main() {
	printf("Starting...\n");
}
