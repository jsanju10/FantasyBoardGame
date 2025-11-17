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
