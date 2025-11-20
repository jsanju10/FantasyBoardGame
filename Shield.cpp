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
