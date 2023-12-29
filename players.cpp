#include "players.hpp"

Paddle::Paddle(Color col, float spd, float startX, float startY)
    : color(col), speed(spd), x(startX), y(startY) {}

float Paddle::GetX() const {
    return x;
}

float Paddle::GetY() const {
    return y;
}

PlayerPaddle::PlayerPaddle() : Paddle(BLACK, 5.0, 30, GetScreenHeight() / 2 - 30) {}

void PlayerPaddle::Move() {
    if (IsKeyDown(KEY_W) && y > 0) {
        y -= speed;
    }
    else if (IsKeyDown(KEY_S) && y + 60 < GetScreenHeight()) {
        y += speed;
    }
}

void PlayerPaddle::Draw() {
    DrawRectangleRounded(Rectangle{ x,y,10,60 }, 0.8, 0, color);
}

CpuPaddle::CpuPaddle(Ball& ball) : Paddle(BLACK, 5.0, GetScreenWidth() - 45, GetScreenHeight() / 2 - 30), ball(ball) {}

void CpuPaddle::Move() {
    if (ball.GetY() < y + 30) {
        if (y > 0) {
            y -= speed - 1.5;
        }
    }
    else if (ball.GetY() > y + 30) {
        if (y + 60 < GetScreenHeight()) {
            y += speed - 1.5;
        }
    }
}

void CpuPaddle::Draw() {
    DrawRectangleRounded(Rectangle{x,y,10,60 }, 0.8, 0, color);
}