#include <sway/webcore/css/selectors/cnselector.hpp>
#include <sway/webcore/css/selectors/idselector.hpp>
#include <sway/webcore/css/stylesheet.hpp>
#include <sway/webcore/dom/htmldocument.hpp>
#include <sway/webcore/nodeelementupdater.hpp>
#include <sway/webcore/region.hpp>
#include <sway/webcore/router/router.hpp>
#include <sway/webcore/tree.hpp>
#include <sway/webcore/treenodeelement.hpp>

using namespace sway;
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

auto createTreeNodeElementDescriptor(emscripten::val obj) -> TreeNodeElementDescriptor {
  TreeNodeElementDescriptor descriptor;

  if (obj.hasOwnProperty("tagname")) {
    descriptor.tagname = obj["tagname"].as<std::string>();
  }

  if (obj.hasOwnProperty("id")) {
    descriptor.id = obj["id"].as<std::string>();
  }

  return descriptor;
}

EMSCRIPTEN_BINDINGS(sway_webcore_html) {
  emscripten::value_object<RegionCreateInfo>("RegionCreateInfo")
      .field("id", &RegionCreateInfo::id)
      .field("replace", &RegionCreateInfo::replace);

  emscripten::value_object<CnSelectorChain>("CnSelectorChain")
      .field("block", &CnSelectorChain::block)
      .field("elem", &CnSelectorChain::elem)
      .field("mods", &CnSelectorChain::mods);

  emscripten::value_object<CnSelectorDescriptor>("CnSelectorDescriptor")
      .field("glob", &CnSelectorDescriptor::glob)
      .field("chain", &CnSelectorDescriptor::chain);

  emscripten::value_object<TreeNodeElementDescriptor>("TreeNodeElementDescriptor")
      .field("tagname", &TreeNodeElementDescriptor::tagname)
      .field("id", &TreeNodeElementDescriptor::id)
      .field("stylesheet", &TreeNodeElementDescriptor::stylesheet)
      .field("classes", &TreeNodeElementDescriptor::classes);

  HtmlElement::bindEmscriptenClass();

  emscripten::function("createTreeNodeElementDescriptor", &createTreeNodeElementDescriptor);
  emscripten::function("createTreeNodeElement",
      emscripten::optional_override(
          [](const TreeNodeElementDescriptor &descriptor) { return std::make_shared<TreeNodeElement>(descriptor); }));
  emscripten::function("createTreeNodeElementUpdater",
      emscripten::optional_override([]() { return std::make_shared<NodeElementUpdater>(); }));

  Region::bindEmscriptenClass();
  TreeNodeElement::bindEmscriptenClass();
  Tree::bindEmscriptenClass();
  NodeElementUpdater::bindEmscriptenClass();
  HtmlDocument::bindEmscriptenClass();
}

#endif
