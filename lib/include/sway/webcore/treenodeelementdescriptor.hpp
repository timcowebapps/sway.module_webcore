#ifndef SWAY_WEBCORE_TREENODEELEMENTDESCRIPTOR_HPP
#define SWAY_WEBCORE_TREENODEELEMENTDESCRIPTOR_HPP

#include <sway/webcore/css/selectors/cnselectordescriptor.hpp>
#include <sway/webcore/prereqs.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)

struct TreeNodeElementDescriptor {
  std::string tagname; /*!< Имя тега. */
  std::string id; /*!< Уникальный идентификатор. */
#ifdef _EMSCRIPTEN
  emscripten::val stylesheet; /*!< Ассоциативный массив стилей. */
  emscripten::val classes; /*!< std::vector<css::CnSelectorDescriptor> */
#else
  std::map<std::string, std::string> stylesheet;
  std::vector<css::CnSelectorDescriptor> classes;
#endif
};

NAMESPACE_END(webcore)
NAMESPACE_END(sway)

#endif
