#include <gtest/gtest.h>

#include "hello.h"

TEST(hello, test_case1)
{
    EXPECT_EQ(0, test(1,0));
}

TEST(hello, test_case2)
{
    EXPECT_EQ(0, test(1,2));
}

TEST(hello, test_case3)
{
    EXPECT_EQ(1, test(1,1));
}