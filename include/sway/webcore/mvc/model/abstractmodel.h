#ifndef _SWAY_WEBCORE_MVC_MODEL_ABSTRACTMODEL_H
#define _SWAY_WEBCORE_MVC_MODEL_ABSTRACTMODEL_H

#include <sway/webcore/mvc/model/observable.h>
#include <sway/webcore/prereqs.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)
NAMESPACE_BEGIN(mvc)
NAMESPACE_BEGIN(model)

class AbstractModel : public Observable {
public:
	static ModelSmartPtr_t create();

	#pragma region Constructor / Destructor

	/*!
	 * \brief
	 *    Конструктор класса.
	 *    Выполняет инициализацию нового экземпляра класса.
	 */
	AbstractModel();

	/*!
	 * \brief
	 *    Виртуальный деструктор класса.
	 */
	virtual ~AbstractModel();

	#pragma endregion // Constructor / Destructor

	#pragma region Setters / Getters

	void setProperty(const std::string & key, const std::string & value);

	emscripten::val getProperties() const;

	#pragma endregion // Setters / Getters

private:
	emscripten::val _data;
};

NAMESPACE_END(model)
NAMESPACE_END(mvc)
NAMESPACE_END(webcore)
NAMESPACE_END(sway)

#endif // _SWAY_WEBCORE_MVC_MODEL_ABSTRACTMODEL_H
