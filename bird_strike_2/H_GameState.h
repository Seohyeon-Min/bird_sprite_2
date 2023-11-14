#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <raylib.h>
#include "H_Sun.h"
#include "H_Crow.h"
#include "H_Main.h"
#include "H_Drag.h"
#include "H_Mouse.h"
#include "H_Image.h"

enum GameState {
    Startloading,
    LobbyScreen,
    Gameplay,
    Gameover,
    Setting
};

extern GameState gamestate;

void startloding();
void start_game();
void end_game();
void lobbyscreen();
void gameplay();
void gameover();
void setting();

#endif