#include <sway/webcore/css/stylesheet.hpp>

#include <gtest/gtest.h>

using namespace sway::webcore;

TEST(StyleSheetTest, getName) {
  Mapper_t mapper = {{"block__elem--1", "ab-1"}, {"block__elem--2", "ab-2"}};

  auto ss = std::make_shared<StyleSheet>(mapper);
  ASSERT_STREQ(ss->getClassName("block__elem--1").c_str(), "ab-1");
}
