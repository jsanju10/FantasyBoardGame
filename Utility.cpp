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
