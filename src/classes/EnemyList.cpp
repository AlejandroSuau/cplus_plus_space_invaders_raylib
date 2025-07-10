#include "classes/EnemyList.hpp"

#include <raylib.h>

#include "Config.hpp"

EnemyList::EnemyList() 
    : enemies_{}
    , timer_to_step_(0.5f) {
    Init();
}

void EnemyList::Init() {
    enemies_[0] = std::make_unique<Enemy>(Vector2{80.f, 80.f});
}

void EnemyList::Update(float dt) {
    // TraceLog(LOG_INFO, "Passed time: %f", timer_to_step_.GetElapsedSeconds());
    if (timer_to_step_.Update(dt)) {
        Step();
    }
}

void EnemyList::Step() {
    for (auto& e : enemies_) {
        if (!e) continue;

        Vector2 pos = e->GetPosition();
        pos.x += EnemyAttribs::kDimensions.x + 2.f;
        e->SetPosition(pos);
    }
}

void EnemyList::Draw() {
    for (auto& e : enemies_) {
        if (!e) continue;

        e->Draw();
    }
}
