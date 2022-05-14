#include <sway/webcore/css/selectors/cnselector.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)
NAMESPACE_BEGIN(css)

void CnSelector::registerEmClass() {
#ifdef _EMSCRIPTEN
  emscripten::class_<CnSelector, emscripten::base<Selector>>("CnSelector")
      .constructor<CnSelectorChain>()
      .function("getMods", &CnSelector::getMods);
#endif
}

CnSelector::CnSelector(const CnSelectorChain &chain)
    : Selector(SelectorType::CN)
    , chain_(chain) {
  std::string name = chain_.elem.empty() ? chain_.block : chain_.block + "__" + chain_.elem;

  setName(name);
}

std::vector<std::string> CnSelector::getMods() const {
#ifdef _EMSCRIPTEN
  return emscripten::vecFromJSArray<std::string>(chain_.mods);
#else
  return chain_.mods;
#endif
}

NAMESPACE_END(css)
NAMESPACE_END(webcore)
NAMESPACE_END(sway)
