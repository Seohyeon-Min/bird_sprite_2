#include <iostream>
#include <raylib.h>
#include "H_Crow.h"
#include "H_Main.h"

constexpr int BPM = 100;
constexpr double judge_offSet = 0.1;
constexpr int trigger_bar = 1;
static bool hasRun = false;
bool judge = false;
int beat_count = 0;

void IsOnBeat() {

    double SecondTerm = 60.0 / BPM; //compute the term between beats
    double time = double(GetMusicTimePlayed(music));
    int beat_count = time / SecondTerm;
    
    judge = false;
    //judge
    if (time < double(beat_count * SecondTerm + judge_offSet)  &&
        time >  double(beat_count * SecondTerm - judge_offSet)) {

        DrawCircle(40, 40, 30, RED);
        judge = true;
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


}