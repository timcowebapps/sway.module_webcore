#ifndef _SWAY_WEBCORE_VIEW_ABSTRACTVIEW_H
#define _SWAY_WEBCORE_VIEW_ABSTRACTVIEW_H

#include <sway/webcore/view/observer.h>
#include <sway/webcore/prereqs.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)
NAMESPACE_BEGIN(view)

template<class OBSERVABLE_CLASS>
class TAbstractView;

template<class OBSERVABLE_CLASS>
using TViewHierarchy = core::containers::THierarchy<TAbstractView<OBSERVABLE_CLASS>>;

/*!
 * \brief
 *    Шаблонный класс абстрактного представления.
 */
template<class OBSERVABLE_CLASS>
class TAbstractView
	: public TViewHierarchy<OBSERVABLE_CLASS>
	, public virtual IObserver {
public:

	#pragma region Constructor / Destructor

	/*!
	 * \brief
	 *    Конструктор класса.
	 *    Выполняет инициализацию нового экземпляра класса.
	 * 
	 * \param[in] name
	 *    Имя представления.
	 */
	TAbstractView(const std::string & name);

	/*!
	 * \brief
	 *    Виртуальный деструктор класса.
	 */
	virtual ~TAbstractView();

	#pragma endregion // Constructor / Destructor

	#pragma region IObserver implementation

	/*!
	 * \brief
	 *    Обновляет состояние наблюдателя.
	 */
	virtual void update() override;

	#pragma endregion // IObserver implementation

	#pragma region Setters / Getters

	/*!
	 * \brief
	 *    Устанавливает модель данных.
	 * 
	 * \param[in] model
	 *    Модель данных.
	 */
	virtual void setModel(OBSERVABLE_CLASS * model);

	/*!
	 * \brief
	 *    Возвращает модель данных.
	 */
	virtual OBSERVABLE_CLASS * getModel();

	#pragma endregion // Setters/Getters

private:
	OBSERVABLE_CLASS * _model = nullptr; /*!< Модель данных. */
};

NAMESPACE_END(view)
NAMESPACE_END(webcore)
NAMESPACE_END(sway)

#include <sway/webcore/view/abstractview.inl>

#endif // _SWAY_WEBCORE_VIEW_ABSTRACTVIEW_H
