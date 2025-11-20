#include "Board.h"
#include "Utility.h"
#include "Enemy.h"
#include "Item.h"
#include "ItemFactory.h"
#include <iostream>

/*
 PSEUDOCODE - Board::populateSquare(x,y)
  - choose random 0..2
  - if 0: create Enemy::createRandomEnemy(); place enemy
  - if 1: create random Item and place
  - else: leave empty
*/

// helper: create random item
// helper: create random item (delegates to ItemFactory)
static std::unique_ptr<Item> createRandomItem() {
    return ItemFactory::createRandomItem();
}

Board::Board(int width, int height)
    : width_(width), height_(height)
{
    grid_.resize(height_);
    for (int y = 0; y < height_; ++y) {
        grid_[y].resize(width_);
        for (int x = 0; x < width_; ++x) {
            grid_[y][x] = std::make_unique<BoardSquare>();
        }
    }
}

void Board::initialize()
{
    for (int y = 0; y < height_; ++y) {
        for (int x = 0; x < width_; ++x) {
            populateSquare(x, y);
        }
    }
}

void Board::populateSquare(int x, int y)
{
    int c = Utility::randInt(0, 2);
    if (c == 0) {
        auto e = Enemy::createRandomEnemy();
        if (e) {
            // set orc stats according to current time
            e->updateForTime(Utility::isNight());
            grid_[y][x]->placeEnemy(std::move(e));
        }
    } else if (c == 1) {
        auto item = createRandomItem();
        if (item) grid_[y][x]->placeItem(std::move(item));
    }
}

bool Board::inBounds(int x, int y) const {
    return x >= 0 && x < width_ && y >= 0 && y < height_;
}

bool Board::movePlayer(Player &player, char direction)
{
    int x = player.getX();
    int y = player.getY();
    char d = static_cast<char>(std::toupper(direction));
    int nx = x, ny = y;
    if (d == 'N') ny = y - 1;
    else if (d == 'S') ny = y + 1;
    else if (d == 'E') nx = x + 1;
    else if (d == 'W') nx = x - 1;
    else {
        std::cout << "Unknown direction.\n";
        return false;
    }
    if (!inBounds(nx, ny)) {
        std::cout << "You cannot move there — out of bounds.\n";
        return false;
    }
    player.setPosition(nx, ny);
    // update orc stats on move if any
    BoardSquare *sq = grid_[ny][nx].get();
    if (sq && sq->hasEnemy()) {
        Enemy *e = sq->getEnemy();
        if (e) e->updateForTime(Utility::isNight());
    }
    lookAtPlayerSquare(player);
    return true;
}

void Board::lookAtPlayerSquare(const Player &player) const
{
    int x = player.getX();
    int y = player.getY();
    std::cout << grid_[y][x]->look() << "\n";
}

void Board::playerPickUp(Player &player)
{
    int x = player.getX();
    int y = player.getY();
    BoardSquare *sq = grid_[y][x].get();
    if (!sq) return;
    if (!sq->hasItem()) {
        std::cout << "There is no item here to pick up.\n";
        return;
    }
    std::unique_ptr<Item> it = sq->takeItem();
    if (!player.pickUp(std::move(it))) {
        // pickUp failed -> put it back
        std::cout << "You cannot carry that item (category/weight). It remains here.\n";
        // if it was moved out, takeItem returned ownership; place back
        // (ensure sq doesn't already contain an item)
        // safe-guard: re-place
        // (if pickUp consumed ownership then addItemBack design would differ)
        // We'll place it back:
        // Note: after std::move(it) it is nullptr, so re-create using sq->placeItem
        // We'll handle by re-putting from the unique ptr we still have (if null, nothing)
        // But since pickUp returned false and we moved, we must put back the item reference.
        // To keep simple we expect pickUp not to take ownership on failure (it doesn't).
        // However to be safe: if it != nullptr then place back.
        // In our implementation pickUp only applies effect after checking constraints and
        // only moves ownership on success; so here we have the item.
        // Place back:
        // (it is still valid if pickUp returned false)
        // placeItem
        sq->placeItem(std::move(it));
    } else {
        std::cout << "Item picked up successfully.\n";
    }
}

bool Board::playerDrop(Player &player, std::unique_ptr<Item> itemToDrop)
{
    int x = player.getX();
    int y = player.getY();
    BoardSquare *sq = grid_[y][x].get();
    if (!sq) return false;
    if (sq->hasItem()) {
        std::cout << "Square already contains an item.\n";
        return false;
    }
    if (sq->dropItem(std::move(itemToDrop))) {
        std::cout << "Dropped item on square.\n";
        return true;
    }
    return false;
}

void Board::playerAttack(Player &player)
{
    int x = player.getX();
    int y = player.getY();
    BoardSquare *sq = grid_[y][x].get();
    if (!sq) return;
    if (!sq->hasEnemy()) {
        std::cout << "There is no enemy here to attack.\n";
        return;
    }
    Enemy *e = sq->getEnemy();
    if (!e) return;

    // update orc's stats for current time
    e->updateForTime(Utility::isNight());

    // player attacks enemy
    player.attack(e);

    // if enemy dead -> remove and award gold
    if (!e->isAlive()) {
        std::unique_ptr<Enemy> dead = sq->takeEnemy();
        int reward = dead->getDefenceValueWithItems();
        player.addGold(reward);
        std::cout << "Enemy defeated! You gained " << reward << " gold.\n";
        return;
    }

    // enemy counterattacks immediately (assignment requires immediate counterattack)
    std::cout << e->getName() << " attempts to counterattack!\n";
    e->attack(&player);

    if (!player.isAlive()) {
        std::cout << "You have been defeated! Game over.\n";
    }
}

void Board::printDebug() const
{
    std::cout << "Board debug (" << width_ << "x" << height_ << "):\n";
    for (int y = 0; y < height_; ++y) {
        for (int x = 0; x < width_; ++x) {
            if (grid_[y][x]->hasEnemy()) std::cout << "E ";
            else if (grid_[y][x]->hasItem()) std::cout << "I ";
            else std::cout << ". ";
        }
        std::cout << "\n";
    }
}
