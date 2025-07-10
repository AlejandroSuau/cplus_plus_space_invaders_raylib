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
    enum class EDirection {
        LEFT = -1,
        NONE = 0,
        RIGHT = 1
    };

    Enemies enemies_;
    Timer timer_to_step_;
    EDirection direction_;
    float x_limit_begin_;
    float x_limit_end_;

    void Init();
    void Step();
    void SwapDirection();
};
