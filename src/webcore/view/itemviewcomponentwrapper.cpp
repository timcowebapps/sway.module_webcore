#include <sway/webcore/view/itemviewcomponentwrapper.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)
NAMESPACE_BEGIN(view)

void AItemViewComponentWrapper::initialize() {
	return call<void>("initialize");
}

void AItemViewComponentWrapper::onDataChanged() {
	return call<void>("onDataChanged");
}

NAMESPACE_END(view)
NAMESPACE_END(webcore)
NAMESPACE_END(sway)
