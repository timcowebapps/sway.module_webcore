#ifndef _SWAY_WEBCORE_CSS_CNSELECTOR_H
#define _SWAY_WEBCORE_CSS_CNSELECTOR_H

#include <sway/webcore/css/selector.h>
#include <sway/webcore/css/selectors/cnselectorchain.h>
#include <sway/webcore/treenodeelementcreateinfo.h>
#include <sway/webcore/prereqs.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)
NAMESPACE_BEGIN(css)

typedef std::shared_ptr<class CnSelector> CnSelectorSmartPtr_t;

class CnSelector
	: public Selector {
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
	CnSelector(const CnSelectorChain & chain);

	/*!
	 * \brief
	 *    Виртуальный деструктор класса.
	 */
	virtual ~CnSelector() = default;

#pragma endregion

#pragma region "Getters / Setters"

	std::vector<std::string> getMods() const;

#pragma endregion

private:
	CnSelectorChain _chain;
};

NAMESPACE_END(css)
NAMESPACE_END(webcore)
NAMESPACE_END(sway)

#endif // _SWAY_WEBCORE_CSS_CNSELECTOR_H
