#ifndef ENEMY_H
#define ENEMY_H

#include "Character.h"
#include <memory>

/**
 * Enemy is a Character placed on BoardSquare.
 * Provides factory createRandomEnemy() and updateForTime(isNight).
 */
class Enemy : public Character {
public:
    explicit Enemy(const std::string &raceName);

    std::string getName() const override { return race_ + " (Enemy)"; }

    static std::unique_ptr<Enemy> createRandomEnemy();

    /** Update effective stats based on day/night (Orc special) */
    void updateForTime(bool isNight);

protected:
    int handleSuccessfulDefence() override;
};

#endif // ENEMY_H
