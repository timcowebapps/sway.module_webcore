#include <sway/webcore/css/selector.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)
NAMESPACE_BEGIN(css)

void Selector::registerEmClass() {
#ifdef _EMSCRIPTEN
  emscripten::class_<Selector>("Selector")
      //.constructor<SelectorType>()
      .smart_ptr<std::shared_ptr<Selector>>("SelectorSmartPtr")
      .function("getType", &Selector::getType)
      .function("getName", &Selector::getName);
#endif
}

Selector::Selector(SelectorType type)
    : type_(type) {
}

SelectorType Selector::getType() const {
  return type_;
}

std::string Selector::getName() const {
  return name_;
}

void Selector::setName(const std::string &name) {
  name_ = name;
}

NAMESPACE_END(css)
NAMESPACE_END(webcore)
NAMESPACE_END(sway)
