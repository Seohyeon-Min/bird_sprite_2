#include <iostream>
#include "raylib.h"
#include "H_Drag.h"
#include "H_Main.h"
#include "H_Beat_system.h"

constexpr int mouse_R{6};
constexpr int beat_circle_scale{25};

void beat_circle() {
    DrawCircleLines(GetMouseX(), GetMouseY(), ((SecondTerms() - GetMusicTimePlayed(music)) * beat_circle_scale + beat_circle_scale)-1, { 255, 255, 255, 125 });
    DrawCircleLines(GetMouseX(), GetMouseY(), (SecondTerms() - GetMusicTimePlayed(music)) * beat_circle_scale + beat_circle_scale, { 0,0,0,125 });
}

void mousedown() {
    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
        //DrawCircleGradient(GetMouseX(), GetMouseY(), mousecircleR, BLACK, dragmouse);
        DrawCircleLines(GetMouseX(), GetMouseY(), mouse_R, WHITE);
        //DrawCircleGradient(GetMouseX(), GetMouseY(), 5, BLACK, BLACK);
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