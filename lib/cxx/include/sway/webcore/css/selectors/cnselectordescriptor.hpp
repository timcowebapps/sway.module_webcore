#ifndef SWAY_WEBCORE_CSS_CNSELECTORDESCRIPTOR_HPP
#define SWAY_WEBCORE_CSS_CNSELECTORDESCRIPTOR_HPP

#include <sway/namespacemacros.hpp>
#include <sway/webcore/css/selectors/cnselectorchain.hpp>

namespace sway::webcore {

struct CnSelectorDescriptor {
  bool glob;
  CnSelectorChain chain;
};

}  // namespace sway::webcore

#endif
