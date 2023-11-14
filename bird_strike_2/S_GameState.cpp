#include "GameState.h"

Vector2 mousepostion{ 0,0 };
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
    int btnState = 0;
    bool btnAcion = false;
    
    mousepostion = GetMousePosition();

    DrawText("Created by [Second Row Capybara]", 110, window_height / 2 - 50, text_size, BLACK);

    DrawText("DigiPen 2023", 280, window_height / 2, text_size, BLACK);

    DrawText("Press Space To Start", 200, window_height / 2 + 50, text_size, BLACK);

    DrawCircle(20, window_height -20, 10, BLACK);

    if (IsKeyPressed(KEY_SPACE)) {
        start_game();
    }
    if (CheckCollisionPointCircle(mousepostion, Vector2{ 20, window_height -20  }, 10)) {
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) btnState = 2;
        else btnState = 1;

        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) btnAcion = true;
    }
    else btnState = 0;
    
    if (btnAcion) {
        gamestate = GameState::Setting;
    }
    mouse_control();
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

void setting() {
    DrawText("Welcome! This is setting screen!", 110, window_height / 2 - 50, text_size, BLACK);
    mouse_control();
}