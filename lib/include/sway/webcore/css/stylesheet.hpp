#ifndef SWAY_WEBCORE_CSS_STYLESHEET_HPP
#define SWAY_WEBCORE_CSS_STYLESHEET_HPP

#include <sway/emscriptenmacros.hpp>
#include <sway/webcore/prereqs.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)

#ifdef EMSCRIPTEN_PLATFORM
class EmscriptenUtil {
public:
  static bool isNone(emscripten::val const &val) { return val.isNull() || val.isUndefined(); }
};
#endif

NAMESPACE_BEGIN(css)

#ifdef EMSCRIPTEN_PLATFORM
using Mapper_t = emscripten::val;
#else
using Mapper_t = std::map<std::string, std::string>;
#endif

class StyleSheet {
public:
  DECLARE_EMSCRIPTEN_BINDING()

  StyleSheet(const Mapper_t &mapper);

  ~StyleSheet() = default;

  [[nodiscard]] auto getClassName(const std::string &classnameKey) const -> std::string;

private:
  Mapper_t mapper_;
};

NAMESPACE_END(css)
NAMESPACE_END(webcore)
NAMESPACE_END(sway)

#endif
