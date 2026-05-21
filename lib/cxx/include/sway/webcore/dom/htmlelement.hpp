#ifndef SWAY_WEBCORE_DOM_HTMLELEMENT_HPP
#define SWAY_WEBCORE_DOM_HTMLELEMENT_HPP

#include <sway/webcore/prereqs.hpp>

namespace sway::webcore {

class HtmlElement;

namespace HtmlElementTypedefs {
using UniquePtr_t = std::unique_ptr<HtmlElement>;
using SharedPtr_t = std::shared_ptr<HtmlElement>;
}  // namespace HtmlElementTypedefs

class HtmlElement {
  DECLARE_EMSCRIPTEN_BINDING()

public:
  static auto makeUniquePtr(const emscripten::val &val = emscripten::val::null()) -> HtmlElementTypedefs::SharedPtr_t {
    if (val.isNull() || val.isUndefined()) {
      return HtmlElementTypedefs::SharedPtr_t(new HtmlElement());
    }

    return HtmlElementTypedefs::SharedPtr_t(new HtmlElement(val));
  }

  HtmlElement() noexcept;

  explicit HtmlElement(const emscripten::val &value);

  HtmlElement(const HtmlElement &) = delete;

  HtmlElement(HtmlElement &&other) noexcept;

  HtmlElement &operator=(HtmlElement &&other) noexcept;

  ~HtmlElement() = default;

  [[nodiscard]]
  auto getParentElement() const -> HtmlElementTypedefs::SharedPtr_t;

  auto appendChild(HtmlElementTypedefs::SharedPtr_t child) -> HtmlElementTypedefs::SharedPtr_t;

  auto replaceChild(HtmlElementTypedefs::SharedPtr_t newChild, HtmlElementTypedefs::SharedPtr_t oldChild)
      -> HtmlElementTypedefs::SharedPtr_t;

  auto removeChild(HtmlElementTypedefs::SharedPtr_t child) -> HtmlElementTypedefs::SharedPtr_t;

  void setInnerContent(const std::string &content, bool dirty = true);

  void setAttribute(const std::string &key, const std::string &value);

  void addClassName(const std::string &name);

  void removeClassName(const std::string &name);

  [[nodiscard]]
  auto hasClassName(const std::string &name) const -> bool;

  [[nodiscard]]
  auto toString() const -> std::string;

  [[nodiscard]]
  auto getJsValue() const -> const emscripten::val & {
    return jsValue_;
  }

  operator emscripten::val() const { return jsValue_; }

  emscripten::val jsValue_;
};

}  // namespace sway::webcore

#endif
