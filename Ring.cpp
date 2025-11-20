#include "Ring.h"
#include "Character.h"

void Ring::applyEffect(Character &c) {
    if (healthBoost_ != 0) c.modifyHealth(healthBoost_);
    if (strengthBoost_ != 0) c.modifyStrength(strengthBoost_);
}
void Ring::removeEffect(Character &c) {
    if (healthBoost_ != 0) c.modifyHealth(-healthBoost_);
    if (strengthBoost_ != 0) c.modifyStrength(-strengthBoost_);
}
