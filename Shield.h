#ifndef SHIELD_H
#define SHIELD_H

<<<<<<< HEAD
#include "Item.h"
#include <string>

class Shield : public Item {
public:
    Shield(const std::string &name, int weight, int defenceBoost, int attackPenalty = 0)
        : Item(name, weight, ItemType::SHIELD),
        defenceBoost_(defenceBoost), attackPenalty_(attackPenalty) {}

    void applyEffect(class Character &c) override;
    void removeEffect(class Character &c) override;

private:
    int defenceBoost_;
    int attackPenalty_;
=======



#include "Item.h"

// Shield increase defence, big shield decrease attack
class Shield : public Item
{
private:
    int defenceBoost;
    int attackPenalty;

public:
    Shield(std::string n, int w, int defBoost, int atkPenalty)
        : Item(n, w, SHIELD)
    {
        defenceBoost = defBoost;
        attackPenalty = atkPenalty;
    }

    void applyEffect(Character &c);
    void removeEffect(Character &c);
>>>>>>> ac8ef0dba7af62ea9c1214bce3c5fd73d1efd64c
};

#endif // SHIELD_H
