#ifndef _SWAY_WEBCORE_VIEW_OBSERVER_H
#define _SWAY_WEBCORE_VIEW_OBSERVER_H

#include <sway/namespacemacros.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)
NAMESPACE_BEGIN(view)

/*!
 * \brief
 *    Наблюдатель.
 */
class IObserver {
public:
	/*!
	 * \brief
	 *    Виртуальный деструктор класса.
	 */
	virtual ~IObserver() {
		// Empty
	}

	/*!
	 * \brief
	 *    Обновляет состояние наблюдателя.
	 */
    virtual void update() = 0;
};

NAMESPACE_END(view)
NAMESPACE_END(webcore)
NAMESPACE_END(sway)

#endif // _SWAY_WEBCORE_VIEW_OBSERVER_H
