#include <sway/webcore/router/uri.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)
NAMESPACE_BEGIN(router)

Uri::Uri(const std::string & str)
	: _regex(UriRegex())
	, _str(str) {

	_pmatch = (regmatch_t *)malloc(Uri::nmatch * sizeof(regmatch_t));
	int matched = _regex.exec(str.c_str(), Uri::nmatch, _pmatch, 0);
	if (matched) EM_ASM({
		console.log("String " + UTF8ToString($0) + " does not match regex " + UTF8ToString($1))
	}, str.c_str(), UriRegex::expression);
}

Uri::~Uri() {
	free(_pmatch);
}

const std::string Uri::getPath() const {
	return (_pmatch[6].rm_so > -1)
		? _str.substr(_pmatch[6].rm_so, _pmatch[6].rm_eo - _pmatch[6].rm_so)
		: std::string();
}

const std::string Uri::getQuery() const {
	return (_pmatch[7].rm_so > -1)
		? _str.substr(_pmatch[7].rm_so, _pmatch[7].rm_eo - _pmatch[7].rm_so)
		: std::string();
}

const std::string Uri::getFragment() const {
	return (_pmatch[10].rm_so > -1)
		? _str.substr(_pmatch[10].rm_so, _pmatch[10].rm_eo - _pmatch[10].rm_so)
		: std::string();
}

NAMESPACE_END(router)
NAMESPACE_END(webcore)
NAMESPACE_END(sway)
