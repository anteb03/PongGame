#ifndef BALL_HPP
#define BALL_HPP

#include "raylib.h"
#include "players.hpp"

class PlayerPaddle;
class CpuPaddle; 
class Paddle;
class Ball {
private:
    float x, y;
    float speedX, speedY;
    float radius;
    Color color; 
    int direction;
    int direction2; 
public:
    Ball();
    void Update(PlayerPaddle& playerPaddle, CpuPaddle& cpuPaddle);
    void Draw() const;
    float GetX() const;
    float GetY() const;
    float GetRadius() const ; 
    void Reset();
};

#endif

