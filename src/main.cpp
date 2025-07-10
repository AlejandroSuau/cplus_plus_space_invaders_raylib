#include <iostream>

#include "classes/Game.hpp"

int main() {
    Game game(600, 600, "SpaceInvaders");
    game.Run();

    std::cout << "Hello world!" << std::endl;
    return 0;
}