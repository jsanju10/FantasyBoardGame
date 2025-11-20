<<<<<<< HEAD
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
=======
#include "Ring.h"
#include "Character.h"

// when player take ring
void Ring::applyEffect(Character &c)
{
    c.health = c.health + healthBoost;
    c.strength = c.strength + strengthBoost;
}

// when player remove ring
void Ring::removeEffect(Character &c)
{
    c.health = c.health - healthBoost;
    c.strength = c.strength - strengthBoost;
}
>>>>>>> ac8ef0dba7af62ea9c1214bce3c5fd73d1efd64c
