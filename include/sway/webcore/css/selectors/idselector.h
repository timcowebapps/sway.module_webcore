#ifndef _SWAY_WEBCORE_CSS_IDSELECTOR_H
#define _SWAY_WEBCORE_CSS_IDSELECTOR_H

#include <sway/webcore/css/selector.h>
#include <sway/webcore/prereqs.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)
NAMESPACE_BEGIN(css)

class IdSelector
	: public Selector {
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
	IdSelector(const std::string & name);

	/*!
	 * \brief
	 *    Виртуальный деструктор класса.
	 */
	virtual ~IdSelector() = default;

#pragma endregion
};

NAMESPACE_END(css)
NAMESPACE_END(webcore)
NAMESPACE_END(sway)

#endif // _SWAY_WEBCORE_CSS_IDSELECTOR_H
