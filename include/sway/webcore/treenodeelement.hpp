#ifndef SWAY_WEBCORE_TREENODEELEMENT_HPP
#define SWAY_WEBCORE_TREENODEELEMENT_HPP

#include <sway/webcore/css/selector.hpp>
#include <sway/webcore/eventhandler.hpp>
#include <sway/webcore/eventtarget.hpp>
#include <sway/webcore/prereqs.hpp>
#include <sway/webcore/region.hpp>
#include <sway/webcore/regioncreateinfo.hpp>
#include <sway/webcore/treenodeelementdescriptor.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)

class TreeNodeElement : public core::container::Node {
public:
  static void registerEmClass();

  TreeNodeElement(const TreeNodeElementDescriptor &createInfo);
  virtual ~TreeNodeElement() = default;

  void addRegion(const std::string &name, const RegionCreateInfo &createInfo);

  std::shared_ptr<Region> getRegion(const std::string &name) const;

  std::shared_ptr<Region> getRegionByNodeIdx(const std::string &nodeIdx) const;

  RegionMap_t getRegions();

  void addEvent(const std::string &targetId, const std::string &type
#ifdef _EMSCRIPTEN
      ,
      emscripten::val callback
#endif
  );

  void bindEvents();

  std::string getHtmlElementTagname() const;

  void setHtmlElementTagname(const std::string &tagname);

  std::vector<std::string> getHtmlElementClasses() const;

  void setHtmlElementClasses(const std::vector<std::string> &classes);

  std::string getHtmlElementId() const;

  void setHtmlElementId(const std::string &id);

  std::string getHtmlContent() const;

  void setHtmlContent(const std::string &content);

#pragma endregion

private:
  RegionMap_t regions_; /*!< Карта регионов. */
  std::vector<EventHandler> handlers_;
  std::string htmlElementTagname_; /*!< Имя тега. */
  std::vector<std::string> htmlElementClasses_;
  std::string htmlElementId_; /*!< Уникальный идентификатор. */
  std::string htmlContent_;
};

NAMESPACE_END(webcore)
NAMESPACE_END(sway)

#endif
