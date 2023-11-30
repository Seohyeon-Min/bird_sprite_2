#include <iostream>
#include <raylib.h>
#include "H_Beat_system.h"
#include "H_Score.h"

int score = 0;
constexpr int great_score = 30;
constexpr int good_score = 20;
constexpr int fail_score = -50;
constexpr int extra_score = 10;



void get_score() {
	if (judge_great) {
		std::cout << "great!" << std::endl;
		score += great_score;
	}
	else {
		std::cout << "good!" << std::endl;
		score += good_score;
	}

	std::cout << score << std::endl;
}

void lose_score() {
	std::cout << "fail!" << std::endl;
	score += fail_score;
	std::cout << score << std::endl;
}

void bonus_score() {
	//TODO: try to run it only once.
	std::cout << "bonus!" << std::endl;
	score += extra_score;
}