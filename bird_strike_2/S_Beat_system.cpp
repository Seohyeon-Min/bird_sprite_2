/* GAM100

Seohyeon Min
Hyeonseong Bae

All content © 2023 DigiPen (USA) Corporation, all rights reserved. */

#include <iostream>
#include <raylib.h>
#include "H_Crow.h"
#include "H_Main.h"
#include "H_Drag.h"
#include "H_Score.h"
#include "H_Audio.h"
#include "H_Image.h"
#include "H_GameState.h"
#include "H_Crow_pattern.h"

constexpr double judge_offSet = 0.1;
constexpr double judge_offSet_stage2 = 0.05;
constexpr double judge_offSet_great = 0.05;
constexpr int trigger_bar = 1;

int BPM = 100;


bool crow_delete_flag = false;
bool prev_judge = false;
bool judge = false;
bool judge_great = false;
bool is_changed_j = false;
bool is_changed = false;
bool continuous_fail = false;
bool connect_4 = false;

double SecondTerm = 60.0 / BPM;

float SecondTerms() {
    Music music = return_music();
    double time = double(GetMusicTimePlayed(music));
    int beat_count = time / SecondTerm;

    return float(beat_count * SecondTerm);
}

int* return_BPM() {
    return &BPM;
}

void IsOnBeat(bool for_T) {
    SecondTerm = 60.0 / BPM;
    Music music = return_music();
    double time = double(GetMusicTimePlayed(music));
    is_changed_j = false;
    static bool hasRun = false;
    //judge
    if (time < double(SecondTerms() + judge_offSet) &&
        time >  double(SecondTerms() - judge_offSet)) {
        judge = true;
        if (!for_T && judge) {
            DrawTextPro(font, "BEAT!", { (float)GetScreenWidth() / 2 - 50,100 }, { 0,0 }, 0, 30, 5, BLACK);
        }
        if (time < double(SecondTerms() + judge_offSet_great) &&
            time >  double(SecondTerms() - judge_offSet_great)) {
            judge_great = true;
        }
        else
        {
            judge_great = false;
        }
    }
    else
    {
        judge = false;
    }
    if (for_T == true) {
        if (int(SecondTerms() / SecondTerm) % 5 == 0) {
            if (!hasRun) {
                for (int c = 0; c < 3; c++) {
                    Crow* p_crow = new Crow;
                    p_crow->add_crow();
                }
                hasRun = true;
            }
        }
        else {
            hasRun = false;
        }
    }
    if (judge != prev_judge)
    {
        is_changed_j = true;
    }
    prev_judge = judge;

}

int continuous_count = 1;
int wait = 60;
void continuous_beat() {
    Music music = return_music();
    Drag drag;
    double time = double(GetMusicTimePlayed(music));
    int beat_count = time / SecondTerm;
    
    int prev_beat = 0;
    int beat_count_now = 0;

    if (holding) {

        //if beat_count increased
        // continuous_count++;
        if (is_changed_j == true && judge == true) {
            continuous_count++;
        }

        if ((continuous_count > return_order_counter() + 1) || return_is_colide()) {
            drag.fail_drag();
            continuous_fail = true;
        }


    }
    else {
        if ((wait > 0) && continuous_fail) {
            continuous_fail = true;
            wait--;
        }
        else {
            continuous_fail = false;
            wait = 60;
        }

        continuous_count = 1;
    }


}

bool prev_splited_beat = false;
bool splited_beat = false;
long double splited_gap;

void beat_spliting() {
    Music music = return_music();
    is_changed = false;


    if (return_order_counter() >= 8) {
        splited_gap = long double(SecondTerm / 4);
    }
    else if (return_order_counter() >= 6) {
        splited_gap = long double(SecondTerm / 3);
    }
    else if (return_order_counter() >= 4) {
        splited_gap = long double(SecondTerm / 2);
        connect_4 = true;
    }

    else {
        splited_gap = SecondTerm;
    }



    long double time = long double(GetMusicTimePlayed(music));
    int beat_count_splited = time / splited_gap;

    if (time < long double(beat_count_splited * splited_gap + judge_offSet_stage2) &&
        time >  long double(beat_count_splited * splited_gap - judge_offSet_stage2)) {

        splited_beat = true;
    }
    else
    {
        splited_beat = false;
    }




    if (splited_beat != prev_splited_beat)
    {
        is_changed = true;
    }
    prev_splited_beat = splited_beat;
}


bool return_continuous_fail() {
    return continuous_fail;
}

bool return_connect_4() {
    return connect_4;
}