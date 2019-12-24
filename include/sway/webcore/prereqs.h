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

NAMESPACE_BEGIN(model)
class Observable;
class AbstractItemModel;
typedef std::shared_ptr<class AbstractItemModel> ModelSmartPtr_t;
NAMESPACE_END(model)

NAMESPACE_BEGIN(view)
class Region;
class IObserver;
typedef std::vector<class IObserver *> ObserverArray_t;
typedef ObserverArray_t::const_iterator ObserverArrayIterator_t;
NAMESPACE_END(view)

typedef std::function<void(emscripten::val)> EventCallback_t;
typedef std::pair<emscripten::val, std::string> TargetEventPair_t;
typedef std::vector<TargetEventPair_t> TargetEventVec_t;

NAMESPACE_END(webcore)
NAMESPACE_END(sway)

#endif // _SWAY_WEBCORE_PREREQS_H
