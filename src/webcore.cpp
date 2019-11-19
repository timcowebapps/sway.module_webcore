#include <sway/webcore.h>

using namespace sway::webcore;

EMSCRIPTEN_BINDINGS(event_listener) {
	emscripten::class_<EventListener>("EventListener")
		.function<void>("handleEvent", &EventListener::handleEvent);
}

EMSCRIPTEN_BINDINGS(view) {
	emscripten::class_<mvc::view::TViewHierarchy<mvc::model::AbstractModel>>("THierarchy<val>")
		.constructor<std::string>()
		.function("getParent", &mvc::view::TViewHierarchy<mvc::model::AbstractModel>::getParent, emscripten::allow_raw_pointers())
		.function("setParent", &mvc::view::TViewHierarchy<mvc::model::AbstractModel>::setParent, emscripten::allow_raw_pointers())
		.function("addChild", &mvc::view::TViewHierarchy<mvc::model::AbstractModel>::addChild, emscripten::allow_raw_pointers())
		.function("removeChild", &mvc::view::TViewHierarchy<mvc::model::AbstractModel>::removeChild, emscripten::allow_raw_pointers())
		.function("findChild", &mvc::view::TViewHierarchy<mvc::model::AbstractModel>::findChild, emscripten::allow_raw_pointers());

	emscripten::class_<mvc::view::TAbstractView<mvc::model::AbstractModel>, emscripten::base<mvc::view::TViewHierarchy<mvc::model::AbstractModel>>>("TAbstractView<val>")
		.constructor<std::string>()
		.function("update", &mvc::view::TAbstractView<mvc::model::AbstractModel>::update)
		.function("getModel", &mvc::view::TAbstractView<mvc::model::AbstractModel>::getModel, emscripten::allow_raw_pointers())
		.function("setModel", &mvc::view::TAbstractView<mvc::model::AbstractModel>::setModel, emscripten::allow_raw_pointers());

	emscripten::class_<mvc::view::ViewComponent, emscripten::base<mvc::view::TAbstractView<mvc::model::AbstractModel>>>("ViewComponent")
		.property("name", &mvc::view::ViewComponent::getName)
		.allow_subclass<mvc::view::ViewComponentWrapper>("ViewComponentWrapper", emscripten::constructor<const std::string &, const mvc::view::ViewComponentOptions &>())
		.function("getElement", &mvc::view::ViewComponent::getElement)
		.function("getRegion", &mvc::view::ViewComponent::getRegion)
		.function("setRegion", &mvc::view::ViewComponent::setRegion)
		.function("addEvent", &mvc::view::ViewComponent::addEvent, emscripten::allow_raw_pointers());
}

EMSCRIPTEN_BINDINGS(jsbindings) {
	emscripten::register_vector<std::string>("vector<string>");

	emscripten::enum_<EventTypes_t>("EventTypes_t")
		.value("kClick", EventTypes_t::kClick)
		.value("kMouseOver", EventTypes_t::kMouseOver)
		.value("kMouseOut", EventTypes_t::kMouseOut);

	emscripten::class_<Application>("Application")
		.constructor<std::string, mvc::view::ViewComponent *>()
		.function("start", &Application::start);

	emscripten::class_<mvc::model::Observable>("Observable")
		.constructor()
		.function("addObserver", &mvc::model::Observable::addObserver, emscripten::allow_raw_pointers())
		.function("notify", &mvc::model::Observable::notify);

	emscripten::class_<mvc::model::AbstractModel, emscripten::base<mvc::model::Observable>>("AbstractModel")
		.constructor()
		.smart_ptr<mvc::model::ModelSmartPtr_t>("shared_ptr<Model>")
		.class_function("create", &mvc::model::AbstractModel::create)
		.function("getProperties", &mvc::model::AbstractModel::getProperties)
		.function("setProperty", &mvc::model::AbstractModel::setProperty);

	emscripten::value_object<mvc::view::RegionOptions>("RegionOptions")
		.field("elementId", &mvc::view::RegionOptions::elementId)
		.field("replace", &mvc::view::RegionOptions::replace);

	emscripten::class_<mvc::view::Region>("Region")
		.constructor<mvc::view::RegionOptions>()
		.smart_ptr<mvc::view::RegionPtr_t>("shared_ptr<Region>")
		.class_function("create", &mvc::view::Region::create)
		.property("element", &mvc::view::Region::getElement)
		.function("attachView", &mvc::view::Region::attachView, emscripten::allow_raw_pointers())
		.function("detachView", &mvc::view::Region::detachView, emscripten::allow_raw_pointers());

	emscripten::value_object<mvc::view::ViewComponentOptions>("ViewComponentOptions")
		.field("id", &mvc::view::ViewComponentOptions::id)
		.field("tagname", &mvc::view::ViewComponentOptions::tagname)
		.field("classname", &mvc::view::ViewComponentOptions::classname)
		.field("htmlString", &mvc::view::ViewComponentOptions::htmlString);

	emscripten::class_<mvc::controller::AbstractController>("AbstractController")
		//.constructor<mvc::model::ModelSmartPtr_t>()
		.constructor<mvc::model::AbstractModel *>()
		.function("getModel", &mvc::controller::AbstractController::getModel, emscripten::allow_raw_pointers());
		//.function("getModel", &mvc::controller::AbstractController::getModel);
} // EMSCRIPTEN_BINDINGS

int main() {
	printf("Starting...\n");
}
