// Utility.h
// Helper functions for random numbers, probability checks, and time management.

#ifndef UTILITY_H
#define UTILITY_H

<<<<<<< HEAD
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
=======
class Utility {
public:
    static int randInt(int min, int max);          // Random integer
    static double randReal(double min, double max); // Random double
    static bool checkProbability(double chance);    // True if event occurs
    static bool isDayTime(int commandCount);        // True if day, false if night
};

#endif
>>>>>>> ac8ef0dba7af62ea9c1214bce3c5fd73d1efd64c
