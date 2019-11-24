#include <sway/webcore/view/viewcomponent.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)
NAMESPACE_BEGIN(view)

ViewComponent::ViewComponent(const std::string & name, const ViewComponentOptions & options)
	: TAbstractView<model::AbstractModel>(name)
	, _domElement(emscripten::val::null()) {

	_domElement = dom::Document::createElement(options.tagname);
	_domElement.setInnerHtml(options.htmlString);
	if (!options.id.empty()) _domElement.setAttribute("id", options.id);
	if (!options.classname.empty()) _domElement.addClassName(options.classname);
}

void ViewComponent::buildTemplate(const std::string & html) {
	_domElement.setInnerHtml(html);
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
	EM_ASM({console.log("DESTROY_VIEW " + UTF8ToString($0))}, getName().c_str());
	removeAll();
}

void ViewComponent::addRegion(const std::string & name, const RegionOptions & options) {
	_regions.insert(std::make_pair(name, std::make_shared<Region>(/*this, */options)));
}

RegionPtr_t ViewComponent::getRegion(const std::string & name) const {
	RegionIterator_t iter = _regions.find(name);
	if (iter != _regions.end())
		return iter->second;

	return nullptr;
}

RegionNameVec_t ViewComponent::getRegionNames() const {
	RegionNameVec_t keys;
	std::transform(_regions.begin(), _regions.end(), std::back_inserter(keys),
		[](const RegionMap_t::value_type & pair) {
			return pair.first;
		}
	);

	return keys;
}

void ViewComponent::addChildView(ViewComponent * child) {
	addChild(child);
	repaint();
}

void ViewComponent::removeChildView(ViewComponent * child) {
	removeChild(child);
	SAFE_DELETE(child);
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

void ViewComponent::prerepaint() {
	// Default Implementation
}

void ViewComponent::repaint() {
	prerepaint();

	for (typename NodeMap_t::const_iterator iter = children.begin(); iter != children.end(); ++iter) {
		ViewComponent * child = static_cast<ViewComponent *>(iter->second);
		child->repaint();
	}
}

emscripten::val ViewComponent::getElement() {
	return _domElement;
}

NAMESPACE_END(view)
NAMESPACE_END(webcore)
NAMESPACE_END(sway)
