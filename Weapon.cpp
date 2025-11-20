<<<<<<< HEAD
#include "Weapon.h"
#include "Character.h"

void Weapon::applyEffect(Character &c) {
    // Pseudocode:
    //   c.modifyAttack(+attackBoost_);
    c.modifyAttack(attackBoost_);
}
void Weapon::removeEffect(Character &c) {
    // Pseudocode:
    //   c.modifyAttack(-attackBoost_);
    c.modifyAttack(-attackBoost_);
}
=======
#include "Weapon.h"
#include "Character.h"

// when player pick up weapon
void Weapon::applyEffect(Character &c)
{
    // teacher said members can be public or use setter/getter.
    // For simplicity I follow assignment style and access directly.
    c.attack = c.attack + attackBoost;
}

// when player drop weapon
void Weapon::removeEffect(Character &c)
{
    c.attack = c.attack - attackBoost;
}
>>>>>>> ac8ef0dba7af62ea9c1214bce3c5fd73d1efd64c
