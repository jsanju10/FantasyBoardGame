#include "ItemFactory.h"
#include "Utility.h"
#include "Weapon.h"
#include "Armour.h"
#include "Shield.h"
#include "Ring.h"

std::unique_ptr<Item> ItemFactory::createRandomItem() {
    // define list of possible items; pick one randomly
    int choice = Utility::randInt(0, 7);
    switch (choice) {
    case 0: return std::make_unique<Weapon>("Sword", 10, 10);
    case 1: return std::make_unique<Weapon>("Dagger", 5, 5);
    case 2: return std::make_unique<Armour>("Plate Armour", 40, 10, 5);
    case 3: return std::make_unique<Armour>("Leather Armour", 20, 5, 0);
    case 4: return std::make_unique<Shield>("Large Shield", 30, 10, 5);
    case 5: return std::make_unique<Shield>("Small Shield", 10, 5, 0);
    case 6: return std::make_unique<Ring>("Ring of Life", 1, 10, 0);      // +10 health
    case 7: return std::make_unique<Ring>("Ring of Strength", 1, -10, 50); // -10 health, +50 strength

    }
    return nullptr;
}
