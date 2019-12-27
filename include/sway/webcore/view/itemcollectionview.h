#ifndef _SWAY_WEBCORE_VIEW_ABSTRACTITEMCOLLECTIONVIEW_H
#define _SWAY_WEBCORE_VIEW_ABSTRACTITEMCOLLECTIONVIEW_H

#include <sway/webcore/base/treenodeelement.h>
#include <sway/webcore/view/observer.h>
#include <sway/webcore/model/abstractitemcollection.h>
#include <sway/webcore/prereqs.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)
NAMESPACE_BEGIN(view)

/*!
 * \brief
 *    Абстрактное представление.
 */
class AItemCollectionView
	: public base::TreeNodeElement
	, public virtual IObserver {
public:

	#pragma region Static methods

	static void registerEmscriptenClass(lpcstr_t classname);

	#pragma endregion // Static methods

	#pragma region Constructor / Destructor

	/*!
	 * \brief
	 *    Конструктор класса.
	 *    Выполняет инициализацию нового экземпляра класса.
	 * 
	 * \param[in] name
	 *    Имя представления.
	 * 
	 * \param[in] options
	 *    Опции представления.
	 */
	AItemCollectionView(core::containers::TreeNodePtr_t parent,
		//const core::containers::TreeNodeIndex & nodeIndex,
		const std::string & nodeId, const base::TreeNodeElementCreateInfo & createInfo);

	/*!
	 * \brief
	 *    Виртуальный деструктор класса.
	 */
	virtual ~AItemCollectionView() = default;

	#pragma endregion // Constructor / Destructor

	void makeItem(u32_t index, base::TreeNodeElement * child);

	virtual void accept(base::ITreeVisitor * visitor);

	virtual void initialize();

	#pragma region IObserver implementation

	/*!
	 * \brief
	 *    Обновляет состояние наблюдателя.
	 */
	virtual void onDataChanged() override;

	#pragma endregion // IObserver implementation

	#pragma region Getters / Setters

	/*!
	 * \brief
	 *    Возвращает модель данных.
	 */
	model::Observable * getModel();

	/*!
	 * \brief
	 *    Устанавливает модель данных.
	 * 
	 * \param[in] model
	 *    Модель данных.
	 */
	void setModel(model::Observable * model);

	#pragma endregion // Getters / Setters

private:
	model::Observable * _model; /*!< Модель данных. */
};

NAMESPACE_END(view)
NAMESPACE_END(webcore)
NAMESPACE_END(sway)

#endif // _SWAY_WEBCORE_VIEW_ABSTRACTITEMCOLLECTIONVIEW_H
