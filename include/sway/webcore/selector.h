#ifndef _SWAY_WEBCORE_SELECTOR_H
#define _SWAY_WEBCORE_SELECTOR_H

#include <sway/webcore/selectortypes.h>
#include <sway/webcore/prereqs.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)

typedef std::vector<class Selector> SelectorGroup_t;

class Selector {
public:

#pragma region "Static variables"

	static std::string SelectorPrefix_Id;
	static std::string SelectorPrefix_Class;

#pragma endregion

#pragma region "Constructor / Destructor"

	/*!
	 * \brief
	 *    Конструктор класса.
	 *    Выполняет инициализацию нового экземпляра класса.
	 */
	Selector(u32_t type, const std::string & name);

	/*!
	 * \brief
	 *    Виртуальный деструктор класса.
	 */
	virtual ~Selector() = default;

#pragma endregion

#pragma region "Getters / Setters"

	u32_t getType() const;

	std::string getName() const;

#pragma endregion

	std::string toString() const;

private:
	u32_t _type;
	std::string _name;
};

NAMESPACE_END(webcore)
NAMESPACE_END(sway)

#endif // _SWAY_WEBCORE_SELECTOR_H
