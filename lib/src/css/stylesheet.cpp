#include <sway/webcore/css/stylesheet.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)
NAMESPACE_BEGIN(css)

void StyleSheet::registerEmClass() {
#ifdef EMSCRIPTEN_PLATFORM
  emscripten::class_<StyleSheet>("StyleSheet")
      .constructor<emscripten::val>()
      .function("getClassName", &StyleSheet::getClassName);
#endif
}

StyleSheet::StyleSheet(const Mapper_t &mapper)
    : mapper_(std::move(mapper)) {}

std::string StyleSheet::getClassName(const std::string &classnameKey) const {
  auto mpr = mapper_;
  lpcstr_t key = classnameKey.c_str();

#ifdef EMSCRIPTEN_PLATFORM
  if (EmscriptenUtil::isNone(mpr) || EmscriptenUtil::isNone(mpr[key])) {
    EM_ASM({ console.warn("'" + UTF8ToString($0) + "' must be not null"); }, key);
    return "";
  }

  return mpr[key].as<std::string>();
#else
  return mpr[key];
#endif
}

NAMESPACE_END(css)
NAMESPACE_END(webcore)
NAMESPACE_END(sway)
