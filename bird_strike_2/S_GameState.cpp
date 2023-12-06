#include "H_GameState.h"
#include "H_Beat_system.h"
#include "H_Sun.h"
#include "H_Score.h"
#include "H_Particle.h"

extern Vector2 mousepostion;
double animation_timer_title = 0;
int title_x = 0;
GameState gamestate = GameState::Startloading;
constexpr int icon_width = 25;
constexpr int setting_position = 15;
constexpr int star_position = 45;
constexpr int challenge_position = 75;


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
    mouse_control();
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


void lobbyscreen() {
    animation_move();
    int btnState = 0;
    bool btnAcion = false;
    DrawTexturePro(
        title_background_texture,
        { 0,0,window_width / 2,  window_height / 2
        },
        { 0,0,window_width, window_height
        },
        { 0,0 },
        0,
        WHITE
    );
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


    DrawTexturePro(setting_icon_texture,
        { 0,0,float(setting_icon_image.height), float(setting_icon_image.width) },
        { setting_position,window_height - (setting_position + icon_width),icon_width,icon_width },
        { 0,0 },
        0,
        WHITE);
    DrawTexturePro(star_icon_texture,
        {0,0,float(star_icon_image.width),float(star_icon_image.height)},
        {star_position,window_height-(setting_position+icon_width),icon_width,icon_width},
        {0,0},
        0,
        WHITE);
    DrawTexturePro(challenge_icon_texture,
        { 0,0,float(challenge_icon_image.width),float(challenge_icon_image.height) },
        { challenge_position,window_height - (setting_position + icon_width)+1,icon_width,icon_width },
        { 0,0 },
        0,
        WHITE);

    if (IsKeyPressed(KEY_SPACE)) {
        start_game();
    }
    if (GetMouseX() > setting_position && GetMouseX() < setting_position + icon_width && GetMouseY() > window_height - (setting_position + icon_width) && GetMouseY() < window_height - setting_position) { 
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) btnState = 2;
        else btnState = 1;
        DrawTexturePro(setting_icon_texture,
            { 0,0,float(setting_icon_image.height), float(setting_icon_image.width) },
            { setting_position,window_height - (setting_position + icon_width),icon_width,icon_width },
            { 0,0 },
            0,
            { 125,125,125,255 });

        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) btnAcion = true;
    }
    else btnState = 0;

    if (btnAcion) {
        gamestate = GameState::Setting;
    }
    mouse_control();
}
Crow crow;
Drag drag;
extern bool is_gameover;

void stage_1() {

    if (_sun()) {
        start_stage_2();
    }
    IsOnBeat();
    beat_spliting();
    continuous_beat();
    Particle::update_all();
    crow._crow();
    drag.Fx();
    if (is_gameover) {
        end_game();
    }
    DrawTexture(grass_texture, 0, 0, WHITE);
    beat_circle();
    show_score();


    mouse_control();
}

void stage_2() {
    ClearBackground({ 0,0,0,125 });
    DrawText("state 2 !!", 270, window_height / 2 - 30, 40, BLACK);
    IsOnBeat();
    beat_spliting();
    continuous_beat();
    show_score();
    crow._crow();
    drag.Fx();
    if (is_gameover) {
        end_game();
    }
    DrawTexture(grass_texture, 0, 0, WHITE);
    beat_circle();

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
    DrawText("Press Space to go back to the title.", 110, window_height / 2 - 20, text_size, BLACK);
    mouse_control();
    if (IsKeyPressed(KEY_SPACE)) {
        gamestate = GameState::LobbyScreen;
    }
}


