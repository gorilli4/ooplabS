#include "days_to_reach_height.h"

int daysToReachHeight(int upSpeed, int downSpeed, int needHeight) {
    // Если растение не может расти из-за слишком большого ночного уменьшения
    if (upSpeed <= downSpeed && upSpeed < needHeight) return -1;

    // Вычисляем количество дней, используя формулу
    int days = (needHeight - downSpeed - 1) / (upSpeed - downSpeed) + 1;
    return days;
}