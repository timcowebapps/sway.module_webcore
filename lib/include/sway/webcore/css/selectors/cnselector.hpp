#ifndef SWAY_WEBCORE_CSS_CNSELECTOR_HPP
#define SWAY_WEBCORE_CSS_CNSELECTOR_HPP

#include <sway/emscriptenmacros.hpp>
#include <sway/webcore/css/selector.hpp>
#include <sway/webcore/css/selectors/cnselectorchain.hpp>
#include <sway/webcore/prereqs.hpp>
#include <sway/webcore/treenodeelementdescriptor.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)
NAMESPACE_BEGIN(css)

class CnSelector final : public Selector {
public:
  DECLARE_EMSCRIPTEN_BINDING()

  CnSelector(const CnSelectorChain &chain);

  virtual ~CnSelector() = default;

  [[nodiscard]] auto getMods() const -> std::vector<std::string>;

private:
  CnSelectorChain chain_;
};

NAMESPACE_END(css)
NAMESPACE_END(webcore)
NAMESPACE_END(sway)

#endif
