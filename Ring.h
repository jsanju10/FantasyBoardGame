#ifndef RING_H
#define RING_H

<<<<<<< HEAD
#include "Item.h"
#include <string>

class Ring : public Item {
public:
    Ring(const std::string &name, int weight, int healthBoost, int strengthBoost)
        : Item(name, weight, ItemType::RING),
        healthBoost_(healthBoost), strengthBoost_(strengthBoost) {}

    void applyEffect(class Character &c) override;
    void removeEffect(class Character &c) override;

private:
    int healthBoost_;
    int strengthBoost_;
=======


#include "Item.h"

// Ring can increase health or strength.
// Player can have many rings.
class Ring : public Item
{
private:
    int healthBoost;
    int strengthBoost;

public:
    Ring(std::string n, int w, int hBoost, int sBoost)
        : Item(n, w, RING)
    {
        healthBoost = hBoost;
        strengthBoost = sBoost;
    }

    void applyEffect(Character &c);
    void removeEffect(Character &c);
>>>>>>> ac8ef0dba7af62ea9c1214bce3c5fd73d1efd64c
};

#endif // RING_H
