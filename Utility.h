#ifndef UTILITY_H
#define UTILITY_H

/**
 * Utility functions: RNG, probability, and day/night toggling.
 *
 * This is a small static utility class used by many modules.
 */

class Utility {
public:
    static int randInt(int min, int max);
    static double randReal(double min, double max);
    static bool probability(double chance);

    // day/night state
    static void toggleDayNight(); // flip internal flag
    static bool isNight();        // true if night, false if day

private:
    // no instances
    Utility() = delete;
};

#endif // UTILITY_H
