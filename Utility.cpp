// Utility.cpp
// Implements helper functions.

#include "Utility.h"
#include "Constants.h"
#include <random>
#include <chrono>

// Generate random integer between min and max
int Utility::randInt(int min, int max) {
    static std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<int> dist(min, max);
    return dist(rng);
}

// Generate random double between min and max
double Utility::randReal(double min, double max) {
    static std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
    std::uniform_real_distribution<double> dist(min, max);
    return dist(rng);
}

// Check if event occurs based on probability (0.0 to 1.0)
bool Utility::checkProbability(double chance) {
    return randReal(0.0, 1.0) <= chance;
}

// Determine if it's day or night based on command count
bool Utility::isDayTime(int commandCount) {
    return (commandCount / Constants::COMMANDS_PER_TIME_SWITCH) % 2 == 0;
}

