#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include "H_GameState.h"
#include "H_Beat_system.h"
#include "H_Sun.h"
#include "H_Score.h"
#include "H_Particle.h"
#include "H_Player.h"
#include "H_Audio.h"
#include "H_Option.h"
#include "H_Txt_read.h"
#include "H_Main.h"
#include "H_Tutorial.h"
#include "H_Crow_pattern.h"



#define MAX_INPUT_CHARS     3

GameState gamestate = GameState::Startloading;
Crow crow;
Crow_pattern crow_pattern_1;
Crow_pattern crow_pattern_2;
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
bool gameover_once = false;
bool save_once = true;
int title_x = 0;
float ChallengePositionY = 0;
int chall_count = 0;


bool call_flag1 = true;
bool call_flag2 = true;
bool call_flag3 = true;
bool call_flag4 = true;
bool call_flag5 = true;
bool call_flag6 = true;
bool call_flag7 = true;

bool IsAnyKeyPressed()
{
    bool keyPressed = false;
    int key = GetKeyPressed();

    if ((key >= 32) && (key <= 126)) keyPressed = true;

    return keyPressed;
}

char name[MAX_INPUT_CHARS + 1] = "\0";
int letterCount = 0;



void animation_move() {
    if (animation_timer_title < 40) {
        animation_timer_title += GetFrameTime() * 17;
        title_x = float(((float)title_Sheet_texture.width / 41 * (int)animation_timer_title));
    }
}

