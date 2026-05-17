#include <sway/webcore/css/selectors/idselector.hpp>

namespace sway::webcore {

EMSCRIPTEN_BINDING_BEGIN(IdSelector)
#ifdef EMSCRIPTEN_PLATFORM
emscripten::class_<IdSelector, emscripten::base<Selector>>("IdSelector").constructor<std::string>();
#endif
EMSCRIPTEN_BINDING_END()

IdSelector::IdSelector(const std::string &name)
    : Selector(SelectorType::ID) {
  setName(name);
}

}  // namespace sway::webcore
