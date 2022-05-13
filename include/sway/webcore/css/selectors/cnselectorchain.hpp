#ifndef SWAY_WEBCORE_CSS_CNSELECTORCHAIN_HPP
#define SWAY_WEBCORE_CSS_CNSELECTORCHAIN_HPP

#include <sway/webcore/prereqs.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)
NAMESPACE_BEGIN(css)

#ifdef _EMSCRIPTEN
using ModifierSet_t = emscripten::val;
#else
using ModifierSet_t = std::vector<std::string>;
#endif

struct CnSelectorChain {
  std::string block;
  std::string elem;
  ModifierSet_t mods;
};

NAMESPACE_END(css)
NAMESPACE_END(webcore)
NAMESPACE_END(sway)

#endif
