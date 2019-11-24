#ifndef _SWAY_WEBCORE_MODEL_ABSTRACTLISTMODELHELPER_H
#define _SWAY_WEBCORE_MODEL_ABSTRACTLISTMODELHELPER_H

#include <sway/webcore/prereqs.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)
NAMESPACE_BEGIN(model)

class AbstractListModelHelper {
public:
	static void registerClass(lpcstr_t classname);
};

NAMESPACE_END(model)
NAMESPACE_END(webcore)
NAMESPACE_END(sway)

#endif // _SWAY_WEBCORE_MODEL_ABSTRACTLISTMODELHELPER_H
