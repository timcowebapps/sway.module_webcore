#ifndef SWAY_WEBCORE_EVENTHANDLER_HPP
#define SWAY_WEBCORE_EVENTHANDLER_HPP

#include <sway/webcore/eventtarget.hpp>
#include <sway/webcore/prereqs.hpp>

namespace sway::webcore {

struct EventHandler {
  std::string type; /* Тип события. */
  std::string targetId;
  webcore::EventTarget *target;
};

}  // namespace sway::webcore

#endif
