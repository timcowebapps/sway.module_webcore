#include <sway/webcore/css/selector.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)
NAMESPACE_BEGIN(css)

void Selector::registerEmscriptenClass(lpcstr_t classname) {
	emscripten::class_<Selector>(classname)
		//.constructor<SelectorTypes_t>()
		.smart_ptr<SelectorSmartPtr_t>(core::misc::format("%sSmartPtr", classname).c_str())
		.function("getType", &Selector::getType)
		.function("getName", &Selector::getName);
}

Selector::Selector(SelectorTypes_t type)
	: _type(type) {
	// Empty
}

SelectorTypes_t Selector::getType() const {
	return _type;
}

std::string Selector::getName() const {
	return _name;
}

void Selector::setName(const std::string & name) {
	_name = name;
}

NAMESPACE_END(css)
NAMESPACE_END(webcore)
NAMESPACE_END(sway)
