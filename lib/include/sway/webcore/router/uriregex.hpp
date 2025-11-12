#ifndef SWAY_WEBCORE_ROUTER_URIREGEX_HPP
#define SWAY_WEBCORE_ROUTER_URIREGEX_HPP

#include <sway/webcore/prereqs.hpp>

#include <array>

namespace sway::webcore {

class UriRegex {
public:
  static lpcstr_t const expression;

  UriRegex();

  ~UriRegex();

  int exec(lpcstr_t str, size_t nmatch, regmatch_t pmatch[], int eflags);
  // template <size_t N>
  // int exec(lpcstr_t str, size_t nmatch, std::array<regmatch_t, N> pmatch, int eflags) {
  //     return regexec(&preg_, str, nmatch, pmatch, eflags);
  // }

private:
  regex_t preg_;
};

}  // namespace sway::webcore

#endif
