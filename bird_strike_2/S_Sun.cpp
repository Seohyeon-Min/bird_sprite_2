#include <raylib.h>
#include <iostream>
#include "H_Sun.h"
#include "H_Main.h"
#include "H_Beat_system.h"
#include "H_GameState.h"
#include "H_Audio.h"

constexpr int initial_sun_y = 325;
constexpr int sun_radius = 300;
constexpr int max_time = 100;

constexpr Color sun_color_1 = Color{ 247, 240, 234, 255 };
constexpr Color sun_color_2 = Color{ 246, 236, 218, 255 };
constexpr Color sun_color_3 = Color{ 253, 236, 196, 255 };
constexpr Color sun_color_4 = Color{ 242, 178, 106, 255 };


double sun_y = initial_sun_y;
double sun_drop_speed = (double)(((float)GetScreenHeight() + sun_radius - initial_sun_y) / max_time) / target_frame_rate; //프레임당 스피드


float fullFrame = (target_frame_rate * max_time);

//make the sun fall faster as time increase
float drop_v(float i) {
	float x = i * target_frame_rate;
	float y;
	y = (((float)GetScreenHeight() + sun_radius - initial_sun_y) / (fullFrame * fullFrame)) * (x * x) + initial_sun_y;
	return y;
}
float drop_b(float i) {
	float x = i * target_frame_rate;
	float y;
	y = (((float)GetScreenHeight() + sun_radius - initial_sun_y) / (fullFrame * fullFrame)) * (x * x) + initial_sun_y;
	return y;
}



void background(float sky_y) {
	DrawTexture;
	DrawTexturePro(
		stage1_background_texture,
		{ 0, 2368 - sky_y * 3.2f ,1300, 1000
		},
		{ 0,0,(float)GetScreenWidth() , (float)GetScreenHeight()
		},
		{ 0, 0 },
		0,
		WHITE
	);
}


void draw_sun(float sun_y) {
	DrawCircleGradient(GetScreenWidth() / 2, sun_y, (SecondTerms() - GetMusicTimePlayed(music)) * (800) + (800), { 0,0,0, 200 }, { 0,0,0,0 });
	//DrawCircle(window_width / 2, sun_y, sun_radius, sun_color_4);
	//DrawCircle(window_width / 2, sun_y, sun_radius - 13, sun_color_3);
	//DrawCircle(window_width / 2, sun_y, sun_radius - 24, sun_color_2);
	//DrawCircle(window_width / 2, sun_y, sun_radius - 50, sun_color_1);

	DrawTexturePro(
		sun_gradation_texture,
		{ 12,50,864, 486 },
		{ 0, sun_y - 350,(float)GetScreenWidth() , (float)GetScreenHeight() },
		{ 0,0 },
		0,
		WHITE
	);
	DrawTexturePro(
		sun_back_texture,
		{ 12,100,864, 486 },
		{ 0, sun_y - 300,(float)GetScreenWidth() , (float)GetScreenHeight() },
		{ 0,0 },
		0,
		WHITE
	);
	DrawTexturePro(
		sun_front_texture,
		{ 12,100,864, 486 },
		{ 0, sun_y - 300,(float)GetScreenWidth() , (float)GetScreenHeight() },
		{ 0,0 },
		0,
		WHITE
	);
}


void draw_sun_stage_2() {
	//DrawCircleGradient(window_width / 2, sun_y, (SecondTerms() - GetMusicTimePlayed(music)) * (800) + (800), { 0,0,0, 200 }, { 0,0,0,0 });
	//DrawCircle(window_width / 2, sun_y, sun_radius, sun_color_4);

	DrawTexturePro(
		sun_stage_2_texture,
		{ 12,100,864, 486 },
		{ 0, 50,(float)GetScreenWidth() , (float)GetScreenHeight() },
		{ 0,0 },
		0,
		WHITE
	);
}

void _sun_stage2() {
	draw_sun_stage_2();
	DrawTexturePro(
		grass_2_texture,
		{ 0, 0 ,(float)grass_2_image.width,(float)grass_2_image.height },
		{ 0,0,(float)GetScreenWidth() , (float)GetScreenHeight() },
		{ 0, 0 },
		0,
		WHITE
	);
}

bool _sun() {
	float y = drop_v(GetMusicTimePlayed(music));
	float b = drop_b(GetMusicTimePlayed(music));
	background(b);
	draw_sun(y);
	DrawTexturePro(
		grass_texture,
		{ 0, 0 ,(float)grass_image.width,(float)grass_image.height},
		{ 0,0,(float)GetScreenWidth() , (float)GetScreenHeight() },
		{ 0, 0 },
		0,
		WHITE
	);
	//std::cout << i - 325 << "    ,    " << GetTime() << std::endl;
	if (y >= GetScreenHeight() + sun_radius) {
		return true;
	}
	return false;
	//if (is_gameover) {
	//	double sun_y = initial_sun_y;
	//}
}