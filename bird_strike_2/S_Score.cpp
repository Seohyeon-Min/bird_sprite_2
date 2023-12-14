#include <iostream>
#include <raylib.h>
#include <string>
#include "H_Beat_system.h"
#include "H_Score.h"
#include "H_Crow.h"
#include "H_Image.h"
#include "H_Main.h"
#include <tuple>

int score = 0;
int connected_crow_text_size = (float)(GetScreenWidth() / 15.36);
int judge_text_size = window_width / 32;
int alpha = 255;
int spacing = (float)(GetScreenWidth() / 384);
float alpha_2 = 178;
std::string judge_text = "";
constexpr int great_score = 30;
constexpr int good_score = 20;
constexpr int fail_score = -80;
constexpr int extra_score = 20;
Color alpha_white = Color{ 255,255,255,178 };
Color crow_size_text_color = BLACK;




int* return_score() {
	return &score;
}

void judge_text_draw() {
	if (alpha > 0) {
		alpha -= 5;
		alpha_2 -= 3.4;
		Color text_color = { 0,0,0,alpha };
		////////////////////////////////////////////////////////////////////////////////////////////////////
		DrawTextPro(
			font,
			judge_text.c_str(),
			{ (float)(GetScreenWidth() / 1.075) + 2, (float)(GetScreenHeight() / 2.16) },
			{ MeasureTextEx(font,judge_text.c_str(), judge_text_size, spacing).x / 2, 0 },
			0,
			judge_text_size,
			spacing,
			alpha_white);
		DrawTextPro(
			font,
			judge_text.c_str(),
			{ (float)(GetScreenWidth() / 1.075) - 2, (float)(GetScreenHeight() / 2.16) },
			{ MeasureTextEx(font,judge_text.c_str(), judge_text_size, spacing).x / 2, 0 },
			0,
			judge_text_size,
			spacing,
			alpha_white);
		DrawTextPro(
			font,
			judge_text.c_str(),
			{ (float)(GetScreenWidth() / 1.075), (float)(GetScreenHeight() / 2.16) + 2 },
			{ MeasureTextEx(font,judge_text.c_str(), judge_text_size, spacing).x / 2, 0 },
			0,
			judge_text_size,
			spacing,
			alpha_white);
		DrawTextPro(
			font,
			judge_text.c_str(),
			{ (float)(GetScreenWidth() / 1.075), (float)(GetScreenHeight() / 2.16) - 2 },
			{ MeasureTextEx(font,judge_text.c_str(), judge_text_size, spacing).x / 2, 0 },
			0,
			judge_text_size,
			spacing,
			alpha_white);

		DrawTextPro(
			font,
			judge_text.c_str(),
			{ (float)(GetScreenWidth() / 1.075), (float)(GetScreenHeight() / 2.16) },
			{ MeasureTextEx(font,judge_text.c_str(), judge_text_size, spacing).x / 2, 0 },
			0,
			judge_text_size,
			spacing,
			text_color);
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////
	}
}



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void crow_size_text_draw() {
	DrawTextPro(
		font,
		std::to_string(return_crow_size()).c_str(),
		{ (float)(GetScreenWidth() / 2) + 2, (float)(GetScreenHeight() / 10.8) },
		{ MeasureTextEx(font,std::to_string(return_crow_size()).c_str(), (float)(GetScreenWidth() / 20), 0).x / 2,0 },
		0,
		(float)(GetScreenWidth() / 20),
		0,
		alpha_white);
	DrawTextPro(
		font,
		std::to_string(return_crow_size()).c_str(),
		{ (float)(GetScreenWidth() / 2) - 2, (float)(GetScreenHeight() / 10.8) },
		{ MeasureTextEx(font,std::to_string(return_crow_size()).c_str(), (float)(GetScreenWidth() / 20), 0).x / 2,0 },
		0,
		(float)(GetScreenWidth() / 20),
		0,
		alpha_white);
	DrawTextPro(
		font,
		std::to_string(return_crow_size()).c_str(),
		{ (float)(GetScreenWidth() / 2), (float)(GetScreenHeight() / 10.8) + 2 },
		{ MeasureTextEx(font,std::to_string(return_crow_size()).c_str(), (float)(GetScreenWidth() / 20), 0).x / 2,0 },
		0,
		(float)(GetScreenWidth() / 20),
		0,
		alpha_white);
	DrawTextPro(
		font,
		std::to_string(return_crow_size()).c_str(),
		{ (float)(GetScreenWidth() / 2), (float)(GetScreenHeight() / 10.8) - 2 },
		{ MeasureTextEx(font,std::to_string(return_crow_size()).c_str(), (float)(GetScreenWidth() / 20), 0).x / 2,0 },
		0,
		(float)(GetScreenWidth() / 20),
		0,
		alpha_white);

	DrawTextPro(
		font,
		std::to_string(return_crow_size()).c_str(),
		{ (float)GetScreenWidth() / 2, (float)(GetScreenHeight() / 10.8) },
		{ MeasureTextEx(font,std::to_string(return_crow_size()).c_str(),(float)(GetScreenWidth() / 20), 0).x / 2,0 },
		0,
		(float)(GetScreenWidth() / 20),
		0,
		crow_size_text_color);

	if (return_crow_size() == max_crow) {
		crow_size_text_color = RED;
	}
	else {
		crow_size_text_color = BLACK;
	}
}



