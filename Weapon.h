#ifndef WEAPON_H
#define WEAPON_H

#include "Item.h"
#include <string>

class Weapon : public Item {
public:
    Weapon(const std::string &name, int weight, int attackBoost)
        : Item(name, weight, ItemType::WEAPON), attackBoost_(attackBoost) {}

    void applyEffect(class Character &c) override;
    void removeEffect(class Character &c) override;

private:
    int attackBoost_;
};

#endif // WEAPON_H
