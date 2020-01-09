#include <sway/webcore/css/selectors/cnselector.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)
NAMESPACE_BEGIN(css)

CnSelector::CnSelector(const CnSelectorChain & chain) : Selector(SelectorTypes_t::kCn)
	, _chain(chain) {

	std::string name = _chain.elem.empty()
		? _chain.block
		: _chain.block + "__" + _chain.elem;

	setName(name);
}

std::vector<std::string> CnSelector::getMods() const {
	return emscripten::vecFromJSArray<std::string>(_chain.mods);
}

NAMESPACE_END(css)
NAMESPACE_END(webcore)
NAMESPACE_END(sway)
