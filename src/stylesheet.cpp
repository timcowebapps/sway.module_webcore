#include <sway/webcore/stylesheet.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)

StyleSheet::StyleSheet(const emscripten::val & mapper)
	: _mapper(mapper) {
	// Empty
}

std::string StyleSheet::getClassName(lpcstr_t style) const {
	if (EmscriptenUtil::isNone(_mapper) || EmscriptenUtil::isNone(_mapper[style]))
		return "";

	return _mapper[style].as<std::string>();
}

NAMESPACE_END(webcore)
NAMESPACE_END(sway)