void draw_loading() {
    while (call_flag1 == true) {
        std::vector<ChallengeEntry> completed_ = loadChallenge(challengefile);
        std::string challengename = "Nice_to_meet_you";
        updateChallenge(completed_, challengename);
        saveChallenge(completed_, challengefile);
        call_flag1 = false;
    }

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
    int setting_btnState = 0;
    bool setting_btnAcion = false;
    int star_btnState = 0;
    bool star_btnAcion = false;
    int challenge_btnState = 0;
    bool challenge_btnAcion = false;
    static bool hasRun = false;
    static bool hasRun2 = false;
    static bool hasRun3 = false;

    Color setbtncolor = { 125,125,125,255 };
    Color text_color = { 255, 159, 68, 255 };
    Color text_outline_color = { WHITE };
    Color box_color = { 255,255,255,178 };


    Rectangle rec = { GetScreenWidth() / 2 - box_witdh / 2, (GetScreenHeight() / 44) * 30, box_witdh, box_height };
    Rectangle rec2 = { GetScreenWidth() / 2 - box_witdh / 2, (GetScreenHeight() / 44) * 34, box_witdh, box_height };
    Rectangle rec3 = { GetScreenWidth() / 2 - box_witdh / 2, (GetScreenHeight() / 44) * 38, box_witdh, box_height };


    if (CheckCollisionPointRec(GetMousePosition(), rec)) {
        if (!hasRun) {
            PlaySound(hover_button);
            hasRun = true;
        }
        
        DrawRectangle(GetScreenWidth() / 2 - box_witdh / 2, (GetScreenHeight() / 44) * 30, box_witdh, box_height, box_color);
        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
            PlaySound(click_button);

            start_game();

        }
    }
    else {
        hasRun = false;
    }
    

    if (CheckCollisionPointRec(GetMousePosition(), rec2)) {
        if (!hasRun2) {
            PlaySound(hover_button);
            hasRun2 = true;
        }
        DrawRectangle(GetScreenWidth() / 2 - box_witdh / 2, (GetScreenHeight() / 44) * 34, box_witdh, box_height, box_color);
        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
            PlaySound(click_button);
            gamestate = GameState::Tutorial;
        }
    }
    else {
        hasRun2 = false;
    }

    if (CheckCollisionPointRec(GetMousePosition(), rec3)) {
        if (!hasRun3) {
            PlaySound(hover_button);
            hasRun3 = true;
        }
        DrawRectangle(GetScreenWidth() / 2 - box_witdh / 2, (GetScreenHeight() / 44) * 38, box_witdh, box_height, box_color);
        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
            window_close = true;
        }
    }
    else {
        hasRun3 = false;
    }
        if (GetMouseX() > setting_position && GetMouseX() < setting_position + icon_width && GetMouseY() > window_height - (setting_position + icon_width) && GetMouseY() < window_height - setting_position) {
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) setting_btnState = 2;
        else setting_btnState = 1;
        DrawTexturePro(setting_icon_texture,
            { 0,0,float(setting_icon_image.height), float(setting_icon_image.width) },
            { setting_position,window_height - (setting_position + icon_width),icon_width,icon_width },
            { 0,0 },
            0,
            setbtncolor);

        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) setting_btnAcion = true;
    }
    else setting_btnState = 0;
    if (setting_btnAcion) {
        gamestate = GameState::Setting;
    }

    if (GetMouseX() > star_position && GetMouseX() < star_position + icon_width && GetMouseY() > window_height - (setting_position + icon_width) && GetMouseY() < window_height - setting_position) {
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) star_btnState = 2;
        else star_btnState = 1;
        DrawTexturePro(star_icon_texture,
            { 0,0,float(star_icon_image.width),float(star_icon_image.height) },
            { star_position,window_height - (setting_position + icon_width),icon_width,icon_width },
            { 0,0 },
            0,
            setbtncolor);
        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) star_btnAcion = true;
    }
    else star_btnState = 0;
    if (star_btnAcion) {
        gamestate = GameState::Star;
    }

    if (GetMouseX() > challenge_position && GetMouseX() < challenge_position + icon_width && GetMouseY() > window_height - (setting_position + icon_width) && GetMouseY() < window_height - setting_position) {
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) challenge_btnState = 2;
        else challenge_btnState = 1;
        DrawTexturePro(challenge_icon_texture,
            { 0,0,float(challenge_icon_image.width),float(challenge_icon_image.height) },
            { challenge_position,window_height - (setting_position + icon_width) + 1,icon_width,icon_width },
            { 0,0 },
            0,
            setbtncolor);
        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) challenge_btnAcion = true;
    }
    else challenge_btnState = 0;
    if (challenge_btnAcion) {
        gamestate = GameState::Challenge;
    }
    DrawTextPro(font, "> GAMESTART <", { (float)(GetScreenWidth() / 2) + 2,(float)((GetScreenHeight() / 44) * 30) }, { MeasureTextEx(font, "> GAMESTART <", font_size, spacing_1).x / 2, 0 }, 0, font_size, spacing_1, text_outline_color);
    DrawTextPro(font, "> GAMESTART <", { (float)(GetScreenWidth() / 2) - 2,(float)((GetScreenHeight() / 44) * 30) }, { MeasureTextEx(font, "> GAMESTART <", font_size, spacing_1).x / 2, 0 }, 0, font_size, spacing_1, text_outline_color);
    DrawTextPro(font, "> GAMESTART <", { (float)(GetScreenWidth() / 2),(float)((GetScreenHeight() / 44) * 30) + 2 }, { MeasureTextEx(font, "> GAMESTART <", font_size, spacing_1).x / 2, 0 }, 0, font_size, spacing_1, text_outline_color);
    DrawTextPro(font, "> GAMESTART <", { (float)(GetScreenWidth() / 2),(float)((GetScreenHeight() / 44) * 30) - 2 }, { MeasureTextEx(font, "> GAMESTART <", font_size, spacing_1).x / 2, 0 }, 0, font_size, spacing_1, text_outline_color);
    DrawTextPro(font, "> GAMESTART <", { (float)(GetScreenWidth() / 2),(float)((GetScreenHeight() / 44) * 30) }, { MeasureTextEx(font, "> GAMESTART <", font_size, spacing_1).x / 2, 0 }, 0, font_size, spacing_1, text_color);

    DrawTextPro(font, "> HOW TO PLAY <", { (float)(GetScreenWidth() / 2) + 2,(float)((GetScreenHeight() / 44) * 34) }, { MeasureTextEx(font, "> HOW TO PLAY <", font_size, spacing_1).x / 2 ,0 }, 0, font_size, spacing_1, text_outline_color);
    DrawTextPro(font, "> HOW TO PLAY <", { (float)(GetScreenWidth() / 2) - 2,(float)((GetScreenHeight() / 44) * 34) }, { MeasureTextEx(font, "> HOW TO PLAY <", font_size, spacing_1).x / 2 ,0 }, 0, font_size, spacing_1, text_outline_color);
    DrawTextPro(font, "> HOW TO PLAY <", { (float)(GetScreenWidth() / 2),(float)((GetScreenHeight() / 44) * 34) + 2 }, { MeasureTextEx(font, "> HOW TO PLAY <", font_size, spacing_1).x / 2 ,0 }, 0, font_size, spacing_1, text_outline_color);
    DrawTextPro(font, "> HOW TO PLAY <", { (float)(GetScreenWidth() / 2),(float)((GetScreenHeight() / 44) * 34) - 2 }, { MeasureTextEx(font, "> HOW TO PLAY <", font_size, spacing_1).x / 2 ,0 }, 0, font_size, spacing_1, text_outline_color);
    DrawTextPro(font, "> HOW TO PLAY <", { (float)(GetScreenWidth() / 2),(float)((GetScreenHeight() / 44) * 34) }, { MeasureTextEx(font, "> HOW TO PLAY <", font_size, spacing_1).x / 2 ,0 }, 0, font_size, spacing_1, text_color);

    DrawTextPro(font, "> QUIT <", { (float)(GetScreenWidth() / 2) + 2,(float)((GetScreenHeight() / 44) * 38) }, { MeasureTextEx(font, "> QUIT <", font_size, spacing_1).x / 2 ,0 }, 0, font_size, spacing_2, text_outline_color);
    DrawTextPro(font, "> QUIT <", { (float)(GetScreenWidth() / 2) - 2,(float)((GetScreenHeight() / 44) * 38) }, { MeasureTextEx(font, "> QUIT <", font_size, spacing_1).x / 2 ,0 }, 0, font_size, spacing_2, text_outline_color);
    DrawTextPro(font, "> QUIT <", { (float)(GetScreenWidth() / 2),(float)((GetScreenHeight() / 44) * 38) + 2 }, { MeasureTextEx(font, "> QUIT <", font_size, spacing_1).x / 2 ,0 }, 0, font_size, spacing_2, text_outline_color);
    DrawTextPro(font, "> QUIT <", { (float)(GetScreenWidth() / 2),(float)((GetScreenHeight() / 44) * 38) - 2 }, { MeasureTextEx(font, "> QUIT <", font_size, spacing_1).x / 2 ,0 }, 0, font_size, spacing_2, text_outline_color);
    DrawTextPro(font, "> QUIT <", { (float)(GetScreenWidth() / 2),(float)((GetScreenHeight() / 44) * 38) }, { MeasureTextEx(font, "> QUIT <", font_size, spacing_1).x / 2 ,0 }, 0, font_size, spacing_2, text_color);
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



    int key = GetCharPressed();

    while (key > 0)
    {
        if ((key >= 65) && (key <= 90) && (letterCount < MAX_INPUT_CHARS))
        {
            name[letterCount] = (char)key;
            name[letterCount + 1] = '\0';
        }
        if ((key >= 97) && (key <= 122) && (letterCount < MAX_INPUT_CHARS))
        {
            name[letterCount] = (char)(key - 32);
            name[letterCount + 1] = '\0';

            letterCount++;
        }

        key = GetCharPressed();
    }

    if (IsKeyPressed(KEY_BACKSPACE))
    {
        letterCount--;
        if (letterCount < 0) letterCount = 0;
        name[letterCount] = '\0';
    }

    if (save_once == true && letterCount == 3) {
        if (IsKeyPressed(KEY_ENTER)) {
            gameover_once = true;
            save_once = false;
            letterCount = 0;
        }
    }


    while (gameover_once == true) {
        std::vector<ScoreEntry> scores = loadScores(scorefile);
        scores.emplace_back(name, *return_score());
        std::sort(scores.begin(), scores.end(), [](const ScoreEntry& a, const ScoreEntry& b) {
            return a.score > b.score;
            });
        saveScores(scores, scorefile);
        gameover_once = false;
    }


    if (save_once == false) {
        DrawTextPro(font,
            "SAVE COMPLETE!",
            { (float)GetScreenWidth() / 2,200 },
            { MeasureTextEx(font,"SAVE COMPLETE!", 30, GetScreenWidth() / 384).x / 2 , 0 },
            0,
            30,
            GetScreenWidth() / 384,
            BLACK);
        DrawTextPro(
            font,
            "> PRESS R TO RESTART THE GAME <",
            { (float)(GetScreenWidth() / 2),(float)((GetScreenHeight() / 2) + 30) },
            { MeasureTextEx(font, "> PRESS R TO RESTART THE GAME  <", font_size_2, spacing).x / 2,0 },
            0,
            font_size_2,
            spacing,
            BLACK);

        if (IsKeyPressed(KEY_R)) {
            save_once = true;
            *return_score() = 0;
            *return_BPM() = 100;
            gamestate = GameState::LobbyScreen;
        }
    }
    else {
        DrawTextPro(
            font,
            "> ENTER YOUR NAME TO SAVE <",
            { (float)(GetScreenWidth() / 2),(float)((GetScreenHeight() / 2) + 30) },
            { MeasureTextEx(font, "> ENTER YOUR NAME TO SAVE <", font_size_2, spacing).x / 2,0 },
            0,
            font_size_2,
            spacing,
            BLACK);
    }
    DrawTextPro(font,
        name,
        { (float)GetScreenWidth() / 2,453 },
        { MeasureTextEx(font, name, GetScreenWidth() / 15, GetScreenWidth() / 384).x / 2,0 },
        0,
        GetScreenWidth() / 15,
        GetScreenWidth() / 384,
        BLACK);
}
void draw_setting_button() {
    DrawRectangleRounded(
        { 965,   66,
        50,  50 },
        0.09,
        0,
        BLACK
    );
    DrawTextPro(
        font,
        "X",
        { 973,  66 },
        { 0,0 },
        0,
        50,
        2,
        { 251, 241, 232, 255 });


    DrawRectangleRounded(
        { (float)GetScreenWidth() / 2 - MeasureTextEx(font,"CREDIT", 50, 2).x / 2 - 15,   540,
        MeasureTextEx(font,"CREDIT", 50, 2).x + 30,    MeasureTextEx(font,"CREDIT", 50, 2).y + 10 },
        0.09,
        0,
        BLACK
    );

    DrawTextPro(
        font,
        "CREDIT",
        { (float)GetScreenWidth() / 2,  540 },
        { MeasureTextEx(font,"CREDIT", 50, 2).x / 2, -5 },
        0,
        50,
        2,
        { 251, 241, 232, 255 });

    if (CheckCollisionPointRec(GetMousePosition(), { (float)GetScreenWidth() / 2 - MeasureTextEx(font,"CREDIT", 50, 2).x / 2 - 15,   540,
        MeasureTextEx(font,"CREDIT", 50, 2).x + 30,    MeasureTextEx(font,"CREDIT", 50, 2).y + 10 }) && IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
        gamestate = GameState::Credit;
    }

    if (CheckCollisionPointRec(GetMousePosition(), { 965, 66, 50, 50 }) && IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
        StopMusicStream(option_music);
        gamestate = GameState::LobbyScreen;
    }
}

