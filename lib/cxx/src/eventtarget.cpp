#include <sway/webcore/dom/htmldocument.hpp>
#include <sway/webcore/eventtarget.hpp>

namespace sway::webcore {

EventTarget::EventTarget(EventCallback_t callback)
    : listener_(EventListener(callback)) {}

EventTarget::~EventTarget() {
  for (TargetEventPair_t &event : events_) {
    event.first.call<void>("removeEventListener", event.second, listener_);
  }

  listener_.call<void>("delete");
}

void EventTarget::addEventListener(const std::string &targetId, const std::string &type) {
  emscripten::val target = dynamic_cast<HtmlElement *>(HtmlDocument::getElementById(targetId).get())->getJsValue();
  target.call<void>("addEventListener", type, listener_);
  events_.emplace_back(target, type);
}

void EventTarget::setCallback(EventCallback_t callback) { listener_.as<EventListener &>().callback_ = callback; }

}  // namespace sway::webcore
