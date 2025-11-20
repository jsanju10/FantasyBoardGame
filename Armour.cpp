<<<<<<< HEAD
#include "Armour.h"
#include "Character.h"

void Armour::applyEffect(Character &c) {
    c.modifyDefence(defenceBoost_);
    if (attackPenalty_ != 0) c.modifyAttack(-attackPenalty_);
}

void Armour::removeEffect(Character &c) {
    c.modifyDefence(-defenceBoost_);
    if (attackPenalty_ != 0) c.modifyAttack(+attackPenalty_);
}
=======
#include "Armour.h"
#include "Character.h"

// when wearing armour
void Armour::applyEffect(Character &c)
{
    c.defence = c.defence + defenceBoost;
    c.attack = c.attack - attackPenalty;   // some armour reduce attack
}

// when removing armour
void Armour::removeEffect(Character &c)
{
    c.defence = c.defence - defenceBoost;
    c.attack = c.attack + attackPenalty;
}
>>>>>>> ac8ef0dba7af62ea9c1214bce3c5fd73d1efd64c
