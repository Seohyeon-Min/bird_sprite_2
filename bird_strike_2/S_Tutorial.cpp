#include <raylib.h>
#include "H_Sun.h"
#include "H_Image.h"
#include "H_Crow.h"
#include "H_Mouse.h"
#include "H_Particle.h"
#include "H_Beat_system.h"
#include "H_Drag.h"
#include "H_Audio.h"
#include "H_Beat_system.h"
#include "H_GameState.h"
#include "H_Score.h"

int textbox_start = 450;
int recoffset = 20;
int outline_offset = 15;
int textsize = 50;
int player_num = 0;
int T_count = 60;
int tutorial_count = 0;
bool crow_flag = true;



Vector2 text_position = { 50, 500 };
Vector2 text_position2 = { 50, 560 };


void textbox(const char* text,const char* text2, int player_num, int effect_num) {
	DrawRectangle(0 + outline_offset, textbox_start + outline_offset, GetScreenWidth() - (outline_offset*2), GetScreenHeight() + (outline_offset * 2), WHITE);
	DrawRectangle(0+recoffset, textbox_start +recoffset,GetScreenWidth() - (recoffset*2),GetScreenHeight()+ (recoffset * 2),BLACK);
	DrawTextPro(font, text, text_position, { 0,0 }, 0, textsize, 3, WHITE);
	DrawTextPro(font, text2, text_position2, { 0,0 }, 0, textsize, 3, WHITE);
	if (T_count > 30) {
		DrawTriangle({ 50,690 }, { 65,700 }, { 80,690 }, WHITE);
	}
	else if (T_count == 0) {
		T_count = 60;
	}

	switch (player_num) {
	case 1:
		DrawTexturePro(tutorial_1_texture,
			{0,0,(float)tutorial_1_image.width,(float)tutorial_1_image.height},
			{0,0,(float)GetScreenWidth()+50,(float)GetScreenHeight()+50},
			{0,0},
			0,
			WHITE);
		break;
	case 2:
		DrawTexturePro(tutorial_2_texture,
			{ 0,0,(float)tutorial_1_image.width,(float)tutorial_1_image.height },
			{ 0,0,(float)GetScreenWidth() + 50,(float)GetScreenHeight() + 50 },
			{ 0,0 },
			0,
			WHITE);
		break;
	case 3:
		DrawTexturePro(tutorial_3_texture,
			{ 0,0,(float)tutorial_1_image.width,(float)tutorial_1_image.height },
			{ 0,0,(float)GetScreenWidth() + 50,(float)GetScreenHeight() + 50 },
			{ 0,0 },
			0,
			WHITE);
		break;
	case 4:
		DrawTexturePro(tutorial_4_texture,
			{ 0,0,(float)tutorial_1_image.width,(float)tutorial_1_image.height },
			{ 0,0,(float)GetScreenWidth() + 50,(float)GetScreenHeight() + 50 },
			{ 0,0 },
			0,
			WHITE);
		break;
	}

	switch (effect_num) {
	case 1:
		DrawTexturePro(tutorial_5_texture,
			{ 0,0,(float)tutorial_1_image.width,(float)tutorial_1_image.height },
			{ 0,0,(float)GetScreenWidth() + 50,(float)GetScreenHeight() + 50 },
			{ 0,0 },
			0,
			WHITE);
		break;
	case 2:
		DrawTexturePro(tutorial_6_texture,
			{ 0,0,(float)tutorial_1_image.width,(float)tutorial_1_image.height },
			{ 0,0,(float)GetScreenWidth() + 50,(float)GetScreenHeight() + 50 },
			{ 0,0 },
			0,
			WHITE);
		break;
	}
}

