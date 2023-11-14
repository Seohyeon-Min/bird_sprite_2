#include <raylib.h>
#include <iostream>
#include "sun.h"
#include "crow.h"
#include "beat_system.h"
#include "main.h"
#include "drag.h"
#include "mouse.h"
#include "image.h"
#include "GameState.h"



int main() {
    InitWindow(window_width, window_height, "Sample");
    SetTargetFPS(target_frame_rate);
    HideCursor();
    loadimage();
    while (WindowShouldClose() == false) {


        BeginDrawing();

        ClearBackground(WHITE);

        switch (gamestate) {
        case GameState::Startloading:
            startloding();
            break;
        case GameState::LobbyScreen:
            lobbyscreen();
            break;
        case GameState::Gameplay:
            gameplay();
            break;
        case GameState::Gameover:
            gameover();
            break;
        case GameState::Setting:
            setting();
            break;
        }
        EndDrawing();
    }

    CloseWindow();
    return 0;
}