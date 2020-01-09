#ifndef _SWAY_WEBCORE_CSS_CNSELECTORCHAIN_H
#define _SWAY_WEBCORE_CSS_CNSELECTORCHAIN_H

#include <sway/webcore/prereqs.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)
NAMESPACE_BEGIN(css)

struct CnSelectorChain {
	std::string block;
	std::string elem;
	emscripten::val mods;

	CnSelectorChain(std::string block = "", std::string elem = "")
		: block(block)
		, elem(elem)
		, mods(emscripten::val::null()) {
		// Empty
	}
};

NAMESPACE_END(css)
NAMESPACE_END(webcore)
NAMESPACE_END(sway)

#endif // _SWAY_WEBCORE_CSS_CNSELECTORCHAIN_H
