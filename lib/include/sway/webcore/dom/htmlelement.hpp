#ifndef SWAY_WEBCORE_DOM_HTMLELEMENT_HPP
#define SWAY_WEBCORE_DOM_HTMLELEMENT_HPP

#include <sway/webcore/prereqs.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)
NAMESPACE_BEGIN(dom)

class HtmlElement {
public:
  HtmlElement();

#ifdef EMSCRIPTEN_PLATFORM
  HtmlElement(const emscripten::val &value);
#endif

  ~HtmlElement() = default;

  auto getParentElement() const -> HtmlElement;

  auto appendChild(const HtmlElement &child) -> HtmlElement;

  auto replaceChild(HtmlElement newnode, HtmlElement oldnode) -> HtmlElement;

  auto removeChild(const HtmlElement &child) -> HtmlElement;

  void setInnerContent(const std::string &content, bool dirty = true);

  void setAttribute(const std::string &key, const std::string &value);

  void addClassName(const std::string &name);

  [[nodiscard]] auto toString() const -> std::string;

#ifdef EMSCRIPTEN_PLATFORM
  operator emscripten::val() const { return val_; }

  emscripten::val val_;
#endif
};

NAMESPACE_END(dom)
NAMESPACE_END(webcore)
NAMESPACE_END(sway)

#endif
