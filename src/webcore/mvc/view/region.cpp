#include <sway/webcore/mvc/view/region.h>
#include <sway/webcore/mvc/view/viewcomponent.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)
NAMESPACE_BEGIN(mvc)
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

	if (_replace) parent.replaceChild(view->getElement(), current);
	else current.appendChild(view->getElement());

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

		if (_replace) parent.replaceChild(_domElement, current);
		else current.removeChild(view->getElement());

		_elementAttached = false;
	}
}

NAMESPACE_END(view)
NAMESPACE_END(mvc)
NAMESPACE_END(webcore)
NAMESPACE_END(sway)
