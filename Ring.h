#ifndef RING_H
#define RING_H

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
};

#endif // RING_H
