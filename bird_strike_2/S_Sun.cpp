#include <raylib.h>
#include <iostream>
#include "H_Sun.h"
#include "H_Main.h"
#include "H_Beat_system.h"


constexpr int initial_sun_y = 325;
constexpr int sun_radius = 300;
constexpr int max_time = 60;

constexpr Color sun_color_1 = Color{ 247, 240, 234, 255 };
constexpr Color sun_color_2 = Color{ 246, 236, 218, 255 };
constexpr Color sun_color_3 = Color{ 253, 236, 196, 255 };
constexpr Color sun_color_4 = Color{ 242, 178, 106, 255 };


double sun_y = initial_sun_y;
double sun_drop_speed = (double)((window_height + sun_radius - initial_sun_y) / max_time) / target_frame_rate; //프레임당 스피드


float fullFrame = (target_frame_rate * max_time);

//make the sun fall faster as time increase
float drop_v(float i) {
	float x = i * target_frame_rate;
	float y;
	y = ((window_height + sun_radius - initial_sun_y) / (fullFrame * fullFrame)) * (x * x) + initial_sun_y;
	return y;
}


void draw_sun(float sun_y) {
	DrawCircleGradient(window_width / 2, sun_y, (SecondTerms() - GetMusicTimePlayed(music)) * (sun_radius * 2) + (sun_radius * 2), {0,0,0, 200}, {0,0,0,0});
	DrawCircle(window_width / 2, sun_y, sun_radius, sun_color_4);
	DrawCircle(window_width / 2, sun_y, sun_radius - 13, sun_color_3);
	DrawCircle(window_width / 2, sun_y, sun_radius - 24, sun_color_2);
	DrawCircle(window_width / 2, sun_y, sun_radius - 50, sun_color_1);
}

bool _sun() {
	float y = drop_v(GetMusicTimePlayed(music));
	draw_sun(y);
	//std::cout << i - 325 << "    ,    " << GetTime() << std::endl;
	if (y >= GetScreenHeight() + sun_radius) {
		return true;
	}
	return false;
}

