#include <sway/webcore.h>
#include <sway/webcore/model/abstractmodelhelper.h>
#include <sway/webcore/model/abstractlistmodelhelper.h>
#include <sway/webcore/view/viewcomponenthelper.h>
#include <sway/webcore/view/regionhelper.h>
#include <sway/webcore/router/routerhelper.h>

using namespace sway::webcore;

EMSCRIPTEN_BINDINGS(event_listener) {
	emscripten::class_<EventListener>("EventListener")
		.function<void>("handleEvent", &EventListener::handleEvent);
}

EMSCRIPTEN_BINDINGS(jsbindings) {
	emscripten::register_vector<std::string>("vector<string>");

	emscripten::enum_<EventTypes_t>("EventTypes_t")
		.value("kClick", EventTypes_t::kClick)
		.value("kMouseOver", EventTypes_t::kMouseOver)
		.value("kMouseOut", EventTypes_t::kMouseOut);

	emscripten::class_<Application>("Application")
		.constructor<std::string, view::ViewComponent *>()
		.function("start", &Application::start);

	emscripten::class_<model::Observable>("Observable")
		.constructor()
		.function("addObserver", &model::Observable::addObserver, emscripten::allow_raw_pointers())
		.function("notify", &model::Observable::notify);

	model::AbstractModelHelper::registerClass("AbstractModel");
	model::AbstractListModelHelper::registerClass("AbstractListModel");
	view::ViewComponentHelper::registerClassOptions("ViewComponentOptions");
	view::ViewComponentHelper::registerClass("ViewComponent");
	view::RegionHelper::registerClassOptions("RegionOptions");
	view::RegionHelper::registerClass("Region");
	router::RouterHelper::registerClass("Router");


	emscripten::class_<controller::AbstractController>("AbstractController")
		.constructor<model::AbstractModel *>()
		.function("getModel", &controller::AbstractController::getModel, emscripten::allow_raw_pointers());
} // EMSCRIPTEN_BINDINGS

int main() {
	printf("Starting...\n");
}