void show_score() {
	if (score < 0) {
		score = 0;
	}
	if (!is_gameover) {
		DrawTextPro(
			font,
			"score",
			{ (float)(GetScreenWidth() / 25.6) + 2 , (float)(GetScreenHeight() / 21.6) },
			{ 0,0 },
			0,
			(float)(GetScreenWidth() / 25.6),
			3,
			alpha_white);
		DrawTextPro(
			font,
			"score",
			{ (float)(GetScreenWidth() / 25.6) - 2 , (float)(GetScreenHeight() / 21.6) },
			{ 0,0 },
			0,
			(float)(GetScreenWidth() / 25.6),
			3,
			alpha_white);
		DrawTextPro(
			font,
			"score",
			{ (float)(GetScreenWidth() / 25.6) , (float)(GetScreenHeight() / 21.6) + 2 },
			{ 0,0 },
			0,
			(float)(GetScreenWidth() / 25.6),
			3,
			alpha_white);
		DrawTextPro(
			font,
			"score",
			{ (float)(GetScreenWidth() / 25.6) , (float)(GetScreenHeight() / 21.6) - 2 },
			{ 0,0 },
			0,
			(float)(GetScreenWidth() / 25.6),
			3,
			alpha_white);

		DrawTextPro(
			font,
			"score",
			{ (float)(GetScreenWidth() / 25.6) , (float)(GetScreenHeight() / 21.6) },
			{ 0,0 },
			0,
			(float)(GetScreenWidth() / 25.6),
			3,
			BLACK);


		DrawTextPro(
			font,
			std::to_string(score).c_str(),
			{ (float)(GetScreenWidth() / 25.6) + 2 ,(float)(GetScreenHeight() / 10.8) },
			{ 0,0 },
			0,
			(float)(GetScreenWidth() / 19.2),
			3,
			alpha_white);
		DrawTextPro(
			font,
			std::to_string(score).c_str(),
			{ (float)(GetScreenWidth() / 25.6) - 2,(float)(GetScreenHeight() / 10.8) },
			{ 0,0 },
			0,
			(float)(GetScreenWidth() / 19.2),
			3,
			alpha_white);
		DrawTextPro(
			font,
			std::to_string(score).c_str(),
			{ (float)(GetScreenWidth() / 25.6) ,(float)(GetScreenHeight() / 10.8) + 2 },
			{ 0,0 },
			0,
			(float)(GetScreenWidth() / 19.2),
			3,
			alpha_white);
		DrawTextPro(
			font,
			std::to_string(score).c_str(),
			{ (float)(GetScreenWidth() / 25.6) ,(float)(GetScreenHeight() / 10.8) - 2 },
			{ 0,0 },
			0,
			(float)(GetScreenWidth() / 19.2),
			3,
			alpha_white);


		DrawTextPro(
			font,
			std::to_string(score).c_str(),
			{ (float)(GetScreenWidth() / 25.6) ,(float)(GetScreenHeight() / 10.8) },
			{ 0,0 },
			0,
			(float)(GetScreenWidth() / 19.2),
			3,
			BLACK);




		//DrawTextPro(
		//	font,
		//	check_game_over().x.c_str(),
		//	{ (float)(GetScreenWidth() / 2) ,(float)(GetScreenHeight() / 2) },
		//	{ MeasureTextEx(font, check_game_over().x.c_str(), connected_crow_text_size, 0).x / 2,0 },
		//	0,
		//	(float)(GetScreenWidth() / 19.2),
		//	3,
		//	BLACK);
		//DrawText(check_game_over().c_str(), 300, 180, 100, BLACK);
		DrawTextPro(
			font,
			std::get<0>(return_game_over_txt()).c_str(),
			{ (float)(GetScreenWidth() / 2),(float)(GetScreenHeight() / 2) },
			{ MeasureTextEx(font, std::get<0>(return_game_over_txt()).c_str(), std::get<1>(return_game_over_txt()), 2).x / 2 ,MeasureTextEx(font, std::get<0>(return_game_over_txt()).c_str(), std::get<1>(return_game_over_txt()), 2).y / 2 },
			0,
			std::get<1>(return_game_over_txt()),
			2,
			{ 200,200,200,125 });


		if (return_order_counter() > 0) {
			DrawTextPro(
				font,
				std::to_string(return_order_counter()).c_str(),
				{ (float)(GetScreenWidth() / 1.075) + 2,(float)(GetScreenHeight() / 2.47) },
				{ MeasureTextEx(font, std::to_string(return_order_counter()).c_str(), connected_crow_text_size, 0).x / 2 ,
				MeasureTextEx(font, std::to_string(return_order_counter()).c_str(), connected_crow_text_size, 0).y / 2 },
				0,
				connected_crow_text_size,
				0,
				alpha_white);
			DrawTextPro(
				font,
				std::to_string(return_order_counter()).c_str(),
				{ (float)(GetScreenWidth() / 1.075) - 2,(float)(GetScreenHeight() / 2.47) },
				{ MeasureTextEx(font, std::to_string(return_order_counter()).c_str(), connected_crow_text_size, 0).x / 2 ,
				MeasureTextEx(font, std::to_string(return_order_counter()).c_str(), connected_crow_text_size, 0).y / 2 },
				0,
				connected_crow_text_size,
				0,
				alpha_white);
			DrawTextPro(
				font,
				std::to_string(return_order_counter()).c_str(),
				{ (float)(GetScreenWidth() / 1.075),(float)(GetScreenHeight() / 2.47) + 2 },
				{ MeasureTextEx(font, std::to_string(return_order_counter()).c_str(), connected_crow_text_size, 0).x / 2 ,
				MeasureTextEx(font, std::to_string(return_order_counter()).c_str(), connected_crow_text_size, 0).y / 2 },
				0,
				connected_crow_text_size,
				0,
				alpha_white);
			DrawTextPro(
				font,
				std::to_string(return_order_counter()).c_str(),
				{ (float)(GetScreenWidth() / 1.075),(float)(GetScreenHeight() / 2.47) - 2 },
				{ MeasureTextEx(font, std::to_string(return_order_counter()).c_str(), connected_crow_text_size, 0).x / 2 ,
				MeasureTextEx(font, std::to_string(return_order_counter()).c_str(), connected_crow_text_size, 0).y / 2 },
				0,
				connected_crow_text_size,
				0,
				alpha_white);

			DrawTextPro(
				font,
				std::to_string(return_order_counter()).c_str(),
				{ (float)(GetScreenWidth() / 1.075),(float)(GetScreenHeight() / 2.47) },
				{ MeasureTextEx(font, std::to_string(return_order_counter()).c_str(), connected_crow_text_size, 0).x / 2 ,
				MeasureTextEx(font, std::to_string(return_order_counter()).c_str(), connected_crow_text_size, 0).y / 2 },
				0,
				connected_crow_text_size,
				0,
				BLACK);
			if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT) && !holding) {
				connected_crow_text_size = (float)(GetScreenWidth() / 12); // WHY doesn't it work?
			}
		}
		else {
			connected_crow_text_size = (float)(GetScreenWidth() / 15.36);
		}
		judge_text_draw();
		crow_size_text_draw();
	}
	else {


		DrawTextPro(
			font,
			std::to_string(score).c_str(),
			{ (float)(GetScreenWidth() / 2) ,(float)(GetScreenHeight() / 2) },
			{ MeasureTextEx(font, std::to_string(score).c_str(), (float)(GetScreenWidth() / 25.6),(float)(GetScreenWidth() / 256)).x / 2
			, MeasureTextEx(font, std::to_string(score).c_str(), (float)(GetScreenWidth() / 25.6),(float)(GetScreenWidth() / 256)).y / 2 + MeasureTextEx(font, std::to_string(score).c_str(), (float)(GetScreenWidth() / 25.6),(float)(GetScreenWidth() / 256)).y / 2 },
			0,
			(float)(GetScreenWidth() / 19.2),
			3,
			BLACK);
	}

}


void get_score() {
	if (judge_great) {
		alpha = 255;
		alpha_2 = 178;
		score += great_score;
		judge_text = "great";
	}
	else {
		alpha = 255;
		alpha_2 = 178;
		score += good_score;
		judge_text = "good";
	}
}

void lose_score() {
	alpha = 255;
	alpha_2 = 178;
	score += fail_score;
	judge_text = "bad";
}

void bonus_score() {
	if (return_order_counter() >= 8) {
		score += extra_score * 3;
	}
	else if (return_order_counter() >= 6) {
		score += extra_score * 2;
	}
	else if (return_order_counter() >= 4) {
		score += extra_score;
	}
}