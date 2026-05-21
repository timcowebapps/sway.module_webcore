#include <sway/webcore/css/stylesheet.hpp>

namespace sway::webcore {

EMSCRIPTEN_BINDING_BEGIN(StyleSheet)
emscripten::class_<StyleSheet>("StyleSheet")
    .constructor<emscripten::val>()
    .function("getClassName", &StyleSheet::getClassName);
EMSCRIPTEN_BINDING_END()

StyleSheet::StyleSheet(const Mapper_t &mapper)
    : mapper_(std::move(mapper)) {}

auto StyleSheet::getClassName(const std::string &classnameKey) const -> std::string {
  auto mpr = mapper_;
  auto key = classnameKey.c_str();

  if (EmscriptenUtil::isNone(mpr) || EmscriptenUtil::isNone(mpr[key])) {
    EM_ASM({ console.warn("'" + UTF8ToString($0) + "' must be not null"); }, key);
    return "";
  }

  return mpr[key].as<std::string>();
}

}  // namespace sway::webcore
