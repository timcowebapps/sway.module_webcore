#ifndef _SWAY_WEBCORE_DOM_DOCUMENT_H
#define _SWAY_WEBCORE_DOM_DOCUMENT_H

#include <sway/webcore/dom/element.h>
#include <sway/webcore/prereqs.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)
NAMESPACE_BEGIN(dom)

class Document {
public:
	static Element createElement(const std::string & tagname) {
		return emscripten::val::global("document").call<emscripten::val>("createElement", emscripten::val(tagname));
	}
	static Element getElementById(const std::string & id) {
		return emscripten::val::global("document").call<emscripten::val>("getElementById", id);
	}
};

NAMESPACE_END(dom)
NAMESPACE_END(webcore)
NAMESPACE_END(sway)

#endif // _SWAY_WEBCORE_DOM_DOCUMENT_H
