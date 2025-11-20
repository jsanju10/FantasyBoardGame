#ifndef WEAPON_H
#define WEAPON_H

<<<<<<< HEAD
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

=======




#include "Item.h"

// Weapon increase attack for character
class Weapon : public Item
{
private:
    int attackBoost;

public:
    Weapon(std::string n, int w, int boost)
        : Item(n, w, WEAPON)
    {
        attackBoost = boost;
    }

    void applyEffect(Character &c);   // add attack
    void removeEffect(Character &c);  // remove attack
};
>>>>>>> ac8ef0dba7af62ea9c1214bce3c5fd73d1efd64c
#endif // WEAPON_H
