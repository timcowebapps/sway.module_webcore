#include <sway/webcore/css/stylesheet.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)
NAMESPACE_BEGIN(css)

EMSCRIPTEN_BINDING_BEGIN(StyleSheet)
#ifdef EMSCRIPTEN_PLATFORM
emscripten::class_<StyleSheet>("StyleSheet")
    .constructor<emscripten::val>()
    .function("getClassName", &StyleSheet::getClassName);
#endif
EMSCRIPTEN_BINDING_END()

StyleSheet::StyleSheet(const Mapper_t &mapper)
    : mapper_(std::move(mapper)) {}

auto StyleSheet::getClassName(const std::string &classnameKey) const -> std::string {
  auto mpr = mapper_;
  auto key = classnameKey.c_str();

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
