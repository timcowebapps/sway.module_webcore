#ifndef SWAY_WEBCORE_CSS_SELECTOR_HPP
#define SWAY_WEBCORE_CSS_SELECTOR_HPP

#include <sway/webcore/css/selectortypes.hpp>
#include <sway/webcore/prereqs.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)
NAMESPACE_BEGIN(css)

class Selector {
public:
  static void registerEmClass();

  Selector(SelectorType type);

  virtual ~Selector() = default;

  [[nodiscard]] SelectorType getType() const;

  [[nodiscard]] std::string getName() const;

  void setName(const std::string &name);

private:
  SelectorType type_;
  std::string name_;
};

NAMESPACE_END(css)
NAMESPACE_END(webcore)
NAMESPACE_END(sway)

#endif
