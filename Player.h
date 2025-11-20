#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"
#include <memory>
#include <string>

class Player : public Character {
public:
    Player(const std::string &raceName, int startX, int startY);

    std::string getName() const override;

    int getX() const { return x_; }
    int getY() const { return y_; }
    void setPosition(int x, int y) { x_ = x; y_ = y; }

    int getGold() const { return gold_; }
    void addGold(int v) { gold_ += v; }

    void showInventory() const;

    std::unique_ptr<Item> selectItemToDrop();
    void returnDroppedItem(std::unique_ptr<Item> item);

    // NEW: For Orc day/night switching
    void updateForTime(bool isNight);

protected:
    int handleSuccessfulDefence() override;

private:
    int x_;
    int y_;
    int gold_;
};

#endif // PLAYER_H
