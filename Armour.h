#ifndef ARMOUR_H
#define ARMOUR_H

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

#endif // ARMOUR_H
