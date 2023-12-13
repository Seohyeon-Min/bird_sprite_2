#include <raylib.h>
#include < iostream>
#include "H_Option.h"
#include "H_Image.h"
#include "H_Audio.h"
#include <vector>

int position = 0;

std::vector<int> positions;


void Control_bar::draw(int y) {

	std::cout << GetMousePosition().y << std::endl;

	DrawTextPro(
		font,
		"SFX",
		{ bar.x - MeasureTextEx(font,"SFX", 50, 2).x * 2, bar.y + y },
		{ 0, 0 },
		0,
		50,
		2,
		BLACK);


	DrawRectangle(bar.x - 25, bar.y - 25 + y, bar.width + 50, bar.height + 50, BLACK);
	DrawRectangle(bar.x, bar.y + y, bar.width, bar.height, GRAY);
	DrawRectangle(button.x + position, button.y + y, button.width, button.height, BLUE);
}


void Control_bar::move_button(int y) {
	if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(GetMousePosition(), { bar.x - 25, bar.y - 25 + y, bar.width + 50, bar.height + 50 })) {
		position = GetMouseX() - button.x - button.width / 2;
	}

	limit_button_movement();
}

void Control_bar::limit_button_movement() {
	if (button.x + position <= bar.x) {
		position = bar.x - button.x;
	}
	if (button.x + position + button.width >= bar.x + bar.width) {
		position = 252/*-(bar.width - button.width/2 - button.x)*/;
	}

}


void Control_bar::adjust() {
	button.x = (bar.width - button.width) / 10 * default_SFX;
	value_added = float(position / (bar.width - button.width));
	SetSoundVolume(crow_blow, default_SFX + float(position / (bar.width - button.width)));
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

	int y = 0;
	draw(y);
	move_button(y);
	draw(100);
	move_button(100);
	adjust();
	draw_toggle();

}


Color color = BLACK;

void draw_toggle() {

	DrawTextPro(
		font,
		"FULL SCREEN",
		{ 315, 480 },
		{ 0, 0 },
		0,
		50,
		2,
		BLACK);

	DrawRectangle(315 + MeasureTextEx(font, "FULL SCREEN", 50, 2).x + 50, 480, 50, 50, color);
	if (CheckCollisionPointRec(GetMousePosition(),
		{ 315 + MeasureTextEx(font, "FULL SCREEN", 50, 2).x + 50, 480, 50, 50 }) && IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
		ToggleFullscreen();
	}

	if (IsWindowFullscreen()) {
		color = { 150, 150, 150 ,255 };
	}
	else {
		color = { 193, 193, 193 ,255 };
	}
}