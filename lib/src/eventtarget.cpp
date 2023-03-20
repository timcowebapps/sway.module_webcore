#include <sway/webcore/dom/htmldocument.hpp>
#include <sway/webcore/eventtarget.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)

EventTarget::EventTarget(EventCallback_t callback)
#ifdef EMSCRIPTEN_PLATFORM
    : listener_(EventListener(callback))
#endif
{
}

EventTarget::~EventTarget() {
#ifdef EMSCRIPTEN_PLATFORM
  for (TargetEventPair_t &event : events_) {
    event.first.call<void>("removeEventListener", event.second, listener_);
  }

  listener_.call<void>("delete");
#endif
}

void EventTarget::addEventListener(const std::string &targetId, const std::string &type) {
#ifdef EMSCRIPTEN_PLATFORM
  emscripten::val target = dom::HtmlDocument::getElementById(targetId);
  target.call<void>("addEventListener", type, listener_);
  events_.emplace_back(target, type);
#endif
}

void EventTarget::setCallback(EventCallback_t callback) {
#ifdef EMSCRIPTEN_PLATFORM
  listener_.as<EventListener &>().callback_ = callback;
#endif
}

NAMESPACE_END(webcore)
NAMESPACE_END(sway)
