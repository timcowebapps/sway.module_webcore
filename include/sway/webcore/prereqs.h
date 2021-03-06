#ifndef _SWAY_WEBCORE_PREREQS_H
#define _SWAY_WEBCORE_PREREQS_H

#include <sway/core.h>

#include <emscripten/emscripten.h>
#include <emscripten/html5.h>
#include <emscripten/bind.h>
#include <emscripten/val.h>
#include <sstream>
#include <memory>
#include <vector>
#include <deque>
#include <map>
#include <functional>
#include <regex.h>
#include <algorithm>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)

typedef std::function<void(emscripten::val)> EventCallback_t;
typedef std::pair<emscripten::val, std::string> TargetEventPair_t;
typedef std::vector<TargetEventPair_t> TargetEventVec_t;

NAMESPACE_END(webcore)
NAMESPACE_END(sway)

#endif // _SWAY_WEBCORE_PREREQS_H
