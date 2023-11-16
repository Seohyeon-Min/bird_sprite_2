#include <iostream>
#include <raylib.h>
#include "H_Crow.h"
#include "H_Main.h"

constexpr int BPM = 100;
constexpr double judge_offSet = 0.1;
constexpr int trigger_bar = 1;
static bool hasRun = false;

int beat_count = 0;
double SecondTerm = 60.0 / BPM;
bool crow_delete_flag = false;
bool prev_judge = false;
bool judge = false;

bool is_changed = false;

void IsOnBeat() {
    //is_changed = false;

    //compute the term between beats
    double time = double(GetMusicTimePlayed(music));
    int beat_count = time / SecondTerm;

    //judge
    if (time < double(beat_count * SecondTerm + judge_offSet) &&
        time >  double(beat_count * SecondTerm - judge_offSet)) {

        DrawCircle(40, 40, 30, RED);
        judge = true;
    }
    else
    {
        judge = false;
    }

    //std::cout << beat_count << "   :   " << double(beat_count * SecondTerm - judge_offSet) << "  <  " << time << "  <  " << double(beat_count * SecondTerm + judge_offSet) << std::endl;


    if (beat_count % 5 == 0) {
        if (!hasRun) {
            for (int c = 0; c < 3; c++) {
                Crow crow{};
                crow.add_crow();
            }
            hasRun = true;
        }
    }
    else {
        hasRun = false;
    }

    //if (judge != prev_judge)
    //{
    //    is_changed = true;
    //}

    //prev_judge = judge;
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
        std::cout << "here!" << std::endl;
    }
    else if (return_order_counter() >= 4) {
        splited_gap = long double(SecondTerm / 2);
    }
    else {
        splited_gap = SecondTerm;
    }



    long double time = long double(GetMusicTimePlayed(music));
    int beat_count_splited = time / splited_gap;

    if (time < long double(beat_count_splited * splited_gap + judge_offSet) &&
        time >  long double(beat_count_splited * splited_gap - judge_offSet)) {

        DrawCircle(100, 40, 30, BLUE);
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
    //std::cout << double(beat_count_splited * SecondTerm - judge_offSet) << "    <    " << time << "   <     " << double(beat_count_splited * SecondTerm + judge_offSet) << std::endl;
    prev_splited_beat = splited_beat;
}