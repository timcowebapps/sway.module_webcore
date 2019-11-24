#ifndef _SWAY_WEBCORE_CONTROLLER_ABSTRACTCONTROLLER_H
#define _SWAY_WEBCORE_CONTROLLER_ABSTRACTCONTROLLER_H

#include <sway/webcore/model/abstractmodel.h>
#include <sway/webcore/prereqs.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)
NAMESPACE_BEGIN(controller)

class AbstractController {
public:

	#pragma region Constructor / Destructor

	/*!
	 * \brief
	 *    Конструктор класса.
	 *    Выполняет инициализацию нового экземпляра класса.
	 * 
	 * \param[in] model
	 *    Модель данных.
	 */
	AbstractController(model::AbstractModel */*model::ModelSmartPtr_t*/ model);

	/*!
	 * \brief
	 *    Деструктор класса.
	 */
	~AbstractController();

	#pragma endregion // Constructor / Destructor

	/*!
	 * \brief
	 *    Возвращает модель данных.
	 */
	model::AbstractModel */*model::ModelSmartPtr_t*/ getModel();

private:
	model::AbstractModel * /*model::ModelSmartPtr_t*/ _model; /*!< Модель данных. */
	view::ViewComponent * _view; /*!< Представление. */
};

NAMESPACE_END(controller)
NAMESPACE_END(webcore)
NAMESPACE_END(sway)

#endif // _SWAY_WEBCORE_CONTROLLER_ABSTRACTCONTROLLER_H