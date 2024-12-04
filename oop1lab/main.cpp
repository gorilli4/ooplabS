#include <iostream>
#include "days_to_reach_height.h"

int main() {
    int upSpeed, downSpeed, needHeight;
    std::cout << "Введите значения роста растения, его уменьшения и нобходимую высоту: ";
    std::cin >> upSpeed >> downSpeed >> needHeight;

    int result = daysToReachHeight(upSpeed, downSpeed, needHeight);

    if (result == -1) {
        std::cout << "Растение никогда не достигнет указанной высоты." << std::endl;
    } else {
        std::cout << "Дней, через сколько растение достигнет указанной высоты: " << result << std::endl;
    }
    return 0;
}