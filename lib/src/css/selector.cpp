#include <sway/webcore/css/selector.hpp>

namespace sway::webcore {

EMSCRIPTEN_BINDING_BEGIN(Selector)
#ifdef EMSCRIPTEN_PLATFORM
emscripten::class_<Selector>("Selector")
    //.constructor<SelectorType>()
    .smart_ptr<std::shared_ptr<Selector>>("SelectorSmartPtr")
    .function("getType", &Selector::getType)
    .function("getName", &Selector::getName);
#endif
EMSCRIPTEN_BINDING_END()

Selector::Selector(SelectorType type)
    : type_(type) {}

auto Selector::getType() const -> SelectorType { return type_; }

auto Selector::getName() const -> std::string { return name_; }

void Selector::setName(const std::string &name) { name_ = name; }

}  // namespace sway::webcore
