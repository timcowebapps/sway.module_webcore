#ifndef _SWAY_WEBCORE_STYLESHEET_H
#define _SWAY_WEBCORE_STYLESHEET_H

#include <sway/webcore/prereqs.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)

class EmscriptenUtil {
public:
	static bool isNone(emscripten::val const & val) {
		return val.isNull() || val.isUndefined();
	}
};

class StyleSheet {
public:

#pragma region "Constructor / Destructor"

	/*!
	 * \brief
	 *    Конструктор класса.
	 *    Выполняет инициализацию нового экземпляра класса.
	 */
	StyleSheet(const emscripten::val & mapper);

	/*!
	 * \brief
	 *    Виртуальный деструктор класса.
	 */
	virtual ~StyleSheet() = default;

#pragma endregion

#pragma region "Getters / Setters"

	std::string getClassName(lpcstr_t style) const;

#pragma endregion

private:
	emscripten::val _mapper;
};

NAMESPACE_END(webcore)
NAMESPACE_END(sway)

#endif // _SWAY_WEBCORE_STYLESHEET_H
