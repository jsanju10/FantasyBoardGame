#include <iostream>
#include <string>
#include <cctype>
#include "Board.h"
#include "Player.h"
#include "Utility.h"
#include "Constants.h"

static void printWelcome()
{
    std::cout << "======================================\n";
    std::cout << "  Fantasy Board Game (Console)       \n";
    std::cout << "======================================\n";
    std::cout << "Commands: N,S,E,W (move), L=look, P=pick, D=drop, A=attack, I=inventory, X=exit\n";
}

int main()
{
    printWelcome();

    int width = 0, height = 0;
    std::cout << "Enter board width (columns): ";
    std::cin >> width;
    std::cout << "Enter board height (rows): ";
    std::cin >> height;

    if (width <= 0 || height <= 0) {
        std::cout << "Invalid board size. Exiting.\n";
        return 0;
    }

    // ask for player's race
    std::string raceStr;
    std::cout << "Choose your race (Human / Elf / Dwarf / Hobbit / Orc): ";
    std::cin >> raceStr;

    Player player(raceStr, 0, 0);

    Board board(width, height);
    board.initialize();

    board.lookAtPlayerSquare(player);

    int commandCount = 0;
    bool running = true;

    while (running && player.isAlive()) {
        std::cout << "\nEnter command: ";
        std::string cmd; std::cin >> cmd;
        if (cmd.empty()) continue;

        char c = static_cast<char>(std::toupper(cmd[0]));
        bool known = true;

        switch (c) {
        case 'N':
        case 'S':
        case 'E':
        case 'W':
            board.movePlayer(player, c);
            break;
        case 'L':
            board.lookAtPlayerSquare(player);
            break;
        case 'P':
            board.playerPickUp(player);
            break;
        case 'D': {
            std::unique_ptr<Item> itemToDrop = player.selectItemToDrop();
            if (itemToDrop) {
                if (!board.playerDrop(player, std::move(itemToDrop))) {
                    player.returnDroppedItem(std::move(itemToDrop));
                    std::cout << "Drop failed. Item returned.\n";
                }
            }
        } break;
        case 'A':
            board.playerAttack(player);
            break;
        case 'I':
            player.showInventory();
            break;
        case 'X':
            running = false;
            break;
        default:
            std::cout << "Unknown command.\n";
            known = false;
        }

        if (known) {
            ++commandCount;
            if (commandCount % Constants::COMMANDS_PER_TIME_SWITCH == 0) {
                Utility::toggleDayNight();
                bool night = Utility::isNight();
                std::cout << "Time changed. It is now " << (night ? "Night" : "Day") << ".\n";

                // UPDATE PLAYER ORC STATS HERE
                player.updateForTime(night);
            }
        }
    }

    std::cout << "\nGame over. You collected " << player.getGold() << " gold.\n";
    return 0;
}
