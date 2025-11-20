#include "Item.h"
#include "Weapon.h"
#include "Armour.h"
#include "Shield.h"
#include "Ring.h"
#include "Utility.h"

/*
 PSEUDOCODE - Item::createRandomItem()
   rand = Utility::randInt(0,3)
   case 0: return Weapon
   case 1: return Armour
   case 2: return Shield
   case 3: return Ring
*/

std::unique_ptr<Item> Item::createRandomItem()
{
    int r = Utility::randInt(0, 3);

    switch (r) {

    case 0: // WEAPON
        return std::make_unique<Weapon>(
            "Iron Sword",
            5,
            10 // attack boost
            );

    case 1: // ARMOUR
        return std::make_unique<Armour>(
            "Leather Armour",
            8,
            8,   // defence boost
            2    // attack penalty
            );

    case 2: // SHIELD
        return std::make_unique<Shield>(
            "Wooden Shield",
            6,
            12,  // defence boost
            3    // attack penalty
            );

    case 3: // RING
        return std::make_unique<Ring>(
            "Ring of Vitality",
            1,
            5,   // health boost
            3    // strength boost
            );
    }

    // fallback (should never hit)
    return nullptr;
}
