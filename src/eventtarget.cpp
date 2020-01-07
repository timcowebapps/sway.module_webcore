#include <sway/webcore/eventtarget.h>
#include <sway/webcore/dom/htmldocument.h>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)

EventTarget::EventTarget(EventCallback_t callback)
	: _listener(EventListener(callback)) {
	// Empty
}

EventTarget::~EventTarget() {
	for (TargetEventPair_t & event: _events)
		event.first.call<void>("removeEventListener", event.second, _listener);

	_listener.call<void>("delete");
}

void EventTarget::addEventListener(const std::string & targetId, const std::string & type) {
	emscripten::val target = dom::HtmlDocument::getElementById(targetId);
	target.call<void>("addEventListener", type, _listener);
	_events.emplace_back(target, type);
}

void EventTarget::setCallback(EventCallback_t callback) {
	_listener.as<EventListener &>()._callback = callback;
}

NAMESPACE_END(webcore)
NAMESPACE_END(sway)
