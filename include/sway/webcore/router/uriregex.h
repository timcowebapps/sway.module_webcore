#ifndef _SWAY_WEBCORE_ROUTER_URIREGEX_H
#define _SWAY_WEBCORE_ROUTER_URIREGEX_H

#include <sway/webcore/prereqs.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)
NAMESPACE_BEGIN(router)

class UriRegex {
public:

	static lpcstr_t const expression;

	#pragma region Constructor / Destructor

	/*!
	 * \brief
	 *    Конструктор класса.
	 *    Выполняет инициализацию нового экземпляра класса.
	 */
	UriRegex();

	/*!
	 * \brief
	 *    Деструктор класса.
	 */
	~UriRegex();

	#pragma endregion // Constructor / Destructor

	int exec(lpcstr_t str, size_t nmatch, regmatch_t pmatch[], int eflags);

private:
	regex_t _preg;
};

NAMESPACE_END(router)
NAMESPACE_END(webcore)
NAMESPACE_END(sway)

#endif // _SWAY_WEBCORE_ROUTER_URIREGEX_H
