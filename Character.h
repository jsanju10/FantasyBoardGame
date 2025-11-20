#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <vector>
#include <memory>

#include "Item.h"

/**
 * Abstract base class for Player and Enemy.
 *
 * Provides:
 *  - base stats and current effective stats
 *  - inventory management (unique_ptr<Item>)
 *  - attack(Character*) method (generic)
 *  - public modifiers (modifyAttack, modifyDefence, etc.) used by Item subclasses
 *
 * Subclasses must implement:
 *   - getName()
 *   - handleSuccessfulDefence() (race-specific reaction)
 */
class Character {
public:
    Character(const std::string &raceName,
              int attack, double attackChance,
              int defence, double defenceChance,
              int health, int strength);

    virtual ~Character() = default;

    virtual std::string getName() const = 0;

    /** Generic attack method: attacker -> target. */
    void attack(Character *target);

    /** Inventory management */
    bool pickUp(std::unique_ptr<Item> item);          // add if fits (weight & category rules)
    std::unique_ptr<Item> removeItem(size_t index);   // remove & return ownership
    void addItemBack(std::unique_ptr<Item> item);     // re-add ownership

    void printInventory() const;

    bool isAlive() const { return health_ > 0; }

    // getters
    int getAttack() const { return attack_; }
    int getDefence() const { return defence_; }
    int getHealth() const { return health_; }
    int getStrength() const { return strength_; }

    /** reward: effective defence (includes items) */
    virtual int getDefenceValueWithItems() const { return defence_; }

    // Public modifiers used by Item::applyEffect/removeEffect:
    void modifyAttack(int delta)   { attack_ += delta; if (attack_ < 0) attack_ = 0; }
    void modifyDefence(int delta)  { defence_ += delta; if (defence_ < 0) defence_ = 0; }
    void modifyHealth(int delta)   { health_ += delta; if (health_ < 0) health_ = 0; }
    void modifyStrength(int delta) { strength_ += delta; if (strength_ < 0) strength_ = 0; }

    // setters for runtime adjustments (used for orc day/night)
    void setAttack(int v) { attack_ = v; }
    void setAttackChance(double v) { attackChance_ = v; }
    void setDefence(int v) { defence_ = v; }
    void setDefenceChance(double v) { defenceChance_ = v; }

protected:
    // race tag
    std::string race_;

    // base stats (unchanging reference)
    int baseAttack_;
    int baseDefence_;
    int baseHealth_;
    int baseStrength_;

    // effective stats (modified by items/time)
    int attack_;
    int defence_;
    int health_;
    int strength_;

    int carriedWeight_ = 0; // total weight carried

    double attackChance_;
    double defenceChance_;

    std::vector<std::unique_ptr<Item>> inventory_;

    // chance helpers
    bool attackSuccess() const;
    bool defenceSuccess() const;

    // subclasses implement race-specific behaviour on successful defence
    virtual int handleSuccessfulDefence() = 0;
};

#endif // CHARACTER_H
