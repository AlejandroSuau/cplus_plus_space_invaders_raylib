#include "classes/EnemyList.hpp"

#include <raylib.h>

#include "Config.hpp"

EnemyList::EnemyList() 
    : enemies_{}
    , timer_to_step_(0.5f) 
    , direction_(EnemyList::EDirection::LEFT) {
    Init();
}

void EnemyList::Init() {
    Vector2 pos{10.f, 200.f};
    float padding = 3.f;

    x_limit_begin_ = pos.x;
    x_limit_end_ = EnemyAttribs::kDimensions.x * static_cast<float>(kColsCount);
    
    for (std::size_t i = 0; i < 10; ++i) {
        enemies_[i] = std::make_unique<Enemy>(pos);
        pos.x += EnemyAttribs::kDimensions.x;
    }
}

void EnemyList::Update(float dt) {
    // TraceLog(LOG_INFO, "Passed time: %f", timer_to_step_.GetElapsedSeconds());
    if (timer_to_step_.Update(dt)) {
        // StepHorizontally() dt_pos?
        // StepVertically() dt_pos?
        Step();
    }
}

void EnemyList::Step() {
    float dt_pos = EnemyAttribs::kDimensions.x * static_cast<int>(direction_);
    if (x_limit_begin_ + dt_pos <= 10.f || x_limit_end_ + dt_pos >= (static_cast<float>(GetScreenWidth()) - 10.f)) {
        SwapDirection();
        
        // TODO: StepDown

        return;
    } else {
        x_limit_begin_ += dt_pos;
        x_limit_end_ += dt_pos;
    }

    for (auto& e : enemies_) {
        if (!e) continue;

        Vector2 pos = e->GetPosition();
        pos.x += dt_pos;
        e->SetPosition(pos);
    }
}

void EnemyList::Draw() {
    for (auto& e : enemies_) {
        if (!e) continue;

        e->Draw();
    }
}

void EnemyList::SwapDirection() {
    direction_ = (direction_ == EDirection::RIGHT) ? EDirection::LEFT : EDirection::RIGHT;
}
