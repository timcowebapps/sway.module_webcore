#include <sway/webcore/eventtypes.h>
#include <string>

template<typename Type = char, typename Traits = std::char_traits<Type>, typename Alloc = std::allocator<Type>>
inline std::basic_string<Type, Traits, Alloc> stringize(sway::webcore::EventTypes_t value) {
	switch (value) {
		case sway::webcore::EventTypes_t::kClick: return "click";
		case sway::webcore::EventTypes_t::kMouseOver: return "mouseover";
		case sway::webcore::EventTypes_t::kMouseOut: return "mouseout";
		default:
			return "unknown";
	}
}
