#ifndef _SWAY_WEBCORE_CSS_CNSELECTORDESCRIPTOR_H
#define _SWAY_WEBCORE_CSS_CNSELECTORDESCRIPTOR_H

#include <sway/webcore/css/selectors/cnselectorchain.h>
#include <sway/namespacemacros.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)
NAMESPACE_BEGIN(css)

struct CnSelectorDescriptor {
	bool glob;
	CnSelectorChain chain;

	CnSelectorDescriptor()
		: glob(false)
		, chain(CnSelectorChain()) {
		// Empty
	}
};

NAMESPACE_END(css)
NAMESPACE_END(webcore)
NAMESPACE_END(sway)

#endif // _SWAY_WEBCORE_CSS_CNSELECTORDESCRIPTOR_H
