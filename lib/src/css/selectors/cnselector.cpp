#include <sway/webcore/css/selectors/cnselector.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)
NAMESPACE_BEGIN(css)

EMSCRIPTEN_BINDING_BEGIN(CnSelector)
#ifdef EMSCRIPTEN_PLATFORM
emscripten::class_<CnSelector, emscripten::base<Selector>>("CnSelector")
    .constructor<CnSelectorChain>()
    .function("getMods", &CnSelector::getMods);
#endif
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
#ifdef EMSCRIPTEN_PLATFORM
  return emscripten::vecFromJSArray<std::string>(chain_.mods);
#else
  return chain_.mods;
#endif
}

NAMESPACE_END(css)
NAMESPACE_END(webcore)
NAMESPACE_END(sway)
