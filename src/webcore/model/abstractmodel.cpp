#include <sway/webcore/model/abstractmodel.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)
NAMESPACE_BEGIN(model)

ModelSmartPtr_t AbstractModel::create() {
	return std::make_shared<AbstractModel>();
}

AbstractModel::AbstractModel()
	: _data(emscripten::val::object()) {
	// Empty
}

AbstractModel::~AbstractModel() {
	// Empty
}

void AbstractModel::setProp(const std::string & key, const emscripten::val & value) {
	_data.set(key, value);
	notify();
}

emscripten::val AbstractModel::getProps() const {
	return _data;
}

NAMESPACE_END(model)
NAMESPACE_END(webcore)
NAMESPACE_END(sway)
