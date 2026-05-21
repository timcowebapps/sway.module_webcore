#include <sway/webcore/css/selectors/idselector.hpp>

namespace sway::webcore {

EMSCRIPTEN_BINDING_BEGIN(IdSelector)
emscripten::class_<IdSelector, emscripten::base<Selector>>("IdSelector").constructor<std::string>();
EMSCRIPTEN_BINDING_END()

IdSelector::IdSelector(const std::string &name)
    : Selector(SelectorType::ID) {
  setName(name);
}

}  // namespace sway::webcore
