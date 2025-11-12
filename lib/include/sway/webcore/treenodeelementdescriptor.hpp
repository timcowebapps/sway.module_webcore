#ifndef SWAY_WEBCORE_TREENODEELEMENTDESCRIPTOR_HPP
#define SWAY_WEBCORE_TREENODEELEMENTDESCRIPTOR_HPP

#include <sway/webcore/css/selectors/cnselectordescriptor.hpp>
#include <sway/webcore/prereqs.hpp>

namespace sway::webcore {

struct TreeNodeElementDescriptor {
  std::string tagname;  //!< Имя тега.
  std::string id;  //!< Уникальный идентификатор.
#ifdef EMSCRIPTEN_PLATFORM
  emscripten::val stylesheet;  //!< Ассоциативный массив стилей.
  emscripten::val classes;  //!< std::vector<CnSelectorDescriptor>
#else
  std::map<std::string, std::string> stylesheet;
  std::vector<CnSelectorDescriptor> classes;
#endif
};

}  // namespace sway::webcore

#endif
