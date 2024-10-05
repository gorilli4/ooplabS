#include "../include/PlantGrowth.hpp"

PlantGrowth::PlantGrowth(int down, int desired) : downSpeed(down), desiredHeight(desired) {}

int PlantGrowth::calculateDays()
{
  if (downSpeed >= upSpeed && desiredHeight > upSpeed)
  {
    return -1; // случай, когда нельзя достичь высоты, те скорость уменьшения >= росту
  }

  int currentHeight = 0; // первоначальная высота 0 по условию
  int days = 0;

  while (currentHeight < desiredHeight)
  {
    days++;
    currentHeight += upSpeed; // растение растет на 100 см (1 метр) днем по условию
    if (currentHeight >= desiredHeight)
      break;                    // выход из цикла, когда достигли нужной высоты
    currentHeight -= downSpeed; // уменьшение высоты растения ночью
  }

  return days;
}
