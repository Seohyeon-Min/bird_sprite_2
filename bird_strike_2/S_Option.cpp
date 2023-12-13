#include <raylib.h>
#include < iostream>
#include "H_Option.h"
#include "H_Image.h"
#include "H_Audio.h"
#include <vector>


std::vector<Control_bar*> bars;

Control_bar::Control_bar(){
}

Control_bar::Control_bar(const char* name, int y):name(name),y(y) {
	position = 0;
}

void make_bars() {
	bars.push_back(new Control_bar{ "SFX   ",0 });
	bars.push_back(new Control_bar{ "SOUND", 100 });
}

void Control_bar::draw() {

	DrawTextPro(
		font,
		name,
		{ bar.x - MeasureTextEx(font,name, 60, 2).x , bar.y + y },
		{ 0, 0 },
		0,
		50,
		2,
		BLACK);


	//DrawRectangle(bar.x-25, bar.y-25 + y, bar.width+50, bar.height+50, BLACK);
	DrawRectangle(bar.x, bar.y + y, bar.width, bar.height, { 251, 241, 232 ,105});
	DrawRectangle(button.x + position, button.y + y, button.width, button.height, BLACK);
}


void Control_bar::move_button() {
	if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)&&CheckCollisionPointRec(GetMousePosition(),{ bar.x - 25, bar.y - 25 + y, bar.width + 50, bar.height + 50})) {
		
		position = GetMouseX() - button.x - button.width / 2;
	}

	limit_button_movement();
}

void Control_bar::limit_button_movement() {
	if (button.x + position <= bar.x) {
		position = bar.x - button.x;
	}
	if (button.x + position + button.width >= bar.x + bar.width) {
		position = 72/*-(bar.width - button.width/2 - button.x)*/;
	}

}


float Control_bar::adjust() {
	//button.x = (bar.width - button.width) / 10 * default_SFX;
	return float(position / (bar.width - button.width));
}

void Control_bar::update_all() {
	

	DrawRectangleRounded(
		{ padding.x,padding.y, GetScreenWidth() - padding.x * 2, GetScreenHeight() - padding.y * 2 },
		0.05,
		0,
		{ 0,0,0,100 }
	);

	DrawTextPro(
		font,
		"OPTION",
		{ (float)GetScreenWidth() / 2, 74 },
		{ MeasureTextEx(font,"OPTION", 50, 2).x / 2, 0 },
		0,
		50,
		2,
		BLACK);

	for (int i = 0; i < bars.size(); i++) {
		bars[i]->draw();
		bars[i]->move_button();
		bars[i]->adjust();
	}

	SetSoundVolume(crow_blow, default_SFX + (bars[0]->adjust()));
	SetMusicVolume(stage1_music, default_music + (bars[1]->adjust()));
	


	draw_toggle();

}



void draw_toggle() {

	DrawTextPro(
		font,
		"FULL SCREEN",
		{ 315, 440 },
		{ 0, 0 },
		0,
		50,
		2,
		BLACK);

	DrawRectangle(315+ MeasureTextEx(font, "FULL SCREEN", 50, 2).x +50, 440, 50, 50, { 251, 241, 232 ,105 });
	if (CheckCollisionPointRec(GetMousePosition(),{ 315 + MeasureTextEx(font, "FULL SCREEN", 50, 2).x + 50, 440, 50, 50 })) {

		DrawTexturePro(check2_texture,
			{ 0,0,float(check2_image.height), float(check2_image.width) },
			{ 315 + MeasureTextEx(font, "FULL SCREEN", 50, 2).x + 50, 440, 50, 50 },
			{ 0,0 },
			0,
			WHITE);
		if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
			ToggleFullscreen();
		}

	}
	else if (IsWindowFullscreen()) {
		DrawTexturePro(check_texture,
			{ 0,0,float(check_image.height), float(check_image.width) },
			{ 315 + MeasureTextEx(font, "FULL SCREEN", 50, 2).x + 50, 440, 50, 50 },
			{ 0,0 },
			0,
			WHITE);
	}
}