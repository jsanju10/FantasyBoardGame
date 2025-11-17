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
