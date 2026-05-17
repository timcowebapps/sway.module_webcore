#ifndef SWAY_WEBCORE_CSS_SELECTOR_HPP
#define SWAY_WEBCORE_CSS_SELECTOR_HPP

#include <sway/emscriptenmacros.hpp>
#include <sway/webcore/css/selectortypes.hpp>
#include <sway/webcore/prereqs.hpp>

namespace sway::webcore {

class Selector {
  DECLARE_EMSCRIPTEN_BINDING()

public:
  Selector(SelectorType type);

  virtual ~Selector() = default;

  [[nodiscard]]
  auto getType() const -> SelectorType;

  [[nodiscard]]
  auto getName() const -> std::string;

  void setName(const std::string &name);

private:
  SelectorType type_;
  std::string name_;
};

}  // namespace sway::webcore

#endif
