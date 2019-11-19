#ifndef _SWAY_WEBCORE_MVC_MODEL_OBSERVABLE_H
#define _SWAY_WEBCORE_MVC_MODEL_OBSERVABLE_H

#include <sway/webcore/mvc/view/observer.h>
#include <sway/webcore/prereqs.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)
NAMESPACE_BEGIN(mvc)
NAMESPACE_BEGIN(model)

class Observable {
public:

	#pragma region Constructor / Destructor

	/*!
	 * \brief
	 *    Конструктор класса.
	 *    Выполняет инициализацию нового экземпляра класса.
	 */
	Observable();

	/*!
	 * \brief
	 *    Виртуальный деструктор класса.
	 */
	virtual ~Observable();

	#pragma endregion // Constructor / Destructor

	/**
	 * \brief
	 *    Добавляет нового наблюдателя в список наблюдателей, если его еще нет в списке.
	 * 
	 * \param[in] observer
	 *    Наблюдатель будет добавлен в список наблюдателей.
	 */
	void addObserver(view::IObserver * observer);

	/**
	 * \brief
	 *    Удаляет указанного наблюдателя из списка, если он существует.
	 * 
	 * \param[in] observer
	 *    Наблюдатель должен быть исключен из списка наблюдателей.
	 */
	void removeObserver(view::IObserver * observer);

	/**
	 * \brief
	 *    Уведомляет всех наблюдателей о том, что событие произошло.
	 */
	void notify();

private:
	view::ObserverArray_t _observers; /*!< Массив наблюдателей, которые слушают этот наблюдаемый объект. */
};

NAMESPACE_END(model)
NAMESPACE_END(mvc)
NAMESPACE_END(webcore)
NAMESPACE_END(sway)

#endif // _SWAY_WEBCORE_MVC_MODEL_OBSERVABLE_H
