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

  HtmlElement getParentElement() const;

  HtmlElement appendChild(const HtmlElement &child);

  HtmlElement replaceChild(HtmlElement newnode, HtmlElement oldnode);

  HtmlElement removeChild(const HtmlElement &child);

  void setInnerContent(const std::string &content, bool dirty = true);

  void setAttribute(const std::string &key, const std::string &value);

  void addClassName(const std::string &name);

  [[nodiscard]] std::string toString() const;

#ifdef EMSCRIPTEN_PLATFORM
  operator emscripten::val() const { return val_; }

  emscripten::val val_;
#endif
};

NAMESPACE_END(dom)
NAMESPACE_END(webcore)
NAMESPACE_END(sway)

#endif
