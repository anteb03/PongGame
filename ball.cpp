#include "ball.hpp"

Ball::Ball() {
    x = GetScreenWidth() / 2;
    y = GetScreenHeight() / 2;
    speedX = 4.0;
    speedY = 4.0;
    radius = 10.0;
    color = RED;
}

void Ball::Update(PlayerPaddle& playerPaddle, CpuPaddle& cpuPaddle) {
    x -= speedX;
    y += speedY;
    Rectangle playerRect = { playerPaddle.GetX(), playerPaddle.GetY(), 10, 60 };
    Rectangle cpuRect = { cpuPaddle.GetX(), cpuPaddle.GetY(), 10, 60 };

    if (x + radius >= GetScreenWidth() || x - radius <= 0) {
        speedX = -speedX;
    }
    if (y + radius >= GetScreenHeight() || y - radius <= 0) {
        speedY = -speedY;
    }

    if (CheckCollisionCircleRec(Vector2{x,y},radius, playerRect)){
        speedX *= -1;
    }
    if (CheckCollisionCircleRec(Vector2{x,y}, radius, cpuRect)) {
        speedX *= -1;
    }
}

void Ball::Draw() const {
    DrawCircle(static_cast<int>(x), static_cast<int>(y), radius, color);
}

float Ball::GetX() const {
    return x;
}

float Ball::GetY() const {
    return y;
}

float Ball::GetRadius() const {
    return radius;
}


void Ball::Reset() {
    x = GetScreenWidth() / 2;
    y = GetScreenHeight() / 2;
    speedX = 4.0;
    speedY = 4.0;
    direction = GetRandomValue(0, 1) == 0 ? -1 : 1; 
    direction2 = GetRandomValue(0, 1) == 0 ? -1 : 1;
    speedX *= direction; 
    speedY *= direction2;
}