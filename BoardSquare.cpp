#include "BoardSquare.h"
#include "Item.h"
#include "Enemy.h"
#include <sstream>

BoardSquare::BoardSquare()
    : item_(nullptr), enemy_(nullptr)
{}

std::string BoardSquare::look() const
{
    std::ostringstream ss;
    if (enemy_) {
        ss << "An enemy is here: " << enemy_->getName()
        << " (H:" << enemy_->getHealth() << " A:" << enemy_->getAttack()
        << " D:" << enemy_->getDefence() << ")";
    } else if (item_) {
        ss << "You see an item: " << item_->getName()
        << " (weight " << item_->getWeight() << ")";
    } else {
        ss << "The square is empty.";
    }
    return ss.str();
}

void BoardSquare::placeItem(std::unique_ptr<Item> item) {
    item_ = std::move(item);
}
void BoardSquare::placeEnemy(std::unique_ptr<Enemy> enemy) {
    enemy_ = std::move(enemy);
}

Item* BoardSquare::getItem() const { return item_.get(); }
Enemy* BoardSquare::getEnemy() const { return enemy_.get(); }

std::unique_ptr<Item> BoardSquare::takeItem() {
    return std::move(item_);
}
std::unique_ptr<Enemy> BoardSquare::takeEnemy() {
    return std::move(enemy_);
}

bool BoardSquare::dropItem(std::unique_ptr<Item> itemToDrop)
{
    if (!itemToDrop) return false;
    if (item_) return false;
    item_ = std::move(itemToDrop);
    return true;
}

bool BoardSquare::hasEnemy() const { return enemy_ != nullptr; }
bool BoardSquare::hasItem() const { return item_ != nullptr; }
