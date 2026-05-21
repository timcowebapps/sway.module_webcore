#ifndef SWAY_WEBCORE_TREENODEELEMENT_HPP
#define SWAY_WEBCORE_TREENODEELEMENT_HPP

#include <sway/emscriptenmacros.hpp>
#include <sway/webcore/css/selector.hpp>
#include <sway/webcore/eventhandler.hpp>
#include <sway/webcore/eventtarget.hpp>
#include <sway/webcore/prereqs.hpp>
#include <sway/webcore/region.hpp>
#include <sway/webcore/regioncreateinfo.hpp>
#include <sway/webcore/treenodeelementdescriptor.hpp>

namespace sway::webcore {

class TreeNodeElement : public core::Node {
  DECLARE_EMSCRIPTEN_BINDING()

public:
  TreeNodeElement(const TreeNodeElementDescriptor &descriptor);

  virtual ~TreeNodeElement() = default;

  void addRegionImpl(const std::string &name, const RegionCreateInfo &createInfo);

  void addRegion(const std::string &name, emscripten::val createInfo);

  auto getRegion(const std::string &name) const -> std::shared_ptr<Region>;

  auto getRegionByNodeIdx(const core::NodeIndex &nodeIdx) const -> std::shared_ptr<Region>;

  auto getRegions() -> RegionMap_t;

  void addEvent(const std::string &targetId, const std::string &type, emscripten::val callback);

  void bindEvents();

  auto getHtmlElementTagname() const -> std::string;

  void setHtmlElementTagname(const std::string &tagname);

  auto getHtmlElementClasses() const -> std::vector<std::string>;

  void setHtmlElementClasses(const std::vector<std::string> &classes);

  auto getHtmlElementId() const -> std::string;

  void setHtmlElementId(const std::string &id);

  auto getHtmlContent() const -> std::string;

  void setHtmlContent(const std::string &content);

private:
  RegionMap_t regions_;  //!< Карта регионов.
  std::vector<EventHandler> handlers_;
  std::string htmlElementTagname_;  //!< Имя тега.
  std::vector<std::string> htmlElementClasses_;
  std::string htmlElementId_;  //!< Уникальный идентификатор.
  std::string htmlContent_;
};

}  // namespace sway::webcore

#endif
