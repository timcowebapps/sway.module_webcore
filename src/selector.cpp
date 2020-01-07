#include <sway/webcore/selector.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)

std::string Selector::SelectorPrefix_Id = std::string("#");
std::string Selector::SelectorPrefix_Class = std::string(".");

Selector::Selector(u32_t type, const std::string & name)
	: _type(type)
	, _name(name) {
	// Empty
}

u32_t Selector::getType() const {
	return _type;
}

std::string Selector::getName() const {
	return _name;
}

std::string Selector::toString() const {
	switch (core::detail::toEnum<SelectorTypes_t>(_type)) {
	case SelectorTypes_t::kId:
		return Selector::SelectorPrefix_Id + _name;

	case SelectorTypes_t::kClass:
		return Selector::SelectorPrefix_Class + _name;

	default:
		return "";
	}
}

NAMESPACE_END(webcore)
NAMESPACE_END(sway)
