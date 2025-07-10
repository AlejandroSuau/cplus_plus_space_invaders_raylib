#pragma once

#include <raylib.h>

#include "Config.hpp"
#include "classes/Player.hpp"

#include <string>

class Game {
public:
    Game(int width, int height, std::string title);
    void Run();

private:
    int width_, height_;
    std::string title_;

    Player player_{Vector2{50.f, 50.f}};

    void Init();
    void Update();
    void Draw();
};
