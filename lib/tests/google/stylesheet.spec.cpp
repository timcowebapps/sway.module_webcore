#include <sway/webcore/css/stylesheet.hpp>

#include <gtest/gtest.h>

using namespace sway::webcore;

TEST(StyleSheetTest, getName) {
  css::Mapper_t mapper = {{"block__elem--1", "ab-1"}, {"block__elem--2", "ab-2"}};

  auto ss = std::make_shared<css::StyleSheet>(mapper);
  ASSERT_STREQ(ss->getClassName("block__elem--1").c_str(), "ab-1");
}
