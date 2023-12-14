/* GAM100

Seohyeon Min

All content © 2023 DigiPen (USA) Corporation, all rights reserved. */


#ifndef AUDIO_H
#define AUDIO_H
#include "raylib.h"
#include <iostream>

extern Music option_music;
extern Music lobby_music;
extern Music stage1_music;
extern Music stage2_music;
extern Music tutorial_music;
extern Sound crow_blow;
extern Sound count_sound;
extern Sound fly_in;
extern Sound hover_button;
extern Sound click_button;
extern Sound to_two_phase;



void loadaudio();

#endif