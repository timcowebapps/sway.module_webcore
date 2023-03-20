#ifndef SWAY_WEBCORE_REGIONCREATEINFO_HPP
#define SWAY_WEBCORE_REGIONCREATEINFO_HPP

#include <sway/webcore/prereqs.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)

struct RegionCreateInfo {
  std::string id;  // Уникальный идентификатор.
  bool replace;
};

NAMESPACE_END(webcore)
NAMESPACE_END(sway)

#endif
