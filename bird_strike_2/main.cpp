#include <raylib.h>
#include <iostream>
#include "sun.h"
#include "crow.h"
#include "beat_system.h"
#include "main.h"
#include "drag.h"
#include "mouse.h"
#include "image.h"

enum GameState {
    Startloading,
    LobbyScreen,
    Gameplay,
    Gameover
};
GameState gamestate = GameState::Startloading;

void startloding() {
    if (int(GetTime() < 2)) {
        ClearBackground(WHITE);

        DrawTexturePro(
            Capybara_texture,
            Rectangle{ 0,0,float(Capybara_texture.width),float(Capybara_texture.height) },
            Rectangle{ window_width / 2,window_height / 2,capybara_size,capybara_size },
            Vector2{ capybara_size / 2,capybara_size / 2 },
            0,
            Color{ 255,255,255,255 });

    }
    
    else if (int(GetTime()) > 2 && int(GetTime()) < 6) {
        ClearBackground(WHITE);
        DrawTexturePro(
            DigiPenlogo_texture,
            Rectangle{ 0, 0, float(DigiPenlogo_texture.width), float(DigiPenlogo_texture.height) },
            Rectangle{ window_width / 2,window_height / 2,float(DigiPenlogo_texture.width) / 2 ,float(DigiPenlogo_texture.height) / 2 },
            Vector2{ float(DigiPenlogo_texture.width) / 4,float(DigiPenlogo_texture.height) / 4 },
            0,
            Color{ 255,255,255,255 });
    }
    if (IsKeyReleased(MOUSE_BUTTON_LEFT) || IsKeyReleased(KEY_SPACE) || int(GetTime()) > 6) {
        gamestate = GameState::LobbyScreen;
    }
}

void start_game() {
    gamestate = GameState::Gameplay;

}
void end_game() {
    gamestate = GameState::Gameover;

}

void lobbyscreen() {
    DrawText("Created by [Second Row Capybara]", 110, window_height / 2 - 50, text_size, BLACK);

    DrawText("DigiPen 2023", 280, window_height / 2, text_size, BLACK);

    DrawText("Press Space To Start", 200, window_height / 2 + 50, text_size, BLACK);

    if (IsKeyPressed(KEY_SPACE)) {
        start_game();
    }
}

void gameplay() {
    Crow crow;
    Drag drag;
    extern bool is_gameover;
    float i = drop_v(GetTime());
    draw_sun(i);
    //std::cout << i - 325 << "    ,    " << GetTime() << std::endl;
    IsOnBeat();
    crow._crow();
    drag.Fx();
    //std::cout << "gameover " << is_gameover() << std::endl;
    if (is_gameover) {
        end_game();
    }
    mouse_control();
}

void gameover() {
    DrawText("Game over!", 270, window_height / 2 - 30, 40, BLACK);
    //DrawText("Press R to restart", 270, window_height / 2 + 10 , 20, BLACK);
    //if (IsKeyPressed(KEY_R)) {
    //    start_game();
    //}
}

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
        }
        EndDrawing();
    }

    CloseWindow();
    return 0;
}