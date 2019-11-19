#ifndef _SWAY_WEBCORE_EVENTTARGET_H
#define _SWAY_WEBCORE_EVENTTARGET_H

#include <sway/webcore/eventlistener.h>
#include <sway/webcore/prereqs.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)

class EventTarget {
public:
	/*!
	 * \brief
	 *    Конструктор класса.
	 *    Выполняет инициализацию нового экземпляра класса.
	 */
	EventTarget(EventCallback_t callback);

	/*!
	 * \brief
	 *    Деструктор класса.
	 */
	~EventTarget();

	/*!
	 * \brief
	 *    Регистрирует определенный обработчик события.
	 * 
	 * \param[in] targetId
	 *    Идентификатор генератора событий.
	 * 
	 * \param[in] type
	 *    Строка, представляющая тип прослушиваемого события.
	 */
	void addEventListener(const std::string & targetId, const std::string & type);

	void setCallback(EventCallback_t callback);

private:
	TargetEventVec_t _events;
	emscripten::val _listener;
};

NAMESPACE_END(webcore)
NAMESPACE_END(sway)

#endif // _SWAY_WEBCORE_EVENTTARGET_H
