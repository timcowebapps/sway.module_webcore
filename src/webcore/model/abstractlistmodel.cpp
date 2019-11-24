#include <sway/webcore/model/abstractlistmodel.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)
NAMESPACE_BEGIN(model)

AbstractListModel::AbstractListModel()
	: _dataItems(emscripten::val::array()) {
	// Empty
}

AbstractListModel::~AbstractListModel() {
	// Empty
}

void AbstractListModel::setItem(int idx, const emscripten::val & value) {
	_dataItems.set(idx, value);
}

emscripten::val AbstractListModel::getItems() const {
	return _dataItems;
}

NAMESPACE_END(model)
NAMESPACE_END(webcore)
NAMESPACE_END(sway)
