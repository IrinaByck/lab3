#include <gtest/gtest.h>
#include "../include/Square.h"

TEST(SimpleTest, Test1_SquareCenter) {
    Square s(0, 0, 2, 0, 2, 2, 0, 2);
    EXPECT_EQ(s.getCenter().first, 1.0);
}

TEST(SimpleTest, Test2_SquareArea) {
    Square s(0, 0, 2, 0, 2, 2, 0, 2);
    EXPECT_EQ(static_cast<double>(s), 4.0);
}

TEST(SimpleTest, Test3_SquareEqual) {
    Square s1(0, 0, 2, 0, 2, 2, 0, 2);
    Square s2(0, 0, 2, 0, 2, 2, 0, 2);
    EXPECT_TRUE(s1 == s2);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
