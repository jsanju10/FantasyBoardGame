#ifndef ITEMFACTORY_H
#define ITEMFACTORY_H

#include <memory>
#include "Item.h"

// Forward declarations of concrete items
class Weapon;
class Armour;
class Shield;
class Ring;

class ItemFactory {
public:
    // create a random item; can return nullptr sometimes
    static std::unique_ptr<Item> createRandomItem();
};

#endif // ITEMFACTORY_H
