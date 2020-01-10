#include <sway/webcore/css/stylesheet.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)
NAMESPACE_BEGIN(css)

void StyleSheet::registerEmscriptenClass(lpcstr_t classname) {
	emscripten::class_<StyleSheet>(classname)
		.constructor<emscripten::val>()
		.function("getClassName", &StyleSheet::getClassName);
}

StyleSheet::StyleSheet(const emscripten::val & mapper)
	: _mapper(mapper) {
	// Empty
}

std::string StyleSheet::getClassName(const std::string & classnameKey) const {
	if (EmscriptenUtil::isNone(_mapper) || EmscriptenUtil::isNone(_mapper[classnameKey.c_str()])) {
		EM_ASM({console.warn("'" + UTF8ToString($0) + "' must be not null")}, classnameKey.c_str());
		return "";
	}

	return _mapper[classnameKey.c_str()].as<std::string>();
}

NAMESPACE_END(css)
NAMESPACE_END(webcore)
NAMESPACE_END(sway)
