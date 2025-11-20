#ifndef CONSTANTS_H
#define CONSTANTS_H

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
