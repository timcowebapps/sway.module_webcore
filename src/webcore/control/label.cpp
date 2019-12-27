#include <sway/webcore/control/label.h>
#include <sway/webcore/base/treeupdater.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)
NAMESPACE_BEGIN(control)

void Label::registerEmscriptenClass(lpcstr_t classname) {
	emscripten::class_<Label, emscripten::base<base::TreeNodeElement>>(classname)
		.constructor<core::containers::TreeNodePtr_t, std::string, base::TreeNodeElementCreateInfo>()
		.smart_ptr<LabelSmartPtr_t>("LabelSmartPtr_t")
		.class_function("createControl", &Label::createControl, emscripten::allow_raw_pointers())
		.function("setStyleSheet", &Label::setStyleSheet)
		.function("setFontFamily", &Label::setFontFamily)
		.function("setColor", &Label::setColor)
		.function("getText", &Label::getText)
		.function("setText", &Label::setText);
}

LabelSmartPtr_t Label::createControl(core::containers::TreeNodePtr_t parent,
	const std::string & nodeId, const base::TreeNodeElementCreateInfo & createInfo, const std::string & content) {
	auto instance = std::make_shared<Label>(parent, nodeId, createInfo);
	instance->setHtmlContent(content);
	parent->addChild(instance.get());
	return instance;
}

Label::Label(core::containers::TreeNodePtr_t parent,
	const std::string & nodeId, const base::TreeNodeElementCreateInfo & createInfo)
	: base::TreeNodeElement(parent, core::containers::TreeNodeIndex(), nodeId, createInfo) {
	// Empty
}

void Label::accept(base::ITreeVisitor * visitor) {
	visitor->visit(this);
	for (core::containers::TreeNodePtr_t node : getChildren())
		static_cast<Label *>(node)->accept(visitor);
}

namespace Emscripten {
	bool isNone(emscripten::val const& val) {
		return val.isNull() || val.isUndefined();
	}
}

void Label::setStyleSheet(emscripten::val styleSheet) {
	if (Emscripten::isNone(styleSheet) || Emscripten::isNone(styleSheet["label"]))
		return;

	_styleSheet.insert(std::make_pair("label", styleSheet["label"].as<std::string>()));
	EM_ASM({console.log(UTF8ToString($0))}, _styleSheet["label"].c_str());
}

void Label::setFontFamily(const std::string & fontFamily) {
	_fontFamily = fontFamily;
}

void Label::setColor(const std::string & color) {
	_color = color;
}

std::string Label::getText() const {
	return getHtmlContent();
}

void Label::setText(const std::string & text) {
	if (text == getHtmlContent())
		return;

	setHtmlContent(text);
	for (core::containers::TreeListener * listener : getHostTree()->getListeners())
		listener->onNodeUpdated(getNodeIndex());
}

NAMESPACE_END(control)
NAMESPACE_END(webcore)
NAMESPACE_END(sway)
