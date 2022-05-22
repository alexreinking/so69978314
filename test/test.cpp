// test/test.cpp
#include <myLib.h>

#include <gtest/gtest.h>

namespace {

TEST(MyLibTest, Success) { ASSERT_TRUE(validate_xml("<element/>")); }
TEST(MyLibTest, Fail) { ASSERT_FALSE(validate_xml("<foo></bar>")); }

} // namespace
