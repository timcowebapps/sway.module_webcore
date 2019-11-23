#include <sway/webcore/router/uriregex.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)
NAMESPACE_BEGIN(router)

lpcstr_t const UriRegex::expression = "^(([^:/?#]+):)?((//([^/?#]*))?([^?#]*)([?]([^#]*))?(#(.*))?)";

UriRegex::UriRegex() {
	regcomp(&_preg, UriRegex::expression, REG_EXTENDED);
}

UriRegex::~UriRegex() {
	regfree(&_preg);
}

int UriRegex::exec(lpcstr_t str, size_t nmatch, regmatch_t pmatch[], int eflags) {
	return regexec(&_preg, str, nmatch, pmatch, eflags);
}

NAMESPACE_END(router)
NAMESPACE_END(webcore)
NAMESPACE_END(sway)
