#include <sway/webcore/css/selectors/cnselector.hpp>
#include <sway/webcore/css/selectors/idselector.hpp>
#include <sway/webcore/css/stylesheet.hpp>
#include <sway/webcore/region.hpp>
#include <sway/webcore/router/router.hpp>
#include <sway/webcore/treenodeelement.hpp>

using namespace sway::webcore;

#if (defined EMSCRIPTEN_PLATFORM && defined EMSCRIPTEN_USE_BINDINGS)

#  include <emscripten/bind.h>

EMSCRIPTEN_BINDINGS(sway_webcore_router) { Router::bindEmscriptenClass(); }

EMSCRIPTEN_BINDINGS(sway_webcore_css) {
  Selector::bindEmscriptenClass();
  StyleSheet::bindEmscriptenClass();
  CnSelector::bindEmscriptenClass();
  IdSelector::bindEmscriptenClass();
}

EMSCRIPTEN_BINDINGS(sway_webcore_html) {
  Region::bindEmscriptenClass();
  TreeNodeElement::bindEmscriptenClass();
}

#endif
