#include <sway/webcore/view/region.h>
#include <sway/webcore/view/viewcomponent.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)
NAMESPACE_BEGIN(view)

RegionPtr_t Region::create(const RegionOptions & options) {
	return std::make_shared<Region>(options);
}

Region::Region(const RegionOptions & options)
	: _domElement(emscripten::val::null())
	, _elementAttached(false)
	, _elementId(options.elementId)
	, _replace(options.replace) {

	reinitialize();
}

Region::~Region() {
	// Empty
}

void Region::reinitialize() {
	_domElement = dom::Document::getElementById(_elementId);
}

emscripten::val Region::getElement() const {
	return _domElement;
}

void Region::attachView(ViewComponent * view) {
	reinitialize();

	dom::Element current = _domElement;
	if (current._val.isNull())
		return;

	dom::Element parent = current.getParentElement();
	if (parent._val.isNull())
		return;

	EM_ASM({
		console.groupCollapsed("ATTACH_VIEW " + UTF8ToString($0));
		console.log(UTF8ToString($1));
		console.groupEnd();
	}, view->getName().c_str(), current.toString().c_str());

	if (_replace) parent.replaceChild(view->getElement(), current);
	else current.appendChild(view->getElement());

	//_view->addChild(view);
	_elementAttached = true;
}

void Region::detachView(ViewComponent * view) {
	if (_elementAttached) {
		dom::Element current = dom::Document::getElementById(_elementId);
		if (current._val.isNull())
			return;

		dom::Element parent = current.getParentElement();
		if (parent._val.isNull())
			return;

		EM_ASM({
			console.groupCollapsed("DETACH_VIEW " + UTF8ToString($0));
			console.log(UTF8ToString($1));
			console.groupEnd();
		}, view->getName().c_str(), current.toString().c_str());

		if (_replace) parent.replaceChild(_domElement, current);
		else current.removeChild(view->getElement());

		_elementAttached = false;
	}
}

NAMESPACE_END(view)
NAMESPACE_END(webcore)
NAMESPACE_END(sway)
