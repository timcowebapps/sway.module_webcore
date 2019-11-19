#ifndef _SWAY_WEBCORE_PREREQS_H
#define _SWAY_WEBCORE_PREREQS_H

#include <sway/core.h>

#include <emscripten/html5.h>
#include <emscripten/emscripten.h>
#include <emscripten/bind.h>
#include <emscripten/val.h>
#include <memory>
#include <vector>
#include <map>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)

NAMESPACE_BEGIN(mvc)

NAMESPACE_BEGIN(model)
class Observable;
class AbstractModel;
typedef std::shared_ptr<class AbstractModel> ModelSmartPtr_t;
NAMESPACE_END(model)

NAMESPACE_BEGIN(view)
class Region;
class ViewComponent;
class IObserver;
typedef std::vector<class IObserver *> ObserverArray_t;
typedef ObserverArray_t::const_iterator ObserverArrayIterator_t;
typedef std::shared_ptr<class Region> RegionPtr_t;
typedef std::map<std::string, class ViewComponent *> ViewMap_t;
typedef ViewMap_t::const_iterator ViewIterator_t;
NAMESPACE_END(view)

NAMESPACE_END(mvc)

typedef std::function<void(emscripten::val)> EventCallback_t;
typedef std::pair<emscripten::val, std::string> TargetEventPair_t;
typedef std::vector<TargetEventPair_t> TargetEventVec_t;

NAMESPACE_END(webcore)
NAMESPACE_END(sway)

#endif // _SWAY_WEBCORE_PREREQS_H
