#include <iostream>
#include <raylib.h>
#include <string>
#include "H_Beat_system.h"
#include "H_Score.h"
#include "H_Crow.h"

int score = 0;
int connected_crow_text_size = 30;
int judge_text_size = 20;
int alpha = 255;
std::string judge_text = "";
constexpr int great_score = 30;
constexpr int good_score = 20;
constexpr int fail_score = -80;
constexpr int extra_score = 20;

void judge_text_draw() {
	alpha -= 5;
	Color text_color = { 0,0,0,alpha };
	DrawText(judge_text.c_str(), 700, 180, judge_text_size, text_color);
}

void show_score() {
	if (score < 0) {
		score = 0;
	}

	DrawText(std::to_string(score).c_str(), 50, 50, 50, BLACK);
	if (return_order_counter() > 0) {
		DrawText(std::to_string(return_order_counter()).c_str(), 720, 150, connected_crow_text_size, BLACK);
		if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT) && holding ) {
			connected_crow_text_size = 40;
		}
	}
	else {
		connected_crow_text_size = 30;
	}
	judge_text_draw();
}


void get_score() {
	if (judge_great) {
		score += great_score;
		judge_text = "great";
		judge_text_size = 25;
	}
	else {
		score += good_score;
		judge_text = "good";
		judge_text_size = 20;
	}
}

void lose_score() {
	score += fail_score;
	judge_text = "bad";
	judge_text_size = 20;
}

void bonus_score() {
	if (return_order_counter() >= 8) {
		std::cout << "8!" << std::endl;
		score += extra_score*3;
	}
	else if (return_order_counter() >= 6) {
		std::cout << "6!" << std::endl;
		score += extra_score*2;
	}
	else if (return_order_counter() >= 4) {
		std::cout << "4!" << std::endl;
		score += extra_score;
	}
}