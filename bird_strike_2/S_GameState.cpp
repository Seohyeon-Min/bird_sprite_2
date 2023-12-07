#include "H_GameState.h"
#include "H_Beat_system.h"
#include "H_Sun.h"
#include "H_Score.h"
#include "H_Particle.h"
#include "H_Player.h"

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
            Rectangle{ (float)GetScreenWidth()/2 , (float)GetScreenHeight() / 2,capybara_size,capybara_size },
            Vector2{ capybara_size / 2,capybara_size / 2 },
            0,
            Color{ 255,255,255,255 });

    }

    else if (int(GetTime()) > 3 && int(GetTime()) < 7) {
        ClearBackground(WHITE);
        DrawTexturePro(
            DigiPenlogo_texture,
            Rectangle{ 0, 0, float(DigiPenlogo_texture.width), float(DigiPenlogo_texture.height) },
            Rectangle{ (float)GetScreenWidth() / 2 , (float)GetScreenHeight() / 2,float(DigiPenlogo_texture.width) / 2 ,float(DigiPenlogo_texture.height) / 2 },
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
    PlayMusicStream(music);
    is_gameover = false;
    gamestate = GameState::Stage_1;

}

void start_stage_2() {
    gamestate = GameState::Stage_2;

}

void end_game() {
    StopMusicStream(music);
    crows.clear();
    gamestate = GameState::Gameover;
}

void animation_move() {
    if (animation_timer_title < 40) {
        animation_timer_title += GetFrameTime() * 17;
        title_x = float(((float)title_Sheet_texture.width / 41 * (int)animation_timer_title));
    }
}

bool window_close = false;


void lobbyscreen() {
    animation_move();
    int btnState = 0;
    bool btnAcion = false;
    DrawTexturePro(
        title_background_texture,
        { 0,0,window_width / 2,  window_height / 2
        },
        { 0,0,(float)GetScreenWidth() , (float)GetScreenHeight()
        },
        { 0,0 },
        0,
        WHITE
    );
    DrawTexturePro(
        title_Sheet_texture,
        { float(title_x),0,window_width / 2,  window_height / 2
        },
        { 0,0,(float)GetScreenWidth() , (float)GetScreenHeight()
        },
        { 0,0 },
        0,
        WHITE
    );


    DrawTexturePro(setting_icon_texture,
        { 0,0,float(setting_icon_image.height), float(setting_icon_image.width) },
        { setting_position,(float)GetScreenHeight() - (setting_position + icon_width),icon_width,icon_width },
        { 0,0 },
        0,
        WHITE);
    DrawTexturePro(star_icon_texture,
        {0,0,float(star_icon_image.width),float(star_icon_image.height)},
        {star_position,(float)GetScreenHeight() -(setting_position+icon_width),icon_width,icon_width},
        {0,0},
        0,
        WHITE);
    DrawTexturePro(challenge_icon_texture,
        { 0,0,float(challenge_icon_image.width),float(challenge_icon_image.height) },
        { challenge_position,(float)GetScreenHeight() - (setting_position + icon_width)+1,icon_width,icon_width },
        { 0,0 },
        0,
        WHITE);

    float box_witdh = (float)(GetScreenWidth() / 3);
    float box_height = (float)(GetScreenWidth() / 27.4);
    float x = GetScreenWidth() / 2 - box_witdh / 2;
    float y = (GetScreenHeight() / 44) * 30;
    int font_size = (float)(GetScreenWidth() / 27.4);
    int spacing_1 = (float)(GetScreenWidth() / 384);
    int spacing_2 = (float)(GetScreenWidth() / 192);

    Color text_color = { 255, 159, 68, 255 };
    Color box_color = { 255,255,255,178 };

    Rectangle rec = { GetScreenWidth() / 2 - box_witdh / 2, (GetScreenHeight() / 44) * 30, box_witdh, box_height};
    Rectangle rec2 = { GetScreenWidth() / 2 - box_witdh / 2, (GetScreenHeight() / 44) * 34, box_witdh, box_height };
    Rectangle rec3 = { GetScreenWidth() / 2 - box_witdh / 2, (GetScreenHeight() / 44) * 38, box_witdh, box_height };
    if (CheckCollisionPointRec(GetMousePosition(), rec)) {
        DrawRectangle(GetScreenWidth() / 2 - box_witdh / 2, (GetScreenHeight() / 44) * 30, box_witdh, box_height, box_color);
        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
            start_game();
        }
    }
    if (CheckCollisionPointRec(GetMousePosition(), rec2)) {
        DrawRectangle(GetScreenWidth() / 2 - box_witdh / 2, (GetScreenHeight() / 44) * 34, box_witdh, box_height, box_color);
        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
        }
    }
    if (CheckCollisionPointRec(GetMousePosition(), rec3)) {
        DrawRectangle(GetScreenWidth() / 2 - box_witdh / 2, (GetScreenHeight() / 44) * 38, box_witdh, box_height, box_color);
        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
            window_close = true;
        }
    }


    DrawTextPro(
        font,
        "> GAMESTART <",
        { (float)(GetScreenWidth() / 2),(float)((GetScreenHeight() / 44) * 30) },
        { MeasureTextEx(font, "> GAMESTART <", font_size, spacing_1).x / 2, 0 },
        0,
        font_size,
        spacing_1,
        text_color);
    DrawTextPro(
        font,
        "> HOW TO PLAY <",
        { (float)(GetScreenWidth() / 2),(float)((GetScreenHeight() / 44) * 34) },
        { MeasureTextEx(font, "> HOW TO PLAY <", font_size, spacing_1).x / 2 ,0 },
        0,
        font_size,
        spacing_1,
        text_color);
    DrawTextPro(
        font,
        "> QUIT <",
        { (float)(GetScreenWidth() / 2),(float)((GetScreenHeight() / 44) * 38) },
        { MeasureTextEx(font, "> QUIT <", font_size, spacing_1).x / 2 ,0 },
        0,
        font_size,
        spacing_2,
        text_color);


    if (IsKeyPressed(KEY_SPACE)) {
        start_game();
    }
    if (GetMouseX() > setting_position && GetMouseX() < setting_position + icon_width && GetMouseY() > window_height - (setting_position + icon_width) && GetMouseY() < window_height - setting_position) { 
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) btnState = 2;
        else btnState = 1;
        DrawTexturePro(setting_icon_texture,
            { 0,0,float(setting_icon_image.height), float(setting_icon_image.width) },
            { setting_position,(float)GetScreenHeight() - (setting_position + icon_width),icon_width,icon_width },
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
Player player;
extern bool is_gameover;

void stage_1() {

    if (_sun()) {
        start_stage_2();
    }
    IsOnBeat();
    beat_spliting();
    continuous_beat();
    Particle::update_particle();
    Effect::make_effect();
    Effect::update_effect();
    crow._crow();   
    drag.Fx();
    if (is_gameover) {
        end_game();
    }
   /* DrawTexture(grass_texture, 0, 0, WHITE);*/
    beat_circle();
    show_score();

    player._player();
    mouse_control();
}

void stage_2() {
    ClearBackground(Color{ 4, 18, 31,255 });
    PlayMusicStream(music);
    _sun_stage2();
    IsOnBeat();
    beat_spliting();
    continuous_beat();
    crow._crow();
    drag.Fx();
    if (is_gameover) {
        end_game();
    }
    beat_circle();
    show_score();
    mouse_control();
    //DrawTexturePro(vignetting_texture,
    //    { 0,0,float(setting_icon_image.height), float(setting_icon_image.width) },
    //    { setting_position,window_height - (setting_position + setting_width),setting_width,setting_width },
    //    { 0,0 },
    //    0,
    //    { 125,125,125,255 });

}

void gameover() {

    if (_sun()) {
        start_stage_2();
    }
    Effect::make_effect();
    Effect::update_effect();
    if (is_gameover) {
        end_game();
    }
    mouse_control();
    show_score();

    int font_size = GetScreenWidth() / 15;
    int font_size_2 = GetScreenWidth() / 30;
    int spacing = GetScreenWidth() / 384;

    DrawTextPro(
        font,
        "GAME OVER!",
        { (float)(GetScreenWidth() / 2),(float)(GetScreenHeight() / 2) },
        { MeasureTextEx(font, "GAME OVER!", font_size, spacing).x / 2, MeasureTextEx(font, "GAME OVER!", font_size, spacing).y / 2 + MeasureTextEx(font, "GAME OVER!", font_size, spacing).y },
        0,
        font_size,
        spacing,
        BLACK);


    DrawTextPro(
        font,
        "> PRESS R TO RESTART <",
        { (float)(GetScreenWidth() / 2),(float)((GetScreenHeight() / 2) + 30) },
        { MeasureTextEx(font, "> PRESS R TO RESTART <", font_size_2, spacing).x / 2,0 },
        0,
        font_size_2,
        spacing,
        BLACK);
        if (IsKeyPressed(KEY_R)) {
            gamestate = GameState::LobbyScreen;
         }
}

void setting() {
    DrawText("Welcome! This is setting screen!", 110, (float)GetScreenHeight() / 2 - 50, text_size, BLACK);
    DrawText("Press Space to go back to the title.", 110, (float)GetScreenHeight() / 2 - 20, text_size, BLACK);
    mouse_control();
    if (IsKeyPressed(KEY_SPACE)) {
        gamestate = GameState::LobbyScreen;
    }
}


