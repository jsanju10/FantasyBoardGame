// Constants.h
// Stores game configuration values and race stats.

#ifndef CONSTANTS_H
#define CONSTANTS_H

<<<<<<< HEAD
/**
 * Constants and race stat templates used across the project.
 */

namespace Constants {

// Commands per day/night toggle
constexpr int COMMANDS_PER_TIME_SWITCH = 5;

struct RaceStats {
    int attack;
    double attackChance;
    int defence;
    double defenceChance;
    int health;
    int strength;
};

constexpr RaceStats HUMAN  = {30, 2.0/3.0, 20, 1.0/2.0, 60, 100};
constexpr RaceStats ELF    = {40, 1.0,     10, 1.0/4.0, 40, 70};
constexpr RaceStats DWARF  = {30, 2.0/3.0, 20, 2.0/3.0, 50, 130};
constexpr RaceStats HOBBIT = {25, 1.0/3.0, 20, 2.0/3.0, 70, 85};

// Orc: day vs night
constexpr RaceStats ORC_DAY   = {25, 1.0/4.0, 10, 1.0/4.0, 50, 130};
constexpr RaceStats ORC_NIGHT = {45, 1.0,    25, 1.0/2.0, 50, 130};

} // namespace Constants

#endif // CONSTANTS_H
=======
namespace Constants {

    // Switch day/night after this many commands
    const int COMMANDS_PER_TIME_SWITCH = 5;

    // Structure for race stats
    struct RaceStats {
        int attack;
        double attackChance;
        int defence;
        double defenceChance;
        int health;
        int strength;
    };

    // Race definitions
    const RaceStats HUMAN  = {30, 0.66, 20, 0.50, 60, 100};
    const RaceStats ELF    = {40, 1.00, 10, 0.25, 40, 70};
    const RaceStats DWARF  = {30, 0.66, 20, 0.66, 50, 130};
    const RaceStats HOBBIT = {25, 0.33, 20, 0.66, 70, 85};

    // Orc stats differ by time of day
    const RaceStats ORC_DAY   = {25, 0.25, 10, 0.25, 50, 130};
    const RaceStats ORC_NIGHT = {45, 1.00, 25, 0.50, 50, 130};

} // namespace Constants


>>>>>>> ac8ef0dba7af62ea9c1214bce3c5fd73d1efd64c
