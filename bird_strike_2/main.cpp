#include <raylib.h>
#include <iostream>
#include "H_Sun.h"
#include "H_Crow.h"
#include "H_Main.h"
#include "H_Drag.h"
#include "H_Mouse.h"
#include "H_Image.h"
#include "H_GameState.h"

Music music;

int main() {
    InitWindow(window_width, window_height, "Bird Strike!");

    InitAudioDevice();

    music = LoadMusicStream("audio/test_sound.mp3");

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
        case GameState::Stage_1:
            UpdateMusicStream(music);
            stage_1();
            break;
        case GameState::Stage_2:
            stage_2();
            break;
        case GameState::Gameover:
            PauseMusicStream(music);
            gameover();
            break;
        case GameState::Setting:
            setting();
            break;
        }
        EndDrawing();
    }

    UnloadMusicStream(music);

    CloseAudioDevice();

    CloseWindow();
    return 0;
}