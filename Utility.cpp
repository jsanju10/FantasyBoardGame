/**
 * @file Utility.cpp
 * @brief Implements helper functions for randomization and time management.
 */

#include "Utility.h"
#include "Constants.h"

int Utility::randInt(int min, int max) {
    static std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<int> dist(min, max);
    return dist(rng);
}

double Utility::randReal(double min, double max) {
    static std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
    std::uniform_real_distribution<double> dist(min, max);
    return dist(rng);
}

bool Utility::checkProbability(double chance) {
    return randReal(0.0, 1.0) <= chance;
}

bool Utility::isDayTime(int commandCount) {
    return (commandCount / Constants::COMMANDS_PER_TIME_SWITCH) % 2 == 0;
}
