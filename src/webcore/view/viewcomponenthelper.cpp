#include <sway/webcore/view/viewcomponenthelper.h>
#include <sway/webcore/view/viewcomponent.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)
NAMESPACE_BEGIN(view)

void ViewComponentHelper::registerClassOptions(lpcstr_t name) {
	emscripten::value_object<ViewComponentOptions>(name)
		.field("id", &ViewComponentOptions::id)
		.field("tagname", &ViewComponentOptions::tagname)
		.field("classname", &ViewComponentOptions::classname)
		.field("htmlString", &ViewComponentOptions::htmlString);
}

void ViewComponentHelper::registerClass(lpcstr_t name) {
	emscripten::class_<TViewHierarchy<model::AbstractModel>>("THierarchy<val>")
		.constructor<std::string>()
		.function("addChild", &TViewHierarchy<model::AbstractModel>::addChild, emscripten::allow_raw_pointers())
		.function("removeChild", &TViewHierarchy<model::AbstractModel>::removeChild, emscripten::allow_raw_pointers())
		.function("findChild", &TViewHierarchy<model::AbstractModel>::findChild, emscripten::allow_raw_pointers())
		.function("getChildCount", &TViewHierarchy<model::AbstractModel>::getChildCount)
		.function("getParent", &TViewHierarchy<model::AbstractModel>::getParent, emscripten::allow_raw_pointers())
		.function("setParent", &TViewHierarchy<model::AbstractModel>::setParent, emscripten::allow_raw_pointers())
		.function("getName", &TViewHierarchy<model::AbstractModel>::getName)
		.function("setName", &TViewHierarchy<model::AbstractModel>::setName);

	emscripten::class_<TAbstractView<model::AbstractModel>, emscripten::base<TViewHierarchy<model::AbstractModel>>>("TAbstractView<val>")
		.constructor<std::string>()
		.function("update", &TAbstractView<model::AbstractModel>::update)
		.function("getModel", &TAbstractView<model::AbstractModel>::getModel, emscripten::allow_raw_pointers())
		.function("setModel", &TAbstractView<model::AbstractModel>::setModel, emscripten::allow_raw_pointers());

	emscripten::class_<ViewComponent, emscripten::base<TAbstractView<model::AbstractModel>>>("ViewComponent")
		.property("name", &ViewComponent::getName)
		.allow_subclass<ViewComponentWrapper>("ViewComponentWrapper", emscripten::constructor<std::string, ViewComponentOptions>())
		.function("prerepaint", emscripten::optional_override([](ViewComponent & self) {
			return self.ViewComponent::prerepaint();
		}))
		.function("update", &ViewComponent::update)
		.function("repaint", &ViewComponent::repaint)
		.function("buildTemplate", &ViewComponent::buildTemplate)
		.function("getElement", &ViewComponent::getElement)
		.function("addRegion", &ViewComponent::addRegion)
		.function("getRegion", &ViewComponent::getRegion, emscripten::allow_raw_pointers())
		.function("getRegionNames", &ViewComponent::getRegionNames)
		.function("addChildView", &ViewComponent::addChildView, emscripten::allow_raw_pointers())
		.function("removeChildView", &ViewComponent::removeChildView, emscripten::allow_raw_pointers())
		.function("addEvent", &ViewComponent::addEvent, emscripten::allow_raw_pointers());
}

NAMESPACE_END(view)
NAMESPACE_END(webcore)
NAMESPACE_END(sway)
