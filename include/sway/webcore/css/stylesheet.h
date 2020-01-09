#ifndef _SWAY_WEBCORE_CSS_STYLESHEET_H
#define _SWAY_WEBCORE_CSS_STYLESHEET_H

#include <sway/webcore/prereqs.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)

class EmscriptenUtil {
public:
	static bool isNone(emscripten::val const & val) {
		return val.isNull() || val.isUndefined();
	}
};

NAMESPACE_BEGIN(css)

class StyleSheet {
public:

#pragma region "Static methods"

	static void registerEmscriptenClass(lpcstr_t classname);

#pragma endregion

#pragma region "Constructor / Destructor"

	/*!
	 * \brief
	 *    Конструктор класса.
	 *    Выполняет инициализацию нового экземпляра класса.
	 */
	StyleSheet(const emscripten::val & mapper = emscripten::val::null());

	/*!
	 * \brief
	 *    Деструктор класса.
	 */
	~StyleSheet() = default;

#pragma endregion

#pragma region "Getters / Setters"

	std::string getClassName(const std::string & classnameKey) const;

#pragma endregion

private:
	emscripten::val _mapper;
};

NAMESPACE_END(css)
NAMESPACE_END(webcore)
NAMESPACE_END(sway)

#endif // _SWAY_WEBCORE_CSS_STYLESHEET_H
