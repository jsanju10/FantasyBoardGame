#include "Character.h"
#include "Utility.h"
#include <iostream>
#include <algorithm>

/*
 PSEUDOCODE - Character::attack(target)
 1. If target == nullptr or not alive -> print message and return
 2. Roll attackSuccess(). If fail -> print "miss" and return
 3. If succeed:
    a) If target->defenceSuccess() -> call target->handleSuccessfulDefence()
         reduce target health by returned specialDamage (could be 0)
    b) else -> damage = this->attack_ - target->defence_; clamp to >=0
         target->modifyHealth(-damage)
 4. Print results.
*/

Character::Character(const std::string &raceName,
                     int attack, double attackChance,
                     int defence, double defenceChance,
                     int health, int strength)
    : race_(raceName),
    baseAttack_(attack), baseDefence_(defence), baseHealth_(health), baseStrength_(strength),
    attack_(attack), defence_(defence), health_(health), strength_(strength),
    attackChance_(attackChance), defenceChance_(defenceChance)
{
}

bool Character::attackSuccess() const {
    return Utility::probability(attackChance_);
}
bool Character::defenceSuccess() const {
    return Utility::probability(defenceChance_);
}

void Character::attack(Character *target)
{
    if (!target) {
        std::cout << "No target to attack.\n";
        return;
    }
    if (!target->isAlive()) {
        std::cout << target->getName() << " is already defeated.\n";
        return;
    }
    std::cout << getName() << " attacks " << target->getName() << "!\n";

    if (!attackSuccess()) {
        std::cout << getName() << " missed the attack.\n";
        return;
    }

    // defender may try to defend
    if (target->defenceSuccess()) {
        int specialDamage = target->handleSuccessfulDefence();
        if (specialDamage > 0) {
            target->modifyHealth(-specialDamage);
        }
        std::cout << target->getName() << " successfully defended (special). Damage taken: "
                  << specialDamage << "\n";
        return;
    }

    // normal damage
    int damage = attack_ - target->defence_;
    if (damage < 0) damage = 0;
    target->modifyHealth(-damage);

    std::cout << getName() << " deals " << damage << " damage to " << target->getName() << ".\n";
}

bool Character::pickUp(std::unique_ptr<Item> item)
{
    if (!item) return false;

    int w = item->getWeight();
    // category rules: only one weapon/armour/shield, many rings allowed
    ItemType t = item->getType();
    if (t != ItemType::RING) {
        // check if we already have item of this category
        for (const auto &it : inventory_) {
            if (it->getType() == t) return false; // already have one
        }
    }

    if (carriedWeight_ + w > strength_) {
        return false;
    }

    // apply effect and add to inventory
    item->applyEffect(*this);
    carriedWeight_ += w;
    inventory_.push_back(std::move(item));
    return true;
}

std::unique_ptr<Item> Character::removeItem(size_t index)
{
    if (index >= inventory_.size()) return nullptr;
    std::unique_ptr<Item> taken = std::move(inventory_[index]);
    // remove effect
    taken->removeEffect(*this);
    carriedWeight_ -= taken->getWeight();
    if (carriedWeight_ < 0) carriedWeight_ = 0;
    inventory_.erase(inventory_.begin() + index);
    return taken;
}

void Character::addItemBack(std::unique_ptr<Item> item)
{
    if (!item) return;
    // ensure capacity
    if (carriedWeight_ + item->getWeight() > strength_) {
        // cannot re-add
        return;
    }
    item->applyEffect(*this);
    carriedWeight_ += item->getWeight();
    inventory_.push_back(std::move(item));
}

void Character::printInventory() const
{
    std::cout << "Inventory (" << inventory_.size() << ") weight " << carriedWeight_ << "/" << strength_ << ":\n";
    for (size_t i = 0; i < inventory_.size(); ++i) {
        std::cout << " [" << i << "] " << inventory_[i]->getName() << " (w=" << inventory_[i]->getWeight() << ")\n";
    }
}
