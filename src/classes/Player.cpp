#include "classes/Player.hpp"

#include "Config.hpp"

Player::Player(Vector2 position)
    : position_(position), speed_(PlayerAttribs::kSpeed), dimensions_(PlayerAttribs::kDimensions), color_(PlayerAttribs::kColor) {}

void Player::Update() {
    if (IsKeyDown(KEY_LEFT) && position_.x - speed_ > 0) {
        position_.x -= speed_;
    }

    if (IsKeyDown(KEY_RIGHT) && position_.x + dimensions_.x + speed_ < GetScreenWidth()) {
        position_.x += speed_;
    }
}

void Player::Draw() const {
    DrawRectangle(
        static_cast<int>(position_.x),
        static_cast<int>(position_.y), 
        static_cast<int>(dimensions_.x),
        static_cast<int>(dimensions_.y),
        color_
    );
}