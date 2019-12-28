#ifndef _SWAY_WEBCORE_VIEW_AITEMCOLLECTIONVIEWCOMPONENTWRAPPER_H
#define _SWAY_WEBCORE_VIEW_AITEMCOLLECTIONVIEWCOMPONENTWRAPPER_H

#include <sway/webcore/view/itemcollectionview.h>
#include <sway/webcore/prereqs.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)
NAMESPACE_BEGIN(view)

class AItemCollectionViewComponentWrapper : public emscripten::wrapper<AItemCollectionView> {
public:
	EMSCRIPTEN_WRAPPER(AItemCollectionViewComponentWrapper)

	void initialize();
	void update();
};

NAMESPACE_END(view)
NAMESPACE_END(webcore)
NAMESPACE_END(sway)

#endif // _SWAY_WEBCORE_VIEW_AITEMCOLLECTIONVIEWCOMPONENTWRAPPER_H
