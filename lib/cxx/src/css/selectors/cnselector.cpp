#include <sway/webcore/css/selectors/cnselector.hpp>

namespace sway::webcore {

EMSCRIPTEN_BINDING_BEGIN(CnSelector)
emscripten::class_<CnSelector, emscripten::base<Selector>>("CnSelector")
    .constructor<CnSelectorChain>()
    .function("getMods", &CnSelector::getMods);
EMSCRIPTEN_BINDING_END()

CnSelector::CnSelector(const CnSelectorChain &chain)
    : Selector(SelectorType::CN)
    , chain_(chain) {
  // clang-format off
  setName(chain_.elem.empty()
    ? chain_.block
    : chain_.block + "__" + chain_.elem);  // clang-format on
}

auto CnSelector::getMods() const -> std::vector<std::string> {
  return emscripten::vecFromJSArray<std::string>(chain_.mods);
}

}  // namespace sway::webcore
