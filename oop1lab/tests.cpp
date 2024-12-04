#include "gtest/gtest.h"
#include "days_to_reach_height.h"

// Тестирование функции daysToReachHeight
TEST(DaysToReachHeightTest, BasicTests) {
    EXPECT_EQ(daysToReachHeight(100, 10, 910), 10);
    EXPECT_EQ(daysToReachHeight(10, 5, 25), 4);
    EXPECT_EQ(daysToReachHeight(5, 1, 6), 2);
}

TEST(DaysToReachHeightTest, ImpossibleCase) {
    EXPECT_EQ(daysToReachHeight(1, 1, 10), -1);
}

TEST(DaysToReachHeightTest, EdgeCases) {
    EXPECT_EQ(daysToReachHeight(5, 0, 5), 1);
    EXPECT_EQ(daysToReachHeight(5, 4, 5), 1);
    EXPECT_EQ(daysToReachHeight(5, 4, 9), 5);
}