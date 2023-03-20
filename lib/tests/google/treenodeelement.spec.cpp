#include <sway/webcore/treenodeelement.hpp>

#include <gtest/gtest.h>

using namespace sway::webcore;

TEST(TreeNodeElementTest, getHtmlElementTagname) {
  auto elem = std::make_shared<TreeNodeElement>((struct TreeNodeElementDescriptor){.tagname = "div"});
  ASSERT_STREQ(elem->getHtmlElementTagname().c_str(), "div");

  elem->addRegion("test_name", (struct RegionCreateInfo){.id = "test_id", .replace = true});

  auto region = elem->getRegion("test_name");
}
