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
