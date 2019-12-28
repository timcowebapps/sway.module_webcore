#ifndef _SWAY_WEBCORE_ROUTER_URI_H
#define _SWAY_WEBCORE_ROUTER_URI_H

#include <sway/webcore/router/uriregex.h>
#include <sway/webcore/prereqs.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)
NAMESPACE_BEGIN(router)

class Uri {
	enum { nmatch = 11 };

public:

#pragma region "Constructor / Destructor"

	/*!
	 * \brief
	 *    Конструктор класса.
	 *    Выполняет инициализацию нового экземпляра класса.
	 */
	Uri(const std::string & str);

	/*!
	 * \brief
	 *    Деструктор класса.
	 */
	~Uri();

#pragma endregion // Constructor / Destructor

	const std::string getPath() const;

	const std::string getQuery() const;

	const std::string getFragment() const;

private:
	UriRegex _regex;
	regmatch_t * _pmatch;
	std::string _str;
};

NAMESPACE_END(router)
NAMESPACE_END(webcore)
NAMESPACE_END(sway)

#endif // _SWAY_WEBCORE_ROUTER_URI_H
