#ifndef _SWAY_WEBCORE_BASE_DOM_HTMLDOCUMENT_H
#define _SWAY_WEBCORE_BASE_DOM_HTMLDOCUMENT_H

#include <sway/webcore/base/dom/htmlelement.h>
#include <sway/webcore/prereqs.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)
NAMESPACE_BEGIN(base)
NAMESPACE_BEGIN(dom)

class HtmlDocument {
public:
	static HtmlElement createElement(const std::string & tagname) {
		return emscripten::val::global("document").call<emscripten::val>("createElement", emscripten::val(tagname));
	}

	static HtmlElement getElementById(const std::string & id) {
		return emscripten::val::global("document").call<emscripten::val>("getElementById", id);
	}

	static HtmlElement getElementBySelector(const std::string & selector) {
		return emscripten::val::global("document").call<emscripten::val>("querySelector", selector);
	}
};

NAMESPACE_END(dom)
NAMESPACE_END(base)
NAMESPACE_END(webcore)
NAMESPACE_END(sway)

#endif // _SWAY_WEBCORE_BASE_DOM_HTMLDOCUMENT_H
