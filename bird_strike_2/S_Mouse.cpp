﻿/* GAM100

Seokhwa Hong

All content © 2023 DigiPen (USA) Corporation, all rights reserved. */


#include <iostream>
#include "raylib.h"
#include "H_Drag.h"
#include "H_Beat_system.h"
#include "H_Audio.h"
#include "H_GameState.h"

constexpr int mouse_R{ 6 };
constexpr int beat_circle_scale{ 25 };

void beat_circle() {
    Music music = return_music();
    DrawCircleLines(GetMouseX(), GetMouseY(), ((SecondTerms() - GetMusicTimePlayed(music)) * beat_circle_scale + beat_circle_scale) - 1, { 255, 255, 255, 125 });
    DrawCircleLines(GetMouseX(), GetMouseY(), (SecondTerms() - GetMusicTimePlayed(music)) * beat_circle_scale + beat_circle_scale, { 0,0,0,125 });
}

void mousedown() {
    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
        DrawCircleLines(GetMouseX(), GetMouseY(), mouse_R, WHITE);
        DrawCircle(GetMouseX(), GetMouseY(), mouse_R - 1, { 0,0,0,125 });

    }
}

void mouse() {
    if (!IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
        DrawCircleLines(GetMouseX(), GetMouseY(), mouse_R, BLACK);
        DrawCircleLines(GetMouseX(), GetMouseY(), mouse_R - 1, WHITE);
    }
}

void mouse_control() {
    mousedown();
    mouse();
}