void tutorial() {
	Crow crow;
	Drag drag;

	ClearBackground({251,241,232,255});
	Particle::update_particle();
	Effect::make_effect();
	Effect::update_effect();

	T_count--;

	if (tutorial_count >= 7) {
		PlayMusicStream(tutorial_music);
		PlayMusicStream(stage1_music);
		SetMusicVolume(stage1_music, 0.0f);
		IsOnBeat(false);
		beat_spliting();
		continuous_beat();
		crow._crow();
		drag.Fx();
	}
	switch (tutorial_count) {
	case 0:
		textbox("Hello!","Welcom to tutorial!", 1, 2);
		if (IsKeyPressed(KEY_SPACE) ) tutorial_count += 1;
		break;
	case 1:
		textbox("Do you want to","play with me?", 1, 0);
		if (IsKeyPressed(KEY_SPACE)) tutorial_count += 1;
		break;
	case 2:
		textbox("Good!", " ", 4, 0);
		if (IsKeyPressed(KEY_SPACE) ) tutorial_count += 1;
		break;
	case 3:
		textbox("If you want to play with me ", "you need to know some rules ", 1, 0);
		if (IsKeyPressed(KEY_SPACE) ) tutorial_count += 1;
		break;
	case 4:
		if (crow_flag ==true ) {
			Crow* p_crow = new Crow;
			p_crow->add_crow();
			crow_flag = false;
		}
		crow._crow();
		textbox("Can you see a crow", "on the screen? ", 1, 0);
		if (IsKeyPressed(KEY_SPACE) ) tutorial_count += 1;
		break;
	case 5:
		crow._crow();
		textbox("If you want me to attack", "crow ", 3, 0);
		if (IsKeyPressed(KEY_SPACE)) tutorial_count += 1;
		break;
	case 6:
		crow._crow();
		textbox("You have to click the crow ", "on the beat! ", 1, 0);
		if (IsKeyPressed(KEY_SPACE)) tutorial_count += 1;
		break;
	case 7:
		textbox("Can you hear a beat? ", " ", 1, 0);
		if (IsKeyPressed(KEY_SPACE)) tutorial_count += 1;
		break;
	case 8:
		textbox("Let click that crow and attack!", " ", 4, 0);
		if (return_continuous_fail()) {
			tutorial_count += 1; 
		}
		if (return_crow_size() == 0) {
			tutorial_count += 2;
		}
		break;
	case 9:
		textbox("NO!", "Let try again... ", 2, 1);
		if (return_crow_size() == 0) {
			tutorial_count += 1;
		}
		break;
	case 10:
		textbox("Perfect!", " ", 4, 2);
		if (IsKeyPressed(KEY_SPACE)) tutorial_count += 1;
		break;
	case 11:
		crow_flag = true;
		textbox("As you connect more and more crow", " ", 1, 0);
		if (IsKeyPressed(KEY_SPACE)) tutorial_count += 1;
		break;
	case 12:
		if (!return_connect_4()) {
			for (int i = return_crow_size(); i < 4; i++) {
				Crow* p_crow = new Crow;
				p_crow->add_crow();
			}
		}
		textbox("Let's connect four crows! ", "You can do it! ", 1, 0);
		if (return_connect_4()&&return_crow_size()<4) tutorial_count += 2;
		break;
	case 14:
		crow_flag = true;
		textbox("Yeah! You did it!", " ", 4, 2);
		if (IsKeyPressed(KEY_SPACE)) tutorial_count += 1;
		break;
	case 15:
		textbox("You clear tutorial!", "Nice job! ", 1, 2);
		if (IsKeyPressed(KEY_SPACE)) tutorial_count += 1;
		break;
	case 16:
		textbox("You can do better on game!", "Let go~ ", 1, 2);
		if (IsKeyPressed(KEY_SPACE)) {
			tutorial_count = 0;
			StopMusicStream(tutorial_music);
			StopMusicStream(stage1_music);
			SetMusicVolume(stage1_music, 1.0f);
			crows.clear();
			*return_score() = 0;
			gamestate = GameState::LobbyScreen;
		}
		break;
	}
	mouse_control();
}