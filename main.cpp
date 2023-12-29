#include "raylib.h"
#include "players.hpp"
#include "ball.hpp"
#include <string>
using namespace std; 

int main(void) {
    const int screenWidth = 1000;
    const int screenHeight = 520;
    InitWindow(screenWidth, screenHeight, "Pong Game");
    SetTargetFPS(100);
    PlayerPaddle playerPaddle; 
    Ball ball;
    CpuPaddle cpuPaddle(ball);
    bool isPlaying = false;
    int playerScore = 0;
    int cpuScore = 0; 
    bool winPlayer = false; 
    bool winCpu = false; 
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(DARKGREEN);
        if (IsKeyPressed(KEY_ENTER)) {
            isPlaying = true; 
        }

        if (!isPlaying) {
            DrawText("Press enter to play", screenWidth / 2 - 100, screenHeight / 2, 20, BLACK);
            DrawText("Left paddle is player, right is CPU", 10, 10, 20, BLACK);
            DrawText("Controls for the player;[W] for moving paddle up,[S] for moving paddle down", 10, 35, 20, BLACK);
            if (winPlayer) {
                DrawText("Player win", screenWidth / 2 - 50, screenHeight / 2 - 30, 20, BLACK);
            }
            else if (winCpu) {
                DrawText("CPU win", screenWidth / 2 - 35 , screenHeight / 2 - 30, 20, BLACK);
            }
        }
        else if(isPlaying) {
            DrawRectangle(screenWidth/2, 0 , 8, screenHeight,WHITE);
            DrawCircle(screenWidth/ 2 + 4, screenHeight/2, 50, WHITE);
            DrawText((to_string(playerScore)).c_str(), (screenWidth / 2) / 2 , 10, 30, BLACK);
            DrawText((to_string(cpuScore)).c_str(), (screenWidth/2) + screenWidth / 4, 10, 30, BLACK);
            ball.Update(playerPaddle,cpuPaddle);
            if (ball.GetX() - ball.GetRadius() <= 0) {
                cpuScore++;
                ball.Reset();
            }
            else if (ball.GetX() + ball.GetRadius() >= screenWidth) {
                playerScore++;
                ball.Reset();
            }
            ball.Draw();
            playerPaddle.Move();
            playerPaddle.Draw();
            cpuPaddle.Move();
            cpuPaddle.Draw();
            if (cpuScore == 3 || playerScore == 3) {
                isPlaying = false; 
                if (cpuScore == 3) {
                    winCpu = true; 
                    winPlayer = false; 
                }
                if (playerScore == 3) {
                    winPlayer = true;
                    winCpu = false; 
                }
                cpuScore = 0;
                playerScore = 0;
            }
        }
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
