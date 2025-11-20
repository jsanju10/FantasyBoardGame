#ifndef ARMOUR_H
#define ARMOUR_H

<<<<<<< HEAD
#include "Item.h"
#include <string>

class Armour : public Item {
public:
    Armour(const std::string &name, int weight, int defenceBoost, int attackPenalty = 0)
        : Item(name, weight, ItemType::ARMOUR),
        defenceBoost_(defenceBoost), attackPenalty_(attackPenalty) {}

    void applyEffect(class Character &c) override;
    void removeEffect(class Character &c) override;

private:
    int defenceBoost_;
    int attackPenalty_;
};

=======


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


>>>>>>> ac8ef0dba7af62ea9c1214bce3c5fd73d1efd64c
#endif // ARMOUR_H
