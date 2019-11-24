#ifndef _SWAY_WEBCORE_MODEL_ABSTRACTLISTMODEL_H
#define _SWAY_WEBCORE_MODEL_ABSTRACTLISTMODEL_H

#include <sway/webcore/model/observable.h>
#include <sway/webcore/prereqs.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)
NAMESPACE_BEGIN(model)

class AbstractListModel {
public:

	#pragma region Constructor / Destructor

	/*!
	 * \brief
	 *    Конструктор класса.
	 *    Выполняет инициализацию нового экземпляра класса.
	 */
	AbstractListModel();

	/*!
	 * \brief
	 *    Виртуальный деструктор класса.
	 */
	virtual ~AbstractListModel();

	#pragma endregion // Constructor / Destructor

	#pragma region Setters / Getters

	void setItem(int idx, const emscripten::val & value);

	emscripten::val getItems() const;

	#pragma endregion // Setters / Getters

private:
	emscripten::val _dataItems;
};

NAMESPACE_END(model)
NAMESPACE_END(webcore)
NAMESPACE_END(sway)

#endif // _SWAY_WEBCORE_MODEL_ABSTRACTLISTMODEL_H
