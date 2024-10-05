#include <iostream>
#include "include/PlantGrowth.hpp"

int main()
{
  int downSpeed, desiredHeight;

  std::cout << "Введите скорость уменьшения высоты ночью (downSpeed в см): ";
  std::cin >> downSpeed;

  std::cout << "Введите желаемую высоту растения (desiredHeight в см): ";
  std::cin >> desiredHeight;

  PlantGrowth plant(downSpeed, desiredHeight);

  int days = plant.calculateDays();
  std::cout << "Количество дней для достижения высоты " << desiredHeight << " см составляет: " << days << std::endl;

  return 0;
}
