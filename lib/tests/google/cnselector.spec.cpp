#include <sway/webcore/css/selectors/cnselector.hpp>

#include <gtest/gtest.h>

using namespace sway::webcore;

TEST(CnSelectorTest, getName) {
  auto cn = std::make_shared<CnSelector>((struct CnSelectorChain){.block = "block", .elem = "elm"});
  ASSERT_STREQ(cn->getName().c_str(), "block__elm");
}