Music music_here;
Music return_music() {
    return music_here;
}



void startloding() {
    music_here = stage1_music;
    SetSoundVolume(crow_blow, default_SFX);
    SetMusicVolume(stage1_music, default_music);
    draw_loading();
    if (IsKeyReleased(MOUSE_BUTTON_LEFT) || IsKeyReleased(KEY_SPACE) || int(GetTime()) > 7) {
        PlaySound(fly_in);
        make_bars();
        gamestate = GameState::LobbyScreen;
    }
    mouse_control();
}
void start_game() {
    *return_BPM() = 100;
    StopMusicStream(lobby_music);
    PlayMusicStream(stage1_music);
    music_here = stage1_music;
    is_gameover = false;
    gamestate = GameState::Stage_1;

}

void start_stage_2() {
    *return_BPM() = 140;
    StopMusicStream(stage1_music);
    PlayMusicStream(stage2_music);
    music_here = stage2_music;
    gamestate = GameState::Stage_2;

}

void end_game() {
    is_gameover = true;
    StopMusicStream(stage1_music);
    StopMusicStream(stage2_music);
    music_here = stage1_music;
    crows.clear();
    gamestate = GameState::Gameover;
}
void lobbyscreen() {

    PlayMusicStream(lobby_music);
    
    animation_move();
    draw_lobby_animation();
    draw_lobby_icon();
    click_lobby_icon();
    draw_lobby_button();
    mouse_control();
}


