#include <iostream>
#include <raylib.h>
#include "H_Crow.h"
#include "H_Main.h"

constexpr int start_BPM = 100;
constexpr double judge_offSet = 0.5;
constexpr int trigger_bar = 1;
static bool hasRun = false;
bool judge = false;
int beat_count = 1;

void IsOnBeat() {

    int BPM = start_BPM;
    double time = static_cast<double>(GetMusicTimePlayed(music));
    judge = false;
    //count the beat and cout the courrent number of beat and BPM
    double SecondTerm = static_cast<double>(60) / BPM; //compute the term between beats
    double SecondTerms = SecondTerm * beat_count;

    if (GetMusicTimePlayed(music) < SecondTerms + judge_offSet && 
        GetMusicTimePlayed(music) > SecondTerms - judge_offSet) {

        DrawCircle(40, 40, 30, RED);
        judge = true;
        beat_count++;
        

    }

    std::cout << SecondTerms - judge_offSet << " < " << GetMusicTimePlayed(music) << "  <" << SecondTerms + judge_offSet << std::endl;
  

    
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