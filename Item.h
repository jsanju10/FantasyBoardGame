#ifndef ITEM_H
#define ITEM_H

#endif // ITEM_H

#include <string>

// I include this because I need Character class later.
// But I only write forward declare here to avoid circular include.
class Character;

// I use this enum to know what type of item this is.
// Teacher used enum in lessons so I follow same style.
enum ItemType
{
    WEAPON,
    ARMOUR,
    SHIELD,
    RING
};

// This is abstract Item class.
// I do this because we never want to create a normal Item object.
// We only want specific items (Weapon, Armour etc).
class Item
{
protected:
    std::string name;
    int weight;
    ItemType type;

public:
    // simple constructor
    Item(std::string n, int w, ItemType t)
    {
        name = n;
        weight = w;
        type = t;
    }

    virtual ~Item() {}

    // basic getter functions
    std::string getName() { return name; }
    int getWeight() { return weight; }
    ItemType getType() { return type; }

    // pure virtual, every child must write own version.
    // applyEffect means player pick the item
    virtual void applyEffect(Character &c) = 0;

    // removeEffect means player drop the item
    virtual void removeEffect(Character &c) = 0;
};


