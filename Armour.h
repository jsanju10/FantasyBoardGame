#ifndef ARMOUR_H
#define ARMOUR_H



#include "Item.h"

// Armour give defence but maybe reduce attack
class Armour : public Item
{
private:
    int defenceBoost;
    int attackPenalty;

public:
    Armour(std::string n, int w, int defBoost, int atkPenalty)
        : Item(n, w, ARMOUR)
    {
        defenceBoost = defBoost;
        attackPenalty = atkPenalty;
    }

    void applyEffect(Character &c);
    void removeEffect(Character &c);
};


#endif // ARMOUR_H
