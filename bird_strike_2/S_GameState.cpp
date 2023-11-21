#include "H_GameState.h"
#include "H_Beat_system.h"
#include "H_Sun.h"

extern Vector2 mousepostion;
double animation_timer_title = 0;
int title_x = 0;
GameState gamestate = GameState::Startloading;

void startloding() {
    if (int(GetTime() < 3)) {
        ClearBackground(WHITE);

        DrawTexturePro(
            Capybara_texture,
            Rectangle{ 0,0,float(Capybara_texture.width),float(Capybara_texture.height) },
            Rectangle{ window_width / 2,window_height / 2,capybara_size,capybara_size },
            Vector2{ capybara_size / 2,capybara_size / 2 },
            0,
            Color{ 255,255,255,255 });

    }

    else if (int(GetTime()) > 3 && int(GetTime()) < 7) {
        ClearBackground(WHITE);
        DrawTexturePro(
            DigiPenlogo_texture,
            Rectangle{ 0, 0, float(DigiPenlogo_texture.width), float(DigiPenlogo_texture.height) },
            Rectangle{ window_width / 2,window_height / 2,float(DigiPenlogo_texture.width) / 2 ,float(DigiPenlogo_texture.height) / 2 },
            Vector2{ float(DigiPenlogo_texture.width) / 4,float(DigiPenlogo_texture.height) / 4 },
            0,
            Color{ 255,255,255,255 });
    }
    if (IsKeyReleased(MOUSE_BUTTON_LEFT) || IsKeyReleased(KEY_SPACE) || int(GetTime()) > 7) {
        gamestate = GameState::LobbyScreen;
    }
}

void start_game() {
    gamestate = GameState::Stage_1;

}

void start_stage_2() {
    gamestate = GameState::Stage_2;

}

void end_game() {
    gamestate = GameState::Gameover;

}

void animation_move() {
    if (animation_timer_title < 40) {
        animation_timer_title += GetFrameTime() * 17;
        title_x = float(((float)title_Sheet_texture.width / 41 * (int)animation_timer_title));
    }
}

Color co = Color{ 227, 98, 66 ,255 };

void lobbyscreen() {
    animation_move();
    int btnState = 0;
    bool btnAcion = false;
    ClearBackground(co);
    DrawTexturePro(
        title_Sheet_texture,
        { float(title_x),0,window_width / 2,  window_height / 2
        },
        { 0,0,window_width, window_height
        },
        { 0,0 },
        0,
        WHITE
    );
    DrawCircle(20, window_height - 20, 10, BLACK);//setting butten

    if (IsKeyPressed(KEY_SPACE)) {
        start_game();
    }
    if (CheckCollisionPointCircle(mousepostion, Vector2{ 20, window_height - 20 }, 10)) {
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

void stage_1() {
    Crow crow;
    Drag drag;
    extern bool is_gameover;
    if (_sun()) {
        start_stage_2();
    }
    IsOnBeat();
    beat_spliting();
    continuous_beat();
    crow._crow();
    drag.Fx();
    //std::cout << "gameover " << is_gameover() << std::endl;
    if (is_gameover) {
        end_game();
    }
    mouse_control();
    DrawTexture(grass_texture, 0, 0, WHITE);
}

void stage_2() {
    DrawText("state 2 !!", 270, window_height / 2 - 30, 40, BLACK);
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



