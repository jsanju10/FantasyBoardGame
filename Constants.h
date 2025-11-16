/**
 * @file Constants.h
 * @brief Defines global constants and race statistics for the Fantasy Game.
 */

#ifndef CONSTANTS_H
#define CONSTANTS_H

namespace Constants {

    // Number of commands before switching day/night
    constexpr int COMMANDS_PER_TIME_SWITCH = 5;

    // Race statistics structure
    struct RaceStats {
        int attack;
        double attackChance;
        int defence;
        double defenceChance;
        int health;
        int strength;
    };

    // Predefined race stats
    constexpr RaceStats HUMAN  = {30, 2.0/3.0, 20, 0.5, 60, 100};
    constexpr RaceStats ELF    = {40, 1.0,     10, 0.25, 40, 70};
    constexpr RaceStats DWARF  = {30, 2.0/3.0, 20, 2.0/3.0, 50, 130};
    constexpr RaceStats HOBBIT = {25, 1.0/3.0, 20, 2.0/3.0, 70, 85};

    // Orc stats differ by time of day
    constexpr RaceStats ORC_DAY   = {25, 0.25, 10, 0.25, 50, 130};
    constexpr RaceStats ORC_NIGHT = {45, 1.0,  25, 0.5,  50, 130};

} // namespace Constants

#endif // CONSTANTS_H

