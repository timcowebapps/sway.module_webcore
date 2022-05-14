#ifndef SWAY_WEBCORE_ROUTER_URI_HPP
#define SWAY_WEBCORE_ROUTER_URI_HPP

#include <sway/webcore/prereqs.hpp>
#include <sway/webcore/router/uriregex.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)
NAMESPACE_BEGIN(router)

class Uri {
  enum { nmatch = 11 };

public:
  Uri(const std::string &str);
  ~Uri();

  [[nodiscard]] const std::string getPath() const;

  [[nodiscard]] const std::string getQuery() const;

  [[nodiscard]] const std::string getFragment() const;

private:
  UriRegex regex_;
  regmatch_t *pmatch_;
  std::string str_;
};

NAMESPACE_END(router)
NAMESPACE_END(webcore)
NAMESPACE_END(sway)

#endif
