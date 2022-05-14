#ifndef SWAY_WEBCORE_EVENTHANDLER_HPP
#define SWAY_WEBCORE_EVENTHANDLER_HPP

#include <sway/webcore/eventtarget.hpp>
#include <sway/webcore/prereqs.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)

struct EventHandler {
  std::string type; /* Тип события. */
  std::string targetId;
  webcore::EventTarget *target;
};

NAMESPACE_END(webcore)
NAMESPACE_END(sway)

#endif
