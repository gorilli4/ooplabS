#include "gtest/gtest.h"
#include "../include/PlantGrowth.hpp"

TEST(PlantGrowthTest, LargeHeightTest)
{
  PlantGrowth plant(50, 2000);          // DownSpeed = 50 см, DesiredHeight = 2000 см
  EXPECT_EQ(plant.calculateDays(), 39); // ожидаем 39 дней
}

TEST(PlantGrowthTest, ExtremeNightLossTest)
{
  PlantGrowth plant(100, 1000);         // DownSpeed = 100 см, DesiredHeight = 1000 см
  EXPECT_EQ(plant.calculateDays(), -1); // не может достичь высоты
}

TEST(PlantGrowthTest, LargeDownSpeedTest)
{
  PlantGrowth plant(150, 1000);         // DownSpeed = 150 см, DesiredHeight = 1000 см
  EXPECT_EQ(plant.calculateDays(), -1); // не может достичь высоты
}

TEST(PlantGrowthTest, EqualSpeedTest)
{
  PlantGrowth plant(100, 1000);         // DownSpeed = 100 см, DesiredHeight = 1000 см
  EXPECT_EQ(plant.calculateDays(), -1); // растение не может достичь высоты
}

TEST(PlantGrowthTest, DownSpeedGreaterThanUpSpeedTest)
{
  PlantGrowth plant(150, 500);          // DownSpeed = 150 см, DesiredHeight = 500 см
  EXPECT_EQ(plant.calculateDays(), -1); // растение не может достичь высоты
}

TEST(PlantGrowthTest, AccumulatedGrowthTest)
{
  PlantGrowth plant(80, 1010);          // DownSpeed = 80 см, DesiredHeight = 1010 см
  EXPECT_EQ(plant.calculateDays(), 47); // ожидаемое значение теперь 47 дней
}

TEST(PlantGrowthTest, CombinationTest)
{
  PlantGrowth plant(99, 9999999); // DownSpeed = 99 см, DesiredHeight = 9 999 999 см
  EXPECT_EQ(plant.calculateDays(), 9999900);
}

TEST(PlantGrowthTest, HeightLessThanOneDayGrowthTest)
{
  PlantGrowth plant(10, 50);           // DownSpeed = 10 см, DesiredHeight = 50 см
  EXPECT_EQ(plant.calculateDays(), 1); // достигнет высоты за 1 день
}

// Уменьшение ночью больше, чем двойной дневной рост
TEST(PlantGrowthTest, DoubleDownSpeedTest)
{
  PlantGrowth plant(200, 500);          // DownSpeed = 200 см, DesiredHeight = 500 см
  EXPECT_EQ(plant.calculateDays(), -1); // не может достичь высоты
}

// Уменьшение ночью сильно больше, чем рост днем (экстрем случай)
TEST(PlantGrowthTest, ExtremeDownSpeedTest)
{
  PlantGrowth plant(1000, 10000);       // DownSpeed = 1000 см, DesiredHeight = 10 000 см
  EXPECT_EQ(plant.calculateDays(), -1); // не может достичь высоты
}

TEST(PlantGrowthTest, MinimalHeightTest)
{
  PlantGrowth plant(1, 100);           // DownSpeed = 1 см, DesiredHeight = 100 см
  EXPECT_EQ(plant.calculateDays(), 1); // достигает высоты за 1 день
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
