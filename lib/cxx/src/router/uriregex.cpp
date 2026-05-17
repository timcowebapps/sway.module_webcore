#include <sway/webcore/router/uriregex.hpp>

namespace sway::webcore {

lpcstr_t const UriRegex::expression = "^(([^:/?#]+):)?((//([^/?#]*))?([^?#]*)([?]([^#]*))?(#(.*))?)";

UriRegex::UriRegex() { regcomp(&preg_, UriRegex::expression, REG_EXTENDED); }

UriRegex::~UriRegex() { regfree(&preg_); }

auto UriRegex::exec(lpcstr_t str, size_t nmatch, regmatch_t pmatch[], int eflags) -> int {
  return regexec(&preg_, str, nmatch, pmatch, eflags);
}

}  // namespace sway::webcore
