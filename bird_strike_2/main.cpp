#include <raylib.h>
#include <iostream>
#include "H_Sun.h"
#include "H_Crow.h"
#include "H_Main.h"
#include "H_Drag.h"
#include "H_Mouse.h"
#include "H_Image.h"
#include "H_GameState.h"
#include "H_Txt_read.h"

//Music music;
//Sound crow_blow;
Vector2 camerapos = { window_width / 2, window_height / 2 };

bool clickEffectActive = false;
bool zoomEffectActive = false;
double clickEffectStartTime = 0;
double fail_StarTime = 0;
float camera_offset = 2;



int main() {
    InitWindow(window_width, window_height, "Bird Strike!");
    SetExitKey(KEY_NULL);

    bool exitWindowRequested = false;
    bool exitWindow = false;


    Camera2D camera{
    { window_width / 2, window_height / 2. },
    { window_width / 2, window_height / 2.},
    0,
    1.007,
    };

    InitAudioDevice();

    SetTargetFPS(target_frame_rate);

    HideCursor();

    loadimage();
    loadaudio();


    while (!exitWindow) {


        

        if (WindowShouldClose() || IsKeyPressed(KEY_ESCAPE)) {
            exitWindowRequested = true;
        }

        if (exitWindowRequested)
        {
            if (IsKeyPressed(KEY_Y)) exitWindow = true;
            else if (IsKeyPressed(KEY_N)) exitWindowRequested = false;
        }


        if (IsKeyPressed(KEY_ENTER) && (IsKeyDown(KEY_LEFT_ALT) || IsKeyDown(KEY_RIGHT_ALT)))
        {
            ToggleFullscreen();
        }

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
        BeginMode2D(camera);
        ClearBackground(WHITE);




        if (clickEffectActive) {
            double currentTime = GetTime();
            double elapsedTime = currentTime - clickEffectStartTime;

            if (elapsedTime < 0.06) {
                float offsetX = (float)GetRandomValue(-camera_offset, camera_offset);
                float offsetY = (float)GetRandomValue(-camera_offset, camera_offset);
                camerapos.x = window_width / 2 + offsetX;
                camerapos.y = window_height / 2 + offsetY;

                camera.target = { camerapos.x,camerapos.y };
            }

            else {
                //camera.target = { window_width / 2 , window_height / 2 };
                zoomEffectActive = false;
            }
        }


        if (camera.target.x > window_width / 2) {
            camera.target.x -= 0.05;
        }
        if (camera.target.x < window_width / 2) {
            camera.target.x += 0.05;
        }
        if (camera.target.y < window_height / 2) {
            camera.target.y += 0.05;
        }
        if (camera.target.y > window_height / 2) {
            camera.target.y -= 0.05;
        }



        if (false) {
            double currentTime = GetTime();
            double elapsedTime = currentTime - clickEffectStartTime;

            if (elapsedTime < 0.1) {
                camera.zoom = 1.01;
            }
            else {
                camera.zoom = 1.003;
                clickEffectActive = false;
            }
        }



        switch (gamestate) {
        case GameState::Startloading:
            startloding();
            break;
        case GameState::LobbyScreen:
            UpdateMusicStream(lobby_music);
            lobbyscreen();
            break;
        case GameState::Stage_1:
            UpdateMusicStream(stage1_music);
            stage_1();
            break;
        case GameState::Stage_2:
            UpdateMusicStream(stage1_music);
            stage_2();
            break;
        case GameState::Gameover:
            PauseMusicStream(stage1_music);
            gameover();
            break;
        case GameState::Setting:
            UpdateMusicStream(option_music);
            setting();
            break;
        case GameState::Star:
            UpdateMusicStream(option_music);
            leaderborad();
            break;
        case GameState::Challenge:
            UpdateMusicStream(option_music);
            challenge();
            break;
        }

        if (exitWindowRequested)
        {
            DrawRectangle(0, 100, GetScreenWidth(), 200, BLACK);
            DrawText("Are you sure you want to exit program? [Y/N]", 40, 180, 30, WHITE);
        }

        EndMode2D();
        EndDrawing();


        if (return_continuous_fail()) {

            //std::cout << "Boom!" << std::endl;
            zoomEffectActive = true;
            fail_StarTime = GetTime();
        }


        if (crow_just_erased) {
            clickEffectActive = true;
            clickEffectStartTime = GetTime();
        }
        if (window_close) {
            break;
        }

    }


    UnloadMusicStream(lobby_music);
    UnloadMusicStream(stage1_music);
    UnloadMusicStream(option_music);
    UnloadSound(crow_blow);
    UnloadFont(font);
    CloseAudioDevice();

    CloseWindow();
    return 0;
}