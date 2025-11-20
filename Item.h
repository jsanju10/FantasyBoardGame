<<<<<<< HEAD
#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <memory>

// Forward declare Character to avoid circular include
class Character;

/**
 * Enumeration of possible item types.
 */
enum class ItemType { WEAPON, ARMOUR, SHIELD, RING };

/**
 * @brief Abstract base class for all items in the game.
 *
 * Required by assignment:
 *  - Every concrete item modifies character stats through applyEffect/removeEffect.
 *  - Player can carry unbounded items (dynamic container).
 *  - Items are stored and transferred via std::unique_ptr<Item>.
 *
 * NOTE:
 *  Board requires a factory to create random items:
 *      Item::createRandomItem()
 */
class Item {
public:
    /**
     * @brief Constructor
     * @param name   name of item
     * @param weight weight of item (used for strength limit)
     * @param type   item category (weapon/armour/shield/ring)
     */
    Item(const std::string &name, int weight, ItemType type)
        : name_(name), weight_(weight), type_(type) {}

    virtual ~Item() = default;

    // getters
    std::string getName() const { return name_; }
    int getWeight()  const { return weight_; }
    ItemType getType() const { return type_; }

    /**
     * @brief applyEffect
     * Called when the player picks up the item.
     * Must modify Character stats.
     */
    virtual void applyEffect(Character &c) = 0;

    /**
     * @brief removeEffect
     * Called when the player drops the item.
     * Must undo applyEffect.
     */
    virtual void removeEffect(Character &c) = 0;

    /**
     * @brief createRandomItem()
     *
     * Factory used by Board::populateSquare().
     *
     * PSEUDOCODE:
     *   generate random number
     *   if 0 -> Weapon
     *   if 1 -> Armour
     *   if 2 -> Shield
     *   if 3 -> Ring
     *   return unique_ptr to new concrete item object
     */
    static std::unique_ptr<Item> createRandomItem();

private:
    std::string name_;
    int weight_;
    ItemType type_;
};

#endif // ITEM_H
=======
#ifndef ITEM_H
#define ITEM_H



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

#endif // ITEM_H

>>>>>>> ac8ef0dba7af62ea9c1214bce3c5fd73d1efd64c
