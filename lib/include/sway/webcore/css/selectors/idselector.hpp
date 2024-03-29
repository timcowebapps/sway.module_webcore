#ifndef SWAY_WEBCORE_CSS_IDSELECTOR_HPP
#define SWAY_WEBCORE_CSS_IDSELECTOR_HPP

#include <sway/emscriptenmacros.hpp>
#include <sway/webcore/css/selector.hpp>
#include <sway/webcore/prereqs.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)
NAMESPACE_BEGIN(css)

class IdSelector final : public Selector {
public:
  DECLARE_EMSCRIPTEN_BINDING()

  IdSelector(const std::string &name);

  virtual ~IdSelector() = default;
};

NAMESPACE_END(css)
NAMESPACE_END(webcore)
NAMESPACE_END(sway)

#endif
