#ifndef _SWAY_WEBCORE_TREENODEELEMENTDESCRIPTOR_H
#define _SWAY_WEBCORE_TREENODEELEMENTDESCRIPTOR_H

#include <sway/webcore/prereqs.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)

struct TreeNodeElementDescriptor {
	std::string tagname; /*!< Имя тега. */
	std::string id; /*!< Уникальный идентификатор. */
	emscripten::val stylesheet; /*!< Ассоциативный массив стилей. */
	emscripten::val classes; /*!< std::vector<css::CnSelectorDescriptor> */

	TreeNodeElementDescriptor(std::string tagname = std::string("div"), std::string id = std::string(""))
		: tagname(tagname)
		, id(id)
		, stylesheet(emscripten::val::object())
		, classes(emscripten::val::array()) {
		// Empty
	}
};

NAMESPACE_END(webcore)
NAMESPACE_END(sway)

#endif // _SWAY_WEBCORE_TREENODEELEMENTDESCRIPTOR_H
