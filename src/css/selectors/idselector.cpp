#include <sway/webcore/css/selectors/idselector.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)
NAMESPACE_BEGIN(css)

void IdSelector::registerEmscriptenClass(lpcstr_t classname) {
	emscripten::class_<IdSelector, emscripten::base<Selector>>(classname)
		.constructor<std::string>();
}

IdSelector::IdSelector(const std::string & name) : Selector(SelectorTypes_t::kId) {
	setName(name);
}

NAMESPACE_END(css)
NAMESPACE_END(webcore)
NAMESPACE_END(sway)
