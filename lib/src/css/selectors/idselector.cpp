#include <sway/webcore/css/selectors/idselector.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)
NAMESPACE_BEGIN(css)

void IdSelector::registerEmClass() {
#ifdef EMSCRIPTEN_PLATFORM
  emscripten::class_<IdSelector, emscripten::base<Selector>>("IdSelector").constructor<std::string>();
#endif
}

IdSelector::IdSelector(const std::string &name)
    : Selector(SelectorType::ID) {
  setName(name);
}

NAMESPACE_END(css)
NAMESPACE_END(webcore)
NAMESPACE_END(sway)