void stage_1() {
    if (return_order_counter() > 11) {
        while (call_flag3 == true) {
            std::vector<ChallengeEntry> completed_ = loadChallenge(challengefile);
            std::string challengename = "Best_aimer";
            updateChallenge(completed_, challengename);
            saveChallenge(completed_, challengefile);
            call_flag3 = false;
        }
    }
    else if (return_order_counter() > 19) {
        while (call_flag4 == true) {
            std::vector<ChallengeEntry> completed_ = loadChallenge(challengefile);
            std::string challengename = "Crazy_aimer";
            updateChallenge(completed_, challengename);
            saveChallenge(completed_, challengefile);
            call_flag4 = false;
        }
    }

    if (is_sun_fall() && *return_score() >= 100) {
        StopMusicStream(stage1_music);
        SetSoundVolume(to_two_phase, 2.0f);
        PlaySound(to_two_phase);
        WaitTime(2);
        start_stage_2();
    }
    if (is_sun_fall() && *return_score() <= 100) {
        end_game();
    }

    _sun();

    if (is_gameover) {
        end_game();
    }
    
    IsOnBeat(true);
    beat_spliting();
    continuous_beat();
    Particle::update_particle();
    Effect::make_effect();
    Effect::update_effect();
    show_score();
    crow._crow();   
    drag.Fx(); 
    player._player();
    beat_circle();
    mouse_control();

}

