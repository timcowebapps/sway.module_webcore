#ifndef _SWAY_WEBCORE_TREENODEELEMENTCREATEINFO_H
#define _SWAY_WEBCORE_TREENODEELEMENTCREATEINFO_H

#include <sway/webcore/prereqs.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)

struct TreeNodeElementClass {
	bool wrap;
	bool glob;
	struct Declaration {
		std::string block;
		std::string elem;
		//std::vector<std::string> mods;
		emscripten::val mods;

		Declaration(std::string block = std::string(""), std::string elem = std::string(""))
			: block(block)
			, elem(elem)
			//, mods(std::vector<std::string>()) {
			, mods(emscripten::val::null()) {
			// Empty
		}
	} decl;

	TreeNodeElementClass()
		: wrap(false)
		, glob(false)
		, decl(Declaration()) {
		// Empty
	}
};

typedef std::vector<TreeNodeElementClass> TreeNodeElementClassVec_t;

struct TreeNodeElementCreateInfo {
	std::string tagname; /*!< Имя тега. */
	std::string id; /*!< Уникальный идентификатор. */
	emscripten::val stylesheet; /*!< Ассоциативный массив стилей. */
	//TreeNodeElementClassVec_t classes;
	emscripten::val classes;

	TreeNodeElementCreateInfo(std::string tagname = std::string(""), std::string id = std::string(""))
		: tagname(tagname)
		, id(id)
		, stylesheet(emscripten::val::null())
		//, classes(std::vector<TreeNodeElementClass>()) {
		, classes(emscripten::val::null()) {
		// Empty
	}
};

NAMESPACE_END(webcore)
NAMESPACE_END(sway)

#endif // _SWAY_WEBCORE_TREENODEELEMENTCREATEINFO_H
