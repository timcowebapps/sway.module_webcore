#include <sway/webcore/model/abstractlistmodelhelper.h>
#include <sway/webcore/model/abstractlistmodel.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)
NAMESPACE_BEGIN(model)

void AbstractListModelHelper::registerClass(lpcstr_t classname) {
	emscripten::class_<AbstractListModel>(classname)
		.constructor()
		.function("getItems", &AbstractListModel::getItems)
		.function("setItem", &AbstractListModel::setItem);
}

NAMESPACE_END(model)
NAMESPACE_END(webcore)
NAMESPACE_END(sway)
