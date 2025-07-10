#include "Game.hpp"

Game::Game(int width, int height, std::string title)
    : width_(width), height_(height), title_(std::move(title)) {}

void Game::Init() {

}

void Game::Run() {
    InitWindow(width_, height_, title_.c_str());
    SetTargetFPS(kTargetFPS);

    Init();

    while(!WindowShouldClose()) {
        this->Update();
        this->Draw();
    }
}

void Game::Update() {
    player_.Update();
}

void Game::Draw() {
    BeginDrawing();

    ClearBackground(RAYWHITE);
    DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

    player_.Draw();

    EndDrawing();
}