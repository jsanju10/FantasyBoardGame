#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <memory>
#include "BoardSquare.h"
#include "Player.h"


/**
 * Board manages a 2D grid of BoardSquare objects and players interactions.
 */
class Board {
public:
    Board(int width, int height);
    ~Board() = default;

    void initialize(); // populate randomly
    bool movePlayer(Player &player, char direction);
    void lookAtPlayerSquare(const Player &player) const;
    void playerPickUp(Player &player);
    bool playerDrop(Player &player, std::unique_ptr<Item> itemToDrop);
    void playerAttack(Player &player);

    void printDebug() const;

private:
    int width_;
    int height_;
    std::vector<std::vector<std::unique_ptr<BoardSquare>>> grid_;

    bool inBounds(int x, int y) const;
    void populateSquare(int x, int y);
};

#endif // BOARD_H
