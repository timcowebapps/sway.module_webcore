#ifndef _SWAY_WEBCORE_VIEW_ABSTRACTITEMVIEW_H
#define _SWAY_WEBCORE_VIEW_ABSTRACTITEMVIEW_H

#include <sway/webcore/base/treenodeelement.h>
#include <sway/webcore/prereqs.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)
NAMESPACE_BEGIN(view)

/*!
 * \brief
 *    Абстрактное представление.
 */
class AItemView
	: public base::TreeNodeElement
	, public virtual core::utilities::IObserver {
public:

#pragma region "Static methods"

	static void registerEmscriptenClass(lpcstr_t classname);

#pragma endregion // Static methods

#pragma region "Constructor / Destructor"

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
	AItemView(core::containers::HierarchyNodePtr_t parent,
		//const core::containers::HierarchyNodeIndex & nodeIndex,
		const std::string & nodeId, const base::TreeNodeElementCreateInfo & createInfo);

	AItemView(core::containers::HierarchyNodePtr_t parent,
		const core::containers::HierarchyNodeIndex & nodeIndex,
		const std::string & nodeId, const base::TreeNodeElementCreateInfo & createInfo);

	/*!
	 * \brief
	 *    Виртуальный деструктор класса.
	 */
	virtual ~AItemView();

#pragma endregion // Constructor / Destructor

#pragma region "IVisitable > HierarchyNode > TreeNodeElement implementation"

	virtual void accept(base::ITreeVisitor * visitor) override;

#pragma endregion // IVisitable > HierarchyNode > TreeNodeElement implementation

	virtual void initialize();

#pragma region "IObserver implementation"

	/*!
	 * \brief
	 *    Обновляет состояние наблюдателя.
	 */
	virtual void update() override;

#pragma endregion // IObserver implementation

#pragma region "Getters / Setters"

	/*!
	 * \brief
	 *    Возвращает модель данных.
	 */
	core::utilities::Observable * getModel();

	/*!
	 * \brief
	 *    Устанавливает модель данных.
	 * 
	 * \param[in] model
	 *    Модель данных.
	 */
	void setModel(core::utilities::Observable * model);

#pragma endregion // Getters / Setters

private:
	core::utilities::Observable * _model; /*!< Модель данных. */
};

NAMESPACE_END(view)
NAMESPACE_END(webcore)
NAMESPACE_END(sway)

#endif // _SWAY_WEBCORE_VIEW_ABSTRACTITEMVIEW_H
