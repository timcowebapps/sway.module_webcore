#include <sway/webcore/dom/htmlelement.hpp>

namespace sway::webcore {

HtmlElement::HtmlElement() noexcept
    : jsValue_(emscripten::val::null()) {}

HtmlElement::HtmlElement(const emscripten::val &value)
    : jsValue_(value) {}

HtmlElement::HtmlElement(HtmlElement &&other) noexcept
    : jsValue_(std::move(other.jsValue_)) {
  other.jsValue_ = emscripten::val::null();
}

HtmlElement &HtmlElement::operator=(HtmlElement &&other) noexcept {
  if (this != &other) {
    jsValue_ = std::move(other.jsValue_);
    other.jsValue_ = emscripten::val::null();
  }

  return *this;
}

auto HtmlElement::getParentElement() const -> HtmlElementTypedefs::UniquePtr_t {
  emscripten::val parent = jsValue_["parentElement"];
  if (parent.isNull() || parent.isUndefined()) {
    return HtmlElement::makeUniquePtr();
  }

  return HtmlElement::makeUniquePtr(parent);
}

auto HtmlElement::appendChild(HtmlElementTypedefs::UniquePtr_t child) -> HtmlElementTypedefs::UniquePtr_t {
  HtmlElement *concreteChild = dynamic_cast<HtmlElement *>(child.get());
  if (!concreteChild) {
    throw std::runtime_error("HtmlElement: Child is not of type HtmlElement");
  }

  emscripten::val result = jsValue_.call<emscripten::val>("appendChild", concreteChild->getJsValue());
  if (result.isNull() || result.isUndefined()) {
    throw std::runtime_error("HtmlElement: Failed to append child");
  }

  return HtmlElement::makeUniquePtr(result);
}

auto HtmlElement::replaceChild(HtmlElementTypedefs::UniquePtr_t newChild, HtmlElementTypedefs::UniquePtr_t oldChild)
    -> HtmlElementTypedefs::UniquePtr_t {
  HtmlElement *concreteNewChild = dynamic_cast<HtmlElement *>(newChild.get());
  HtmlElement *concreteOldChild = dynamic_cast<HtmlElement *>(oldChild.get());
  if (!concreteNewChild || !concreteOldChild) {
    throw std::runtime_error("HtmlElement: Children are not of type HtmlElement");
  }

  emscripten::val result =
      jsValue_.call<emscripten::val>("replaceChild", concreteNewChild->getJsValue(), concreteOldChild->getJsValue());
  if (result.isNull() || result.isUndefined()) {
    throw std::runtime_error("HtmlElement: Failed to replace child");
  }

  return HtmlElement::makeUniquePtr(result);
}

auto HtmlElement::removeChild(HtmlElementTypedefs::UniquePtr_t child) -> HtmlElementTypedefs::UniquePtr_t {
  HtmlElement *concreteChild = dynamic_cast<HtmlElement *>(child.get());
  if (!concreteChild) {
    throw std::runtime_error("HtmlElement: Child is not of type HtmlElement");
  }

  emscripten::val result = jsValue_.call<emscripten::val>("removeChild", concreteChild->getJsValue());
  if (result.isNull() || result.isUndefined()) {
    throw std::runtime_error("HtmlElement: Failed to remove child");
  }

  return HtmlElement::makeUniquePtr(result);
}

void HtmlElement::setInnerContent(const std::string &content, bool dirty) {
  if (content.length() > 1024 * 1024) {
    throw std::invalid_argument("HtmlElement: Content size exceeds 1MB limit");
  }

  jsValue_.set(core::format("inner%s", dirty ? "HTML" : "Text"), content);
}

void HtmlElement::setAttribute(const std::string &key, const std::string &value) {
  if (key.empty()) {
    throw std::invalid_argument("HtmlElement: Attribute key cannot be empty");
  }

  jsValue_.call<void>("setAttribute", emscripten::val(key), emscripten::val(value));
}

void HtmlElement::addClassName(const std::string &name) {
  if (name.empty()) {
    throw std::invalid_argument("HtmlElement: Class name cannot be empty");
  }

  if (name.find(' ') != std::string::npos) {
    throw std::invalid_argument("HtmlElement: Class name cannot contain spaces");
  }

  jsValue_["classList"].call<void>("add", emscripten::val(name));
}

void HtmlElement::removeClassName(const std::string &name) {
  if (name.empty()) {
    throw std::invalid_argument("HtmlElement: Class name cannot be empty");
  }

  jsValue_["classList"].call<void>("remove", emscripten::val(name));
}

auto HtmlElement::hasClassName(const std::string &name) const -> bool {
  if (name.empty()) {
    return false;
  }

  return jsValue_["classList"].call<bool>("contains", emscripten::val(name));
}

auto HtmlElement::toString() const -> std::string { return jsValue_.call<std::string>("toString"); }

}  // namespace sway::webcore
