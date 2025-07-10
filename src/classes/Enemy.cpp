#include "classes/Enemy.hpp"

#include "Config.hpp"

Enemy::Enemy(const Vector2 position)
    : position_(position)
    , dimensions_(EnemyAttribs::kDimensions)
    , color_(EnemyAttribs::kColor) {}

void Enemy::SetPosition(const Vector2 position) {
    position_ = position;
}

void Enemy::Draw() {
    DrawRectangle(
        static_cast<int>(position_.x),
        static_cast<int>(position_.y), 
        static_cast<int>(dimensions_.x),
        static_cast<int>(dimensions_.y),
        color_
    );
}

const Vector2& Enemy::GetPosition() const {
    return position_;
}