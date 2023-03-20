#include <sway/webcore/router/uriregex.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)
NAMESPACE_BEGIN(router)

lpcstr_t const UriRegex::expression = "^(([^:/?#]+):)?((//([^/?#]*))?([^?#]*)([?]([^#]*))?(#(.*))?)";

UriRegex::UriRegex() { regcomp(&preg_, UriRegex::expression, REG_EXTENDED); }

UriRegex::~UriRegex() { regfree(&preg_); }

int UriRegex::exec(lpcstr_t str, size_t nmatch, regmatch_t pmatch[], int eflags) {
  return regexec(&preg_, str, nmatch, pmatch, eflags);
}

NAMESPACE_END(router)
NAMESPACE_END(webcore)
NAMESPACE_END(sway)
