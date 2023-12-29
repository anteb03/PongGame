#ifndef PLAYERS_HPP
#define PLAYERS_HPP

#include "raylib.h"
#include "ball.hpp"
class Ball;
class Paddle {
protected:
    float x, y;
    Color color;
    float speed;

public:
    Paddle(Color col, float spd, float startX, float startY);
    virtual void Move() = 0;
    virtual void Draw() = 0;
    float GetX() const;
    float GetY() const;
};

class PlayerPaddle : public Paddle {
public:
    PlayerPaddle();
    void Move() override;
    void Draw() override;
};

class CpuPaddle : public Paddle {
private:
    Ball& ball;

public:
    CpuPaddle(Ball& ballObj);
    void Move() override;
    void Draw() override;
};

#endif