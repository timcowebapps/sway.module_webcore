#ifndef _SWAY_WEBCORE_CSS_SELECTOR_H
#define _SWAY_WEBCORE_CSS_SELECTOR_H

#include <sway/webcore/css/selectortypes.h>
#include <sway/webcore/prereqs.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)
NAMESPACE_BEGIN(css)

typedef std::shared_ptr<class Selector> SelectorSmartPtr_t;
typedef std::vector<SelectorSmartPtr_t> SelectorVec_t;

class Selector {
public:

#pragma region "Static methods"

	static void registerEmscriptenClass(lpcstr_t classname);

#pragma endregion

#pragma region "Constructor / Destructor"

	/*!
	 * \brief
	 *    Конструктор класса.
	 *    Выполняет инициализацию нового экземпляра класса.
	 */
	Selector(SelectorTypes_t type);

	/*!
	 * \brief
	 *    Виртуальный деструктор класса.
	 */
	virtual ~Selector() = default;

#pragma endregion

#pragma region "Getters / Setters"

	SelectorTypes_t getType() const;

	std::string getName() const;

	void setName(const std::string & name);

#pragma endregion

private:
	SelectorTypes_t _type;
	std::string _name;
};

NAMESPACE_END(css)
NAMESPACE_END(webcore)
NAMESPACE_END(sway)

#endif // _SWAY_WEBCORE_CSS_SELECTOR_H
