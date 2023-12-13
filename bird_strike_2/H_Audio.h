#ifndef AUDIO_H
#define AUDIO_H
#include "raylib.h"
#include <iostream>

extern Music option_music;
extern Music lobby_music;
extern Music stage1_music;
extern Music stage2_music;
extern Sound crow_blow;
extern Sound to_two_phase;
extern Sound fly_in;
extern Sound hover_button;
extern Sound click_button;
extern Sound count_sound;
extern Music tutorial_music;



void loadaudio();

#endif