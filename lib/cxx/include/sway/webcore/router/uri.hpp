#ifndef SWAY_WEBCORE_ROUTER_URI_HPP
#define SWAY_WEBCORE_ROUTER_URI_HPP

#include <sway/webcore/prereqs.hpp>
#include <sway/webcore/router/uriregex.hpp>

namespace sway::webcore {

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

}  // namespace sway::webcore

#endif
