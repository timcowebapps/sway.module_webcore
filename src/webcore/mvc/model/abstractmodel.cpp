#include <sway/webcore/mvc/model/abstractmodel.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)
NAMESPACE_BEGIN(mvc)
NAMESPACE_BEGIN(model)

ModelSmartPtr_t AbstractModel::create() {
	return std::make_shared<AbstractModel>();
}

AbstractModel::AbstractModel()
	: _data(emscripten::val::object()) {
	setProperty("id", "0");
}

AbstractModel::~AbstractModel() {
	// Empty
}

void AbstractModel::setProperty(const std::string & key, const std::string & value) {
	_data.set(key, emscripten::val(value));
	notify();
}

emscripten::val AbstractModel::getProperties() const {
	return _data;
}

NAMESPACE_END(model)
NAMESPACE_END(mvc)
NAMESPACE_END(webcore)
NAMESPACE_END(sway)
