#ifndef SWAY_WEBCORE_PREREQS_HPP
#define SWAY_WEBCORE_PREREQS_HPP

#include <sway/core.hpp>

#include <algorithm>
#include <deque>
#include <functional>
#include <map>
#include <memory>
#include <regex.h>
#include <sstream>
#include <vector>

#ifdef _EMSCRIPTEN
#  include <emscripten/bind.h>
#  include <emscripten/emscripten.h>
#  include <emscripten/html5.h>
#  include <emscripten/val.h>
#endif

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)

#ifdef _EMSCRIPTEN
typedef std::function<void(emscripten::val)> EventCallback_t;
typedef std::pair<emscripten::val, std::string> TargetEventPair_t;
#else
typedef std::function<void()> EventCallback_t;
typedef std::pair<std::string, std::string> TargetEventPair_t;
#endif

typedef std::vector<TargetEventPair_t> TargetEventVec_t;

NAMESPACE_END(webcore)
NAMESPACE_END(sway)

#endif
