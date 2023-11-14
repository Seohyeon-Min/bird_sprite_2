#include <iostream>
#include <raylib.h>
#include "beat_system.h"
#include "crow.h"

constexpr int start_BPM = 100;
constexpr int end_BPM = 200;
constexpr double offSet = 0.008;
constexpr double judge_offSet = 0.07;
constexpr int trigger_bar = 1;

bool judge = false;

void IsOnBeat() {
    int BPM = start_BPM;
    int time = static_cast<int>(GetTime());
    judge = false;
    //count the beat and cout the courrent number of beat and BPM
    for (int i = 0; i < 200; i++) {
        double SecondTerm = static_cast<double>(60) / BPM; //compute the term between beats

        double SecondTerms = SecondTerm * i;
        int i_use = i;
        if (GetTime() < SecondTerms + judge_offSet && GetTime() > SecondTerms - judge_offSet) {

            DrawCircle(40, 40, 30, RED);
            judge = true;
            
        }


   
       
        // float GetMusicTimePlayed(Music music);   (for later use)

        //every Nth beat increase cout the "Now we are on BEAT!!!"
        int n = 5;

        if (i_use % n == 0 &&
            GetTime() < SecondTerms + offSet && GetTime() > SecondTerms - offSet) {
            std::cout << "Now we are on BEAT!!!" << std::endl;
            for (int c = 0; c < 3; c++) {
                Crow crow{};
                crow.add_crow();
            }
        }
    }
}