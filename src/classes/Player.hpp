#pragma once

#include "raylib.h"

class Player {
public:
    Player(Vector2 position);

    void Update();
    void Draw() const;

private:
    Vector2 position_;
    Vector2 dimensions_;
    float speed_;
    
    // How to Render
    Color color_;
};
