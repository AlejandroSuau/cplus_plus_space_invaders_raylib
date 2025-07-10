
#include "Config.hpp"
#include "classes/Game.hpp"

int main() {
    Game game(kScreenWidth, kScreenHeight, "SpaceInvaders");
    game.Run();

    return 0;
}