int a = 255;

void stage_2() {
    if (return_order_counter() > 11) {
        while (call_flag3 == true) {
            std::vector<ChallengeEntry> completed_ = loadChallenge(challengefile);
            std::string challengename = "Best_aimer";
            updateChallenge(completed_, challengename);
            saveChallenge(completed_, challengefile);
            call_flag3 = false;
        }
    }
    else if (return_order_counter() > 19) {
        while (call_flag4 == true) {
            std::vector<ChallengeEntry> completed_ = loadChallenge(challengefile);
            std::string challengename = "Crazy_aimer";
            updateChallenge(completed_, challengename);
            saveChallenge(completed_, challengefile);
            call_flag4 = false;
        }
    }

    while (call_flag5 == true) {
        std::vector<ChallengeEntry> completed_ = loadChallenge(challengefile);
        std::string challengename = "Not_done";
        updateChallenge(completed_, challengename);
        saveChallenge(completed_, challengefile);
        call_flag5 = false;
    }
    

    if (is_gameover) {
        end_game();
    }
    ClearBackground(Color{ 4, 18, 31,255 });
    _sun_stage2();
    IsOnBeat(true);
    beat_spliting();
    continuous_beat();
    Particle::update_particle();
    Effect::make_effect2();
    Effect::update_effect();
    crow._crow();
    crow_pattern_1.fire_crow();
    crow_pattern_1.aim_line();
    crow_pattern_1.draw();
    if (crow_pattern_1.line_colide()) {
        drag.fail_drag();
        delete_crow();
    }
    //crow_pattern_2.fire_crow();
    //crow_pattern_2.aim_line();
    //crow_pattern_2.draw();
    //if (crow_pattern_2.line_colide()) {
    //    drag.fail_drag();
    //    delete_crow();
    //}
    drag.Fx();
    player._player();


    BeginBlendMode(BLEND_ADDITIVE);
    DrawTexturePro(vignetting_texture,
        { 0,0,float(vignetting_image.width), float(vignetting_image.height) },
        { 0,0, (float)GetScreenWidth(), (float)GetScreenHeight() },
        { 0,0 },
        0,
        WHITE);
    EndBlendMode();

    Light::make_light();
    Light::update_light();
    show_score();

    if (a > 0) {
        //std::cout << a << std::endl;
        DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), { 255,255,255,(unsigned char)a });
        a -= 5;
    }
    beat_circle();
    mouse_control();

}

void gameover() {

    if (*return_score() == 0) {
        while (call_flag2 == true) {
            std::vector<ChallengeEntry> completed_ = loadChallenge(challengefile);
            std::string challengename = "Its_my_first_day";
            updateChallenge(completed_, challengename);
            saveChallenge(completed_, challengefile);
            call_flag2 = false;
        }
    }
    if (*return_score() > 10000) {
        while (call_flag6 == true) {
            std::vector<ChallengeEntry> completed_ = loadChallenge(challengefile);
            std::string challengename = "Bird_striker";
            updateChallenge(completed_, challengename);
            saveChallenge(completed_, challengefile);
            call_flag6 = false;
        }
    }


    _sun(); // todo: when you die in stage2, it should change into sun_stage2
    Effect::make_effect();
    Effect::update_effect();
    mouse_control();
    show_score();
    draw_game_over();

}

void setting() {
    _sun();
    StopMusicStream(lobby_music);
    Control_bar bar;
    bar.update_all();
    PlayMusicStream(option_music);
    draw_setting_button();
    mouse_control();
}

void credit() {
    DrawTexturePro(credit_texture,
        { 0,0,float(credit_image.width), float(credit_image.height) },
        { 0,0, (float)GetScreenWidth(), (float)GetScreenHeight() },
        { 0,0 },
        0,
        WHITE);

    if (IsKeyPressed(KEY_SPACE)) {
        gamestate = GameState::Setting;
    }

}


bool load_leaderbored_once = true;

