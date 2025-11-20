<<<<<<< HEAD
#include "Shield.h"
#include "Character.h"

void Shield::applyEffect(Character &c) {
    c.modifyDefence(defenceBoost_);
    if (attackPenalty_ != 0) c.modifyAttack(-attackPenalty_);
}
void Shield::removeEffect(Character &c) {
    c.modifyDefence(-defenceBoost_);
    if (attackPenalty_ != 0) c.modifyAttack(+attackPenalty_);
}
=======
#include "Shield.h"
#include "Character.h"

void Shield::applyEffect(Character &c)
{
    c.defence = c.defence + defenceBoost;
    c.attack = c.attack - attackPenalty;
}

void Shield::removeEffect(Character &c)
{
    c.defence = c.defence - defenceBoost;
    c.attack = c.attack + attackPenalty;
}
>>>>>>> ac8ef0dba7af62ea9c1214bce3c5fd73d1efd64c
