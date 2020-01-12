#include <sway/webcore/visualcomponent.h>
#include <sway/webcore/treeupdater.h>
#include <sway/webcore/css/selectors/cnselectorchain.h>
#include <sway/webcore/css/selectors/cnselectordescriptor.h>
#include <sway/webcore/css/selectors/idselector.h>
#include <sway/webcore/css/selectors/cnselector.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)

void AVisualComponent::registerEmscriptenClass(lpcstr_t classname) {
	emscripten::class_<AVisualComponent, emscripten::base<TreeNodeElement>>(classname)
		.constructor<core::containers::HierarchyNodePtr_t,
			core::containers::HierarchyNodeIndex, std::string, TreeNodeElementCreateInfo>()
		.function("setStyleSheet", &AVisualComponent::setStyleSheet)
		.function("appendStyle", &AVisualComponent::appendStyle)
		.function("getModel", &AVisualComponent::getModel, emscripten::allow_raw_pointers())
		.function("setModel", &AVisualComponent::setModel, emscripten::allow_raw_pointers())
		.function("addSelector", &AVisualComponent::addSelector, emscripten::allow_raw_pointers())
		.function("getSelectors", &AVisualComponent::getSelectors, emscripten::allow_raw_pointers());
}

AVisualComponent::AVisualComponent(core::containers::HierarchyNodePtr_t parent,
	const core::containers::HierarchyNodeIndex & nodeIndex,
	const std::string & nodeId, const TreeNodeElementCreateInfo & createInfo)
	: TreeNodeElement(parent, nodeIndex, nodeId, createInfo) {

	addSelector(std::make_shared<css::IdSelector>(createInfo.id));

	auto classes = emscripten::vecFromJSArray<css::CnSelectorDescriptor>(createInfo.classes);
	for (css::CnSelectorDescriptor desc : classes)
		addSelector(std::make_shared<css::CnSelector>(desc.chain));

	if (EmscriptenUtil::isNone(createInfo.stylesheet)) {
		EM_ASM({console.warn("'stylesheet' must be not null")});
	}
	else {
		setStyleSheet(createInfo.stylesheet);
		appendStyle();
	}
}

void AVisualComponent::accept(ITreeVisitor * visitor) {
	visitor->visitOnEnter(this);

	for (core::containers::HierarchyNodePtr_t node : getChildren())
		static_cast<AVisualComponent *>(node)->accept(visitor);
}

void AVisualComponent::initialize() {
	// Empty
}

void AVisualComponent::update() {
	// Empty
}

css::StyleSheet AVisualComponent::getStyleSheet() const {
	return _styleSheet;
}

void AVisualComponent::setStyleSheet(const emscripten::val & mapper) {
	_styleSheet = css::StyleSheet(mapper);
}

void AVisualComponent::appendStyle() {
	std::vector<std::string> classnameList;
	for (css::SelectorSmartPtr_t selector : getSelectors()) {
		if (selector->getType() == css::SelectorTypes_t::kCn) {
			css::CnSelector * cnSelector = (css::CnSelector *) selector.get();
			classnameList.push_back(_styleSheet.getClassName(cnSelector->getName()));

			for (std::string mod : cnSelector->getMods())
				classnameList.push_back(_styleSheet.getClassName(
					core::misc::format("%s--%s", cnSelector->getName().c_str(), mod.c_str())));
		}
	}

	setHtmlElementClasses(classnameList);
}

void AVisualComponent::addSelector(css::SelectorSmartPtr_t selector) {
	_selectors.push_back(selector);
}

css::SelectorVec_t AVisualComponent::getSelectors() {
	return _selectors;
}

core::utilities::Observable * AVisualComponent::getModel() {
	return _model;
}

void AVisualComponent::setModel(core::utilities::Observable * model) {
	_model = model;
	_model->registerObserver(this);
}

NAMESPACE_END(webcore)
NAMESPACE_END(sway)
