#include <sway/webcore/mvc/view/viewcomponent.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)
NAMESPACE_BEGIN(mvc)
NAMESPACE_BEGIN(view)

ViewComponent::ViewComponent(const std::string & name, const ViewComponentOptions & options)
	: TAbstractView<model::AbstractModel>(name)
	, _region(nullptr)
	, _regionSetted(false)
	, _domElement(emscripten::val::null()) {

	_domElement = dom::Document::createElement(options.tagname);
	_domElement.setInnerHtml(options.htmlString);
	if (!options.id.empty()) _domElement.setAttribute("id", options.id);
	if (!options.classname.empty()) _domElement.addClassName(options.classname);
}

void ViewComponent::addEvent(const std::string & targetId, EventTypes_t type, emscripten::val callback) {
	_handlers.push_back((struct EventHandler) {
		.targetId = targetId,
		.target = new EventTarget([](emscripten::val) { /* Empty */ }),
		.type = type
	});

	_handlers.back().target->setCallback(callback);
}

ViewComponent::~ViewComponent() {
	// Empty
}

void ViewComponent::update() {
	for (int i = 0; i < _handlers.size(); ++i) {
		EventHandler event = _handlers[i];
		event.target->addEventListener(event.targetId, stringize(event.type));
	}

	for (typename NodeMap_t::const_iterator iter = children.begin(); iter != children.end(); ++iter) {
		ViewComponent * child = static_cast<ViewComponent *>(iter->second);
		child->update();
	}
}

void ViewComponent::render() {
	EM_ASM({ console.log("Render: " + UTF8ToString($0)) }, getName().c_str());

	if (_regionSetted) {
		_region->detachView(this);
		_region->attachView(this);
	}

	for (typename NodeMap_t::const_iterator iter = children.begin(); iter != children.end(); ++iter) {
		ViewComponent * child = static_cast<ViewComponent *>(iter->second);
		child->render();
	}
}

void ViewComponent::setRegion(RegionPtr_t region) {
	_region = region;
	_regionSetted = true;
}

RegionPtr_t ViewComponent::getRegion() {
	return _region;
}

emscripten::val ViewComponent::getElement() {
	return _domElement;
}

NAMESPACE_END(view)
NAMESPACE_END(mvc)
NAMESPACE_END(webcore)
NAMESPACE_END(sway)
