#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "H_Beat_system.h"
#include "H_Score.h"
#include "H_Particle.h"
#include "H_Player.h"
#include "H_Audio.h"
#include "H_Sun.h"
#include "H_Crow.h"
#include "H_Main.h"
#include "H_Drag.h"
#include "H_Mouse.h"
#include "H_Image.h"

enum GameState {
    Startloading,
    LobbyScreen,
    Stage_1,
    Stage_2,
    Gameover,
    Setting,
    Star,
    Challenge
};

extern GameState gamestate;
extern bool window_close;

void startloding();
void start_game();
void end_game();
void lobbyscreen();
void stage_1();
void stage_2();
void gameover();
void setting();
void leaderborad();
void challenge();

#endif