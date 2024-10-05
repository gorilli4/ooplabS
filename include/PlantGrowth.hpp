#pragma once

class PlantGrowth
{
private:
  const int upSpeed = 100; // фиксированный рост на 1 метр (100 см) в день (по условию)
  int downSpeed;           // скорость уменьшения высоты ночью
  int desiredHeight;       // желаемая высота

public:
  // конструктор класса для инициализации значений
  PlantGrowth(int down, int desired);

  // метод для расчета количества дней до желаемой высоты
  int calculateDays();
};
