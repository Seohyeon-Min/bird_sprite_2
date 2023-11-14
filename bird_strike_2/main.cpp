#include <raylib.h>
#include <iostream>
#include "H_Sun.h"
#include "H_Crow.h"
#include "H_Main.h"
#include "H_Drag.h"
#include "H_Mouse.h"
#include "H_Image.h"
#include "H_GameState.h"



int main() {
    InitWindow(window_width, window_height, "Bird Strike!");

    InitAudioDevice();

    Music music = LoadMusicStream("audio/test_sound.mp3");

    PlayMusicStream(music);

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
            UpdateMusicStream(music);
            gameplay();
            break;
        case GameState::Gameover:
            UnloadMusicStream(music);
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