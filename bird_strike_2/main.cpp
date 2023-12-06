#include <raylib.h>
#include <iostream>
#include "H_Sun.h"
#include "H_Crow.h"
#include "H_Main.h"
#include "H_Drag.h"
#include "H_Mouse.h"
#include "H_Image.h"
#include "H_GameState.h"
#include "H_Beat_system.h"

Music music;
Music crow_blow;
bool clickEffectActive = false;
Vector2 clickEffectPosition = { 0 };
double clickEffectStartTime = 0;
float camera_offset = 1.3;

int main() {
    InitWindow(window_width, window_height, "Bird Strike!");

    Camera2D camera{
    { window_width / 2, window_height / 2. },
    { window_width / 2, window_height / 2.},
    0,
    1.003,
    };

    InitAudioDevice();

    music = LoadMusicStream("audio/test_sound.mp3");
    crow_blow = LoadMusicStream("audio/crow_blow.mp3");

    PlayMusicStream(music);
    PlayMusicStream(crow_blow);

    SetTargetFPS(target_frame_rate);

    HideCursor();

    loadimage();

    while (WindowShouldClose() == false) {


        BeginDrawing();
        BeginMode2D(camera);
        ClearBackground(WHITE);

        if (clickEffectActive)
        {
            double currentTime = GetTime();
            double elapsedTime = currentTime - clickEffectStartTime;

            if (elapsedTime < 0.1)
            {
                float offsetX = (float)GetRandomValue(-camera_offset, camera_offset);
                float offsetY = (float)GetRandomValue(-camera_offset, camera_offset);


                camera.target = { window_width / 2 + offsetX, window_height / 2 + offsetY };
            }
            else
            {
                camera.target = { window_width / 2 , window_height / 2 };
                clickEffectActive = false;
            }
        }

        

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
        EndMode2D();
        EndDrawing();

        if (crow_just_erased)
        {
            clickEffectPosition = GetMousePosition();
            clickEffectActive = true;
            clickEffectStartTime = GetTime();
        }
    }

    UnloadMusicStream(music);

    CloseAudioDevice();

    CloseWindow();
    return 0;
}