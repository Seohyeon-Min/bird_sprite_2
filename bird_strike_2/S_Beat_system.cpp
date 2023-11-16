#include <iostream>
#include <raylib.h>
#include "H_Crow.h"
#include "H_Main.h"

constexpr int BPM = 100;
constexpr double judge_offSet = 0.1;
constexpr int trigger_bar = 1;
static bool hasRun = false;
bool prev_judge = false;
bool judge = false;
int beat_count = 0;
double SecondTerm = 60.0 / BPM;
bool crow_delete_flag = false;
bool is_changed = false;

void IsOnBeat() {
    is_changed = false;

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

    if (judge != prev_judge)
    {
        is_changed = true;
    }

    std::cout << "is_changed : " << is_changed << std::endl;

    prev_judge = judge;
}