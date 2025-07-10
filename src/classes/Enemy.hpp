#pragma once

#include <raylib.h>

class Enemy {
public:
    Enemy(const Vector2 position);

    void SetPosition(const Vector2 position);
    const Vector2& GetPosition() const;

    void Draw();

private:
    Vector2 position_;
    Vector2 dimensions_;
    Color color_;
};
