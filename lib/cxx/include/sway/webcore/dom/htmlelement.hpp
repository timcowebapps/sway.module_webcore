#ifndef SWAY_WEBCORE_DOM_HTMLELEMENT_HPP
#define SWAY_WEBCORE_DOM_HTMLELEMENT_HPP

#include <sway/webcore/prereqs.hpp>

namespace sway::webcore {

class IHtmlElement {
public:
  virtual ~IHtmlElement() = default;

  [[nodiscard]]
  virtual auto getParentElement() const -> std::unique_ptr<IHtmlElement> = 0;

  virtual auto appendChild(std::unique_ptr<IHtmlElement> child) -> std::unique_ptr<IHtmlElement> = 0;

  virtual auto replaceChild(std::unique_ptr<IHtmlElement> newChild, std::unique_ptr<IHtmlElement> oldChild)
      -> std::unique_ptr<IHtmlElement> = 0;

  virtual auto removeChild(std::unique_ptr<IHtmlElement> child) -> std::unique_ptr<IHtmlElement> = 0;

  virtual void setInnerContent(const std::string &content, bool dirty = true) = 0;

  virtual void setAttribute(const std::string &key, const std::string &value) = 0;

  virtual void addClassName(const std::string &name) = 0;

  virtual void removeClassName(const std::string &name) = 0;

  [[nodiscard]]
  virtual auto hasClassName(const std::string &name) const -> bool = 0;

  [[nodiscard]]
  virtual auto toString() const -> std::string = 0;
};

namespace HtmlElementTypedefs {
using UniquePtr_t = std::unique_ptr<IHtmlElement>;
}

class HtmlElement : public IHtmlElement {
public:
  static auto makeUniquePtr(const emscripten::val &val = emscripten::val::null()) -> HtmlElementTypedefs::UniquePtr_t {
    if (val.isNull() || val.isUndefined()) {
      return HtmlElementTypedefs::UniquePtr_t(new HtmlElement());
    }

    return HtmlElementTypedefs::UniquePtr_t(new HtmlElement(val));
  }

  HtmlElement() noexcept;

  explicit HtmlElement(const emscripten::val &value);

  HtmlElement(const HtmlElement &) = delete;

  HtmlElement(HtmlElement &&other) noexcept;

  HtmlElement &operator=(HtmlElement &&other) noexcept;

  ~HtmlElement() override = default;

  [[nodiscard]]
  auto getParentElement() const -> HtmlElementTypedefs::UniquePtr_t override;

  auto appendChild(HtmlElementTypedefs::UniquePtr_t child) -> HtmlElementTypedefs::UniquePtr_t override;

  auto replaceChild(HtmlElementTypedefs::UniquePtr_t newChild, HtmlElementTypedefs::UniquePtr_t oldChild)
      -> HtmlElementTypedefs::UniquePtr_t override;

  auto removeChild(HtmlElementTypedefs::UniquePtr_t child) -> HtmlElementTypedefs::UniquePtr_t override;

  void setInnerContent(const std::string &content, bool dirty = true) override;

  void setAttribute(const std::string &key, const std::string &value) override;

  void addClassName(const std::string &name) override;

  void removeClassName(const std::string &name) override;

  [[nodiscard]]
  auto hasClassName(const std::string &name) const -> bool override;

  [[nodiscard]]
  auto toString() const -> std::string override;

  [[nodiscard]]
  auto getJsValue() const -> const emscripten::val & {
    return jsValue_;
  }

  operator emscripten::val() const { return jsValue_; }

  emscripten::val jsValue_;
};

}  // namespace sway::webcore

#endif
