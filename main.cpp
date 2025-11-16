#include "Utility.h"
#include "Constants.h"
#include <iostream>

int main() {
    int commandCount = 0;

    // Check day/night
    if (Utility::isDayTime(commandCount)) {
        std::cout << "It's daytime!" << std::endl;
    } else {
        std::cout << "It's nighttime!" << std::endl;
    }

    // Example: Random placement
    int randomSquare = Utility::randInt(0, 9);
    std::cout << "Random square: " << randomSquare << std::endl;

    // Example: Attack chance
    if (Utility::checkProbability(Constants::HUMAN.attackChance)) {
        std::cout << "Attack successful!" << std::endl;
    } else {
        std::cout << "Attack missed!" << std::endl;
    }

    return 0;
}
