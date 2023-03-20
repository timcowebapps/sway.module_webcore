#ifndef SWAY_WEBCORE_CSS_SELECTOR_HPP
#define SWAY_WEBCORE_CSS_SELECTOR_HPP

#include <sway/emscriptenmacros.hpp>
#include <sway/webcore/css/selectortypes.hpp>
#include <sway/webcore/prereqs.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)
NAMESPACE_BEGIN(css)

class Selector {
public:
  DECLARE_EMSCRIPTEN_BINDING()

  Selector(SelectorType type);

  virtual ~Selector() = default;

  [[nodiscard]] auto getType() const -> SelectorType;

  [[nodiscard]] auto getName() const -> std::string;

  void setName(const std::string &name);

private:
  SelectorType type_;
  std::string name_;
};

NAMESPACE_END(css)
NAMESPACE_END(webcore)
NAMESPACE_END(sway)

#endif
