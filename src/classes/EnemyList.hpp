#pragma once

#include "classes/Enemy.hpp"
#include "utils/Timer.hpp"

#include <array>
#include <memory>

class EnemyList {
public:
    static constexpr std::size_t kRowsCount = 5;
    static constexpr std::size_t kColsCount = 11;
    using Enemies = std::array<std::unique_ptr<Enemy>, kRowsCount * kColsCount>;

    EnemyList();
    void Update(float dt);
    void Draw();

private:
    Enemies enemies_;
    Timer timer_to_step_;

    void Init();
    void Step();
};
