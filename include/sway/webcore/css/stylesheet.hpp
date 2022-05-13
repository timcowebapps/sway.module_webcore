#ifndef SWAY_WEBCORE_CSS_STYLESHEET_HPP
#define SWAY_WEBCORE_CSS_STYLESHEET_HPP

#include <sway/webcore/prereqs.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)

#ifdef _EMSCRIPTEN
class EmscriptenUtil {
public:
  static bool isNone(emscripten::val const &val) {
    return val.isNull() || val.isUndefined();
  }
};
#endif

NAMESPACE_BEGIN(css)

#ifdef _EMSCRIPTEN
using Mapper_t = emscripten::val;
#else
using Mapper_t = std::map<std::string, std::string>;
#endif

class StyleSheet {
public:
  static void registerEmClass();

  StyleSheet(const Mapper_t &mapper);
  ~StyleSheet() = default;

  [[nodiscard]] std::string getClassName(const std::string &classnameKey) const;

private:
  Mapper_t mapper_;
};

NAMESPACE_END(css)
NAMESPACE_END(webcore)
NAMESPACE_END(sway)

#endif
