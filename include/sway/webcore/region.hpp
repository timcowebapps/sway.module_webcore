#ifndef SWAY_WEBCORE_REGION_HPP
#define SWAY_WEBCORE_REGION_HPP

#include <sway/webcore/prereqs.hpp>
#include <sway/webcore/regioncreateinfo.hpp>

NAMESPACE_BEGIN(sway)
NAMESPACE_BEGIN(webcore)

typedef std::map<std::string, std::shared_ptr<class Region>> RegionMap_t;
typedef RegionMap_t::const_iterator RegionMapIterator_t;

class TreeNodeElement;
class Region {
public:
  static void registerEmClass();

  Region(std::shared_ptr<TreeNodeElement> parent, const RegionCreateInfo &createInfo);
  virtual ~Region() = default;

  void attachView(std::shared_ptr<TreeNodeElement> node);

  void detachView(TreeNodeElement *node);

  std::string getAttachedNodeIdx() const;

  std::string getHtmlElementId() const;

  bool hasHtmlElementReplaced() const;
  bool hasAttached() const;

private:
  std::shared_ptr<TreeNodeElement> parent_;
  std::string attachedNodeIdx_;
  std::string htmlElementId_;
  bool htmlElementReplace_;
  bool attached_;
};

NAMESPACE_END(webcore)
NAMESPACE_END(sway)

#endif
