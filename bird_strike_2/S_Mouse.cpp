#include <iostream>
#include "raylib.h"
#include "H_Drag.h"


constexpr int mouse_R{6};


void mousedown() {
    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
        //DrawCircleGradient(GetMouseX(), GetMouseY(), mousecircleR, BLACK, dragmouse);
        DrawCircleGradient(GetMouseX(), GetMouseY(), 5, BLACK, BLACK);

    }
}

void mouse() {
    if (!IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
        DrawCircleLines(GetMouseX(), GetMouseY(), mouse_R, BLACK);
        DrawCircleLines(GetMouseX(), GetMouseY(), mouse_R - 1, BLACK);
    }
}

void mouse_control() {
    mousedown();
    mouse();
}