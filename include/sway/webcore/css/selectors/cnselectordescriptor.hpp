#ifndef SWAY_WEBCORE_CSS_CNSELECTORDESCRIPTOR_HPP
#define SWAY_WEBCORE_CSS_CNSELECTORDESCRIPTOR_HPP

#include <sway/namespacemacros.hpp>
#include <sway/webcore/css/selectors/cnselectorchain.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)
NAMESPACE_BEGIN(css)

struct CnSelectorDescriptor {
  bool glob;
  CnSelectorChain chain;
};

NAMESPACE_END(css)
NAMESPACE_END(webcore)
NAMESPACE_END(sway)

#endif
