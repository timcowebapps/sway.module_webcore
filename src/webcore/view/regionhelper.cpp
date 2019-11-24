#include <sway/webcore/view/regionhelper.h>
#include <sway/webcore/view/regionoptions.h>
#include <sway/webcore/view/region.h>
#include <sway/webcore/view/viewcomponent.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)
NAMESPACE_BEGIN(view)

void RegionHelper::registerClassOptions(lpcstr_t name) {
	emscripten::value_object<RegionOptions>(name)
		.field("elementId", &RegionOptions::elementId)
		.field("replace", &RegionOptions::replace);
}

void RegionHelper::registerClass(lpcstr_t name) {
	emscripten::class_<Region>(name)
		.constructor<RegionOptions>()
		.smart_ptr<RegionPtr_t>(core::misc::format("shared_ptr<%s>", name).c_str())
		.class_function("create", &Region::create)
		.property("element", &Region::getElement)
		.function("attachView", &Region::attachView, emscripten::allow_raw_pointers())
		.function("detachView", &Region::detachView, emscripten::allow_raw_pointers());
}

NAMESPACE_END(view)
NAMESPACE_END(webcore)
NAMESPACE_END(sway)
