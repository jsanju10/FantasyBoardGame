#ifndef SHIELD_H
#define SHIELD_H

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
};

#endif // SHIELD_H
