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
