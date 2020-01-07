#ifndef _SWAY_WEBCORE_SELECTOR_H
#define _SWAY_WEBCORE_SELECTOR_H

#include <sway/webcore/prereqs.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)

class Selector {
public:

#pragma region "Constructor / Destructor"

	/*!
	 * \brief
	 *    Конструктор класса.
	 *    Выполняет инициализацию нового экземпляра класса.
	 */
	Selector();

	/*!
	 * \brief
	 *    Виртуальный деструктор класса.
	 */
	virtual ~Selector() = default;

#pragma endregion

};

NAMESPACE_END(webcore)
NAMESPACE_END(sway)

#endif // _SWAY_WEBCORE_SELECTOR_H
