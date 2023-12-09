#include "H_GameState.h"
#include "H_Beat_system.h"
#include "H_Sun.h"
#include "H_Score.h"
#include "H_Particle.h"
#include "H_Player.h"
#include "H_Audio.h"

GameState gamestate = GameState::Startloading;
Crow crow;
Drag drag;
Player player;
constexpr int icon_width = 40;
constexpr int setting_position = 30;
constexpr int star_position = 90;
constexpr int challenge_position = 150;
extern bool is_gameover;
extern Vector2 mousepostion;
double animation_timer_title = 0;
bool window_close = false;
int title_x = 0;


void animation_move() {
    if (animation_timer_title < 40) {
        animation_timer_title += GetFrameTime() * 17;
        title_x = float(((float)title_Sheet_texture.width / 41 * (int)animation_timer_title));
    }
}

void draw_loading() {
    if (int(GetTime() < 3)) {
        ClearBackground(WHITE);

        DrawTexturePro(
            Capybara_texture,
            { 0,0,float(Capybara_texture.width),float(Capybara_texture.height) },
            { (float)GetScreenWidth() / 2 , (float)GetScreenHeight() / 2,capybara_size,capybara_size },
            { capybara_size / 2,capybara_size / 2 },
            0,
            { 255,255,255,255 });

    }

    else if (int(GetTime()) > 3 && int(GetTime()) < 7) {
        ClearBackground(WHITE);
        DrawTexturePro(
            DigiPenlogo_texture,
            { 0, 0, float(DigiPenlogo_texture.width), float(DigiPenlogo_texture.height) },
            { (float)GetScreenWidth() / 2 , (float)GetScreenHeight() / 2,float(DigiPenlogo_texture.width) / 2 ,float(DigiPenlogo_texture.height) / 2 },
            { float(DigiPenlogo_texture.width) / 4,float(DigiPenlogo_texture.height) / 4 },
            0,
            { 255,255,255,255 });
    }
}
void draw_lobby_animation() {
    DrawTexturePro(
        title_background_texture,
        { 0,0,float(title_background_image.width),  float(title_background_image.width)
        },
        { 0,0,(float)GetScreenWidth() , (float)GetScreenHeight()
        },
        { 0,0 },
        0,
        WHITE
    );
    DrawTexturePro(
        title_Sheet_texture,
        { float(title_x),0,384, 216
        },
        { 0,0,(float)GetScreenWidth() , (float)GetScreenHeight()
        },
        { 0,0 },
        0,
        WHITE
    );
}
void draw_lobby_icon() {
    DrawTexturePro(setting_icon_texture,
        { 0,0,float(setting_icon_image.height), float(setting_icon_image.width) },
        { setting_position,(float)GetScreenHeight() - (setting_position + icon_width),icon_width ,icon_width },
        { 0,0 },
        0,
        WHITE);
    DrawTexturePro(star_icon_texture,
        { 0,0,float(star_icon_image.width),float(star_icon_image.height) },
        { star_position,(float)GetScreenHeight() - (setting_position + icon_width),icon_width,icon_width },
        { 0,0 },
        0,
        WHITE);
    DrawTexturePro(challenge_icon_texture,
        { 0,0,float(challenge_icon_image.width),float(challenge_icon_image.height) },
        { challenge_position,(float)GetScreenHeight() - (setting_position + icon_width) + 1,icon_width ,icon_width },
        { 0,0 },
        0,
        WHITE);
}
void click_lobby_icon() {
    int btnState = 0;
    bool btnAcion = false;
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
}
void draw_lobby_button() {
    float box_witdh = (float)(GetScreenWidth() / 3);
    float box_height = (float)(GetScreenWidth() / 27.4);
    float x = GetScreenWidth() / 2 - box_witdh / 2;
    float y = (GetScreenHeight() / 44) * 30;
    int font_size = (float)(GetScreenWidth() / 27.4);
    int spacing_1 = (float)(GetScreenWidth() / 384);
    int spacing_2 = (float)(GetScreenWidth() / 192);
    unsigned char alpha = 0;

    Color text_color = { 255, 159, 68, 255 };
    Color box_color = { 255,255,255,178 };


    Rectangle rec = { GetScreenWidth() / 2 - box_witdh / 2, (GetScreenHeight() / 44) * 30, box_witdh, box_height };
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
}
void draw_game_over() {

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



void startloding() {
    draw_loading();
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
    PlayMusicStream(music);
    gamestate = GameState::Stage_2;

}

void end_game() {
    StopMusicStream(music);
    crows.clear();
    gamestate = GameState::Gameover;
}



void lobbyscreen() {

    animation_move();
    draw_lobby_animation();
    draw_lobby_icon();
    click_lobby_icon();
    draw_lobby_button();

    if (IsKeyPressed(KEY_SPACE)) {
        start_game();
    }
    
    mouse_control();
}


void stage_1() {

    if (is_sun_fall()) {
        StopMusicStream(music);
        start_stage_2();
    }
    _sun();
    if (is_gameover) {
        end_game();
    }
    IsOnBeat();
    beat_spliting();
    continuous_beat();
    Particle::update_particle();
    Effect::make_effect();
    Effect::update_effect();
    crow._crow();   
    drag.Fx(); 
    player._player();
    show_score();
    beat_circle();
    mouse_control();

}

int a = 255;

void stage_2() {

    

    if (is_gameover) {
        end_game();
    }
    ClearBackground(Color{ 4, 18, 31,255 });
    _sun_stage2();
    IsOnBeat();
    beat_spliting();
    continuous_beat();
    crow._crow();
    drag.Fx();
    player._player();
    show_score();

    if(a > 0){
        std::cout << a << std::endl;
        DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), { 255,255,255,(unsigned char)a });
        a-=5;
    }
    beat_circle();
    mouse_control();

}

void gameover() {

    _sun(); // todo: when you die in stage2, it should change into sun_stage2
    Effect::make_effect();
    Effect::update_effect();
    mouse_control();
    show_score();
    draw_game_over();

}

void setting() {
    PlayMusicStream(option_music);
    DrawText("Welcome! This is setting screen!", 110, (float)GetScreenHeight() / 2 - 50, text_size, BLACK);
    DrawText("Press Space to go back to the title.", 110, (float)GetScreenHeight() / 2 - 20, text_size, BLACK);
    mouse_control();
    if (IsKeyPressed(KEY_SPACE)) {
        StopMusicStream(option_music);
        gamestate = GameState::LobbyScreen;
    }
}


