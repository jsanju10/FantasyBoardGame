<<<<<<< HEAD
#include "Utility.h"
#include <random>
#include <chrono>

static std::mt19937 &rng() {
    static std::mt19937 gen((unsigned)std::chrono::steady_clock::now().time_since_epoch().count());
    return gen;
}

int Utility::randInt(int min, int max) {
    std::uniform_int_distribution<int> dist(min, max);
    return dist(rng());
}

double Utility::randReal(double min, double max) {
    std::uniform_real_distribution<double> dist(min, max);
    return dist(rng());
}

bool Utility::probability(double chance) {
    return randReal(0.0, 1.0) <= chance;
}

// simple internal day/night flag:
static bool _isNight = false;

void Utility::toggleDayNight() {
    _isNight = !_isNight;
}

bool Utility::isNight() {
    return _isNight;
}
=======
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

>>>>>>> ac8ef0dba7af62ea9c1214bce3c5fd73d1efd64c
