#include <sway/webcore/tree.hpp>

#include <memory>

namespace sway::webcore {

EMSCRIPTEN_BINDING_BEGIN(Tree)
#ifdef EMSCRIPTEN_PLATFORM
emscripten::class_<TreeListener>("TreeListener");
emscripten::class_<Tree, emscripten::base<core::Hierarchy>>("Tree").constructor();
#endif
EMSCRIPTEN_BINDING_END()

void TreeListener::onNodeAdded(const core::NodeIndex &nodeIdx) {}

void TreeListener::onNodeRemoved(core::Node parent, core::Node child) {}

void TreeListener::onNodeUpdated(const core::NodeIndex &nodeIdx) {}

Tree::Tree() {}

}  // namespace sway::webcore