void leaderborad() {
    ClearBackground({ 251,241,232,255 });

    static bool scoresLoaded = false;
    static std::vector<ScoreEntry> scores;

    std::vector<Color>textcolor = {
        {217,166,71,255},
        {167, 165, 177,255},
        {139,110,107,255},
        {BLACK},
        {BLACK}
    };

    std::vector<const char*>textborard = {
    "1st",
    "2nd",
    "3rd",
    "4th",
    "5th"
    };

    DrawTextPro(font, ">LEADERBORAD<", { 180,150 }, { 0,50  }, 0, 102, 15, BLACK);
    DrawTextPro(font, "Press the 'SPACEBAR' to get out", { 370,330 }, { 0,100}, 0, 25, 5, { 0,0,0,100 });


    if (!scoresLoaded) {
        scores = loadScores(scorefile);
        scoresLoaded = true;
    }
    for (int i = 0; i < 5 && i < scores.size(); i++) {
        const ScoreEntry& entry = scores[i];
        std::string scoreString = std::to_string(scores[i].score);
        const char* savedScore = scoreString.c_str();
        const char* savedName = scores[i].playerName.c_str();
        DrawTextPro(font,
            textborard[i],
            { 200,float(300 + (60 * i)) },
            { 0,0 },
            0,
            GetScreenWidth() / 15,
            GetScreenWidth() / 384,
            textcolor[i]);
        DrawTextPro(font,
            savedName, 
            { (float)GetScreenWidth()/2-150,float(300 + (60 * i))},
            {0,0},
            0, 
            GetScreenWidth() / 15, 
            GetScreenWidth() / 384, 
            textcolor[i]); 
        DrawTextPro(font, 
            savedScore, 
            { (float)GetScreenWidth() / 2 + 150,float(300 +(60*i))},
            {0,0},
            0, 
            GetScreenWidth() / 15,
            GetScreenWidth() / 384, 
            textcolor[i]);
    }

    DrawTexturePro(kingturi_texture,
        { 0,0,(float)kingturi_image.width,(float)kingturi_image.height },
        {(float)GetScreenWidth()-210,(float)GetScreenHeight()-200,200,200},
        {0,0},
        0,
        WHITE
        );
    if (IsKeyPressed(KEY_SPACE)) {
        gamestate = GameState::LobbyScreen;
        scoresLoaded = false;
    }
}
void challenge() {
    std::vector<ChallengeEntry> completed_ = loadChallenge(challengefile);
    int scrollSpeed = 30;
    float recoffest = 20;
    std::vector<Texture> clear_challengelist =
    {
        Nice_to_meet_you_1_texture,
        Its_my_first_day_1_texture,
        best_aimer_1_texture,
        carzy_aimer_1_texture,
        not_done_1_texture,
        strike_1_texture,
        BIRD_STRIKER_1_texture,
        THE_BIRD_1_texture
    };

    std::vector<Texture> unclear_challengelist =
    {
        Nice_to_meet_you_2_texture,
        Its_my_first_day_2_texture,
        best_aimer_2_texture,
        carzy_aimer_2_texture,
        not_done_2_texture,
        strike_2_texture,
        BIRD_STRIKER_2_texture,
        THE_BIRD_2_texture
    };

    ChallengePositionY += (GetMouseWheelMove() * scrollSpeed);
    if (ChallengePositionY > 0) {
        ChallengePositionY = 0;
    }
    else if (ChallengePositionY < -3150) {
        ChallengePositionY = -3150;
    }
    DrawTextPro(font, ">ACHIEVENMENTS<", { 100,100 }, { 0,50 - ChallengePositionY }, 0, 102, 15, BLACK);
    DrawTextPro(font, "Can you achieve the following tasks?", { 120,310 }, { 0,100 - ChallengePositionY }, 0, 50, 5, BLACK);
    DrawTextPro(font, "Achieve the challenges and get 'THE BIRD'", { 57,360 }, { 0,100 - ChallengePositionY }, 0, 50, 5, BLACK);
    DrawTextPro(font, "Press the 'SPACEBAR' to get out", { 370,450 }, { 0,100 - ChallengePositionY }, 0, 25, 5, { 0,0,0,100 });

    for (int i = 0; i < completed_.size(); i++) {
        chall_count += 1;
        const ChallengeEntry& entry = completed_[i];
        if (completed_[i].completed == true) {
            DrawTexturePro(clear_challengelist[i], { 0,0,(float)Nice_to_meet_you_2_image.width,(float)Nice_to_meet_you_2_image.height }, { 0 + recoffest,Nice_to_meet_you_2_image.height * (3 * (i + 1)) + ChallengePositionY,GetScreenWidth() - recoffest,(float)(GetScreenHeight() / 2) + recoffest * 2 }, { 0,0 }, 0, WHITE);
            if (chall_count == 7) {
                while (call_flag7 == true) {
                    std::vector<ChallengeEntry> completed_ = loadChallenge(challengefile);
                    std::string challengename = "The_bird";
                    updateChallenge(completed_, challengename);
                    saveChallenge(completed_, challengefile);
                    call_flag7 = false;
                }
            }
        }
        else {
            DrawTexturePro(unclear_challengelist[i], { 0,0,(float)Nice_to_meet_you_2_image.width,(float)Nice_to_meet_you_2_image.height }, { 0 + recoffest,Nice_to_meet_you_2_image.height * (3 * (i + 1)) + ChallengePositionY,GetScreenWidth() - recoffest,(float)(GetScreenHeight() / 2) + recoffest * 2 }, { 0,0 }, 0, WHITE);
        }

    }


    mouse_control();
    if (IsKeyPressed(KEY_SPACE)) {
        gamestate = GameState::LobbyScreen;
        ChallengePositionY = 0;
    }
}

