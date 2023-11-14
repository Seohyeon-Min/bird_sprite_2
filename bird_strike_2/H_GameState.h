#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <raylib.h>
#include "sun.h"
#include "crow.h"
#include "beat_system.h"
#include "main.h"
#include "drag.h"
#include "mouse.h"
#include "image.h"

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