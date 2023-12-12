#include <iostream>
#include <raylib.h>
#include "H_Crow.h"
#include "H_Main.h"
#include "H_Drag.h"
#include "H_Score.h"
#include "H_Audio.h"

constexpr double judge_offSet = 0.1;
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

double SecondTerm = 60.0 / BPM;

float SecondTerms() {
    double time = double(GetMusicTimePlayed(stage1_music));
    int beat_count = time / SecondTerm;

    return float(beat_count * SecondTerm);
}

void change_BPM() {

    if (GetMusicTimePlayed(stage1_music) >= 33.62f) {
        BPM = 120;
    }
    if (GetMusicTimePlayed(stage1_music) >= 57.7f) {
        BPM = 140;
    }
    SecondTerm = 60.0 / BPM;
}

int* return_BPM() {
    return &BPM;
}

void IsOnBeat() {
    change_BPM();
    std::cout << "  BPM:" << SecondTerm << "  time:" << GetMusicTimePlayed(stage1_music) << std::endl; // 33.7, 57.7
    double time = double(GetMusicTimePlayed(stage1_music));
    is_changed_j = false;
    static bool hasRun = false;
    //judge
    if (time < double(SecondTerms() + judge_offSet) &&
        time >  double(SecondTerms() - judge_offSet)) {
        judge = true;
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

    if (judge != prev_judge)
    {
        is_changed_j = true;
    }
    prev_judge = judge;

}

int continuous_count = 1;

void continuous_beat() {
    //std::cout << " fail" << continuous_fail << " cnt:" << continuous_count << "  order:" << return_order_counter() << std::endl;

    Drag drag;
    double time = double(GetMusicTimePlayed(stage1_music));
    int beat_count = time / SecondTerm;

    int prev_beat = 0;
    int beat_count_now = 0;

    if (holding) {

        //if beat_count increased
        // continuous_count++;
        if (is_changed_j == true && judge == true) {
            continuous_count++;
        }

        if (continuous_count > return_order_counter() + 1) {
            drag.fail_drag(); //TODO: maintatin the func
            std::cout << continuous_fail << std::endl;
            continuous_fail = true;
        }

    }
    else {
        continuous_count = 1;
    }


}

bool prev_splited_beat = false;
bool splited_beat = false;
long double splited_gap;

void beat_spliting() {
    is_changed = false;


    if (return_order_counter() >= 8) {
        splited_gap = long double(SecondTerm / 4);
    }
    else if (return_order_counter() >= 6) {
        splited_gap = long double(SecondTerm / 3);
    }
    else if (return_order_counter() >= 4) {
        splited_gap = long double(SecondTerm / 2);
    }
    else {
        splited_gap = SecondTerm;
    }



    long double time = long double(GetMusicTimePlayed(stage1_music));
    int beat_count_splited = time / splited_gap;

    if (time < long double(beat_count_splited * splited_gap + judge_offSet) &&
        time >  long double(beat_count_splited * splited_gap - judge_offSet)) {

        splited_beat = true;
        DrawCircle(80, 80, 20, BLUE);
    }
    else
    {
        splited_beat = false;
    }




    if (splited_beat != prev_splited_beat)
    {
        is_changed = true;
    }
    //std::cout << double(beat_count_splited * SecondTerm - judge_offSet) << "    <    " << time << "   <     " << double(beat_count_splited * SecondTerm + judge_offSet) << std::endl;
    prev_splited_beat = splited_beat;
}


bool return_continuous_fail() {


    return continuous_fail;
}