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

  [[nodiscard]]
  auto getPath() const -> const std::string;

  [[nodiscard]]
  auto getQuery() const -> const std::string;

  [[nodiscard]]
  auto getFragment() const -> const std::string;

private:
  UriRegex regex_;
  regmatch_t *pmatch_;
  std::string str_;
};

}  // namespace sway::webcore

#endif
