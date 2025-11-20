#include "Enemy.h"
#include "Utility.h"
#include "Constants.h"
#include <vector>
#include <iostream>

/*
 PSEUDOCODE - Enemy::handleSuccessfulDefence()
   Human/Dwarf: return 0
   Elf: health +1, return 0
   Hobbit: return randInt(0,5)
   Orc: if night -> health +1 (return 0)
        else -> return floor((attackerAdjusted - defenderDefence)/4)
           but we don't have attacker here -> approximate by (baseAttack - baseDefence)/4
*/

Enemy::Enemy(const std::string &raceName)
    : Character(raceName,
                (raceName=="Human"? Constants::HUMAN.attack :
                     raceName=="Elf"? Constants::ELF.attack :
                     raceName=="Dwarf"? Constants::DWARF.attack :
                     raceName=="Hobbit"? Constants::HOBBIT.attack :
                     Constants::ORC_DAY.attack),
                (raceName=="Human"? Constants::HUMAN.attackChance :
                     raceName=="Elf"? Constants::ELF.attackChance :
                     raceName=="Dwarf"? Constants::DWARF.attackChance :
                     raceName=="Hobbit"? Constants::HOBBIT.attackChance :
                     Constants::ORC_DAY.attackChance),
                (raceName=="Human"? Constants::HUMAN.defence :
                     raceName=="Elf"? Constants::ELF.defence :
                     raceName=="Dwarf"? Constants::DWARF.defence :
                     raceName=="Hobbit"? Constants::HOBBIT.defence :
                     Constants::ORC_DAY.defence),
                (raceName=="Human"? Constants::HUMAN.defenceChance :
                     raceName=="Elf"? Constants::ELF.defenceChance :
                     raceName=="Dwarf"? Constants::DWARF.defenceChance :
                     raceName=="Hobbit"? Constants::HOBBIT.defenceChance :
                     Constants::ORC_DAY.defenceChance),
                (raceName=="Human"? Constants::HUMAN.health :
                     raceName=="Elf"? Constants::ELF.health :
                     raceName=="Dwarf"? Constants::DWARF.health :
                     raceName=="Hobbit"? Constants::HOBBIT.health :
                     Constants::ORC_DAY.health),
                (raceName=="Human"? Constants::HUMAN.strength :
                     raceName=="Elf"? Constants::ELF.strength :
                     raceName=="Dwarf"? Constants::DWARF.strength :
                     raceName=="Hobbit"? Constants::HOBBIT.strength :
                     Constants::ORC_DAY.strength)
                )
{
    // initially set to race defaults (Orc defaults to DAY, will be updated by Board)
}

int Enemy::handleSuccessfulDefence()
{
    if (race_ == "Human" || race_ == "Dwarf") {
        return 0;
    }
    if (race_ == "Elf") {
        modifyHealth(+1);
        return 0;
    }
    if (race_ == "Hobbit") {
        return Utility::randInt(0, 5);
    }
    if (race_ == "Orc") {
        if (Utility::isNight()) {
            modifyHealth(+1);
            return 0;
        } else {
            // approximate quarter of adjusted damage using own base values
            int adjusted = baseAttack_ - baseDefence_;
            if (adjusted < 0) adjusted = 0;
            int dmg = adjusted / 4;
            return dmg;
        }
    }
    return 0;
}

std::unique_ptr<Enemy> Enemy::createRandomEnemy()
{
    static const std::vector<std::string> races = {"Human","Elf","Dwarf","Hobbit","Orc"};
    int idx = Utility::randInt(0, static_cast<int>(races.size()) - 1);
    return std::make_unique<Enemy>(races[idx]);
}

void Enemy::updateForTime(bool isNight)
{
    if (race_ != "Orc") return;
    if (isNight) {
        setAttack(Constants::ORC_NIGHT.attack);
        setAttackChance(Constants::ORC_NIGHT.attackChance);
        setDefence(Constants::ORC_NIGHT.defence);
        setDefenceChance(Constants::ORC_NIGHT.defenceChance);
    } else {
        setAttack(Constants::ORC_DAY.attack);
        setAttackChance(Constants::ORC_DAY.attackChance);
        setDefence(Constants::ORC_DAY.defence);
        setDefenceChance(Constants::ORC_DAY.defenceChance);
    }
}
