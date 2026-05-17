#ifndef SWAY_WEBCORE_REGIONCREATEINFO_HPP
#define SWAY_WEBCORE_REGIONCREATEINFO_HPP

#include <sway/webcore/prereqs.hpp>

namespace sway::webcore {

struct RegionCreateInfo {
  std::string id;  //!< Уникальный идентификатор.
  bool replace;
};

}  // namespace sway::webcore

#endif
