#include <sway/webcore/model/abstractmodelhelper.h>
#include <sway/webcore/model/abstractmodel.h>
#include <sway/webcore/model/observable.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)
NAMESPACE_BEGIN(model)

void AbstractModelHelper::registerClass(lpcstr_t classname) {
	emscripten::class_<AbstractModel, emscripten::base<Observable>>(classname)
		.constructor()
		.smart_ptr<ModelSmartPtr_t>(core::misc::format("shared_ptr<%s>", classname).c_str())
		.class_function("create", &AbstractModel::create)
		.function("getProps", &AbstractModel::getProps)
		.function("setProp", &AbstractModel::setProp);
}

NAMESPACE_END(model)
NAMESPACE_END(webcore)
NAMESPACE_END(sway)
