#ifndef BOARDSQUARE_H
#define BOARDSQUARE_H

#include <memory>
#include <string>
#include "Enemy.h"


class Item;
class Enemy;

/**
 * A single cell in the board. Holds either one Item or one Enemy (or none).
 */
class BoardSquare {
public:
    BoardSquare();
    ~BoardSquare() = default;

    std::string look() const;

    void placeItem(std::unique_ptr<Item> item);
    void placeEnemy(std::unique_ptr<Enemy> enemy);

    Item* getItem() const;
    Enemy* getEnemy() const;

    std::unique_ptr<Item> takeItem();
    std::unique_ptr<Enemy> takeEnemy();

    bool dropItem(std::unique_ptr<Item> itemToDrop);

    bool hasEnemy() const;
    bool hasItem() const;

private:
    std::unique_ptr<Item> item_;
    std::unique_ptr<Enemy> enemy_;
};

#endif // BOARDSQUARE_H
