#include <sway/webcore/base/treenodeelement.h>
#include <sway/webcore/base/treenode.h>
#include <sway/webcore/base/treeupdater.h>
#include <sway/webcore/base/treevisitor.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)
NAMESPACE_BEGIN(base)

void TreeNodeElement::registerEmscriptenClass(lpcstr_t classname) {
	emscripten::class_<TreeNodeElement>(classname)
		.constructor<TreeNodeElementCreateInfo>()
		.function("addEvent", &TreeNodeElement::addEvent, emscripten::allow_raw_pointers())
		.function("bindEvents", &TreeNodeElement::bindEvents)
		.function("getHtmlElementTagname", &TreeNodeElement::getHtmlElementTagname)
		.function("setHtmlElementTagname", &TreeNodeElement::setHtmlElementTagname)
		.function("getHtmlElementId", &TreeNodeElement::getHtmlElementId)
		.function("setHtmlElementId", &TreeNodeElement::setHtmlElementId)
		.function("getHtmlContent", &TreeNodeElement::getHtmlContent)
		.function("setHtmlContent", &TreeNodeElement::setHtmlContent);
}

TreeNodeElement::TreeNodeElement(const TreeNodeElementCreateInfo & createInfo)
	: _htmlElementTagname(createInfo.tagname)
	, _htmlElementId(createInfo.id)
	, _visibled(true) {
	// Empty
}

void TreeNodeElement::addEvent(const std::string & targetId, const std::string & type, emscripten::val callback) {
	_handlers.push_back((struct EventHandler) {
		.targetId = targetId,
		.target = new EventTarget([](emscripten::val) { /* Empty */ }),
		.type = type
	});

	_handlers.back().target->setCallback(callback);
}

void TreeNodeElement::bindEvents() {
	for (int i = 0; i < _handlers.size(); ++i) {
		EventHandler event = _handlers[i];
		event.target->addEventListener(event.targetId, event.type/*stringize(event.type)*/);
	}
}

TreeNode * TreeNodeElement::getTreeNode() {
	return _treenode;
}

void TreeNodeElement::setTreeNode(TreeNode * node) {
	_treenode = node;
}

std::string TreeNodeElement::getHtmlElementTagname() const {
	return _htmlElementTagname;
}

void TreeNodeElement::setHtmlElementTagname(const std::string & tagname) {
	_htmlElementTagname = tagname;
}

std::string TreeNodeElement::getHtmlElementId() const {
	return _htmlElementId;
}

void TreeNodeElement::setHtmlElementId(const std::string & id) {
	_htmlElementId = id;
}

std::string TreeNodeElement::getHtmlContent() const {
	return _htmlContent;
}

void TreeNodeElement::setHtmlContent(const std::string & content) {
	_htmlContent = content;
}

bool TreeNodeElement::hasVisibled() const {
	return _visibled;
}

void TreeNodeElement::setVisible(bool value) {
	_visibled = value;
}

NAMESPACE_END(base)
NAMESPACE_END(webcore)
NAMESPACE_END(sway)
