#include <raylib.h>
#include < iostream>
#include "H_Option.h"
#include "H_Image.h"
#include "H_Audio.h"

int position = 0;


void Control_bar::draw_bar(int y) {
	DrawTextPro(
		font,
		"SFX",
		{ bar.x - MeasureTextEx(font,"SFX", 50, 2).x * 2, bar.y },
		{ 0, 0 },
		0,
		50,
		2,
		BLACK);

	DrawRectangleRounded(
		{ padding.x,padding.y, GetScreenWidth() - padding.x * 2, GetScreenHeight() - padding.y * 2 },
		0.05,
		0,
		{ 0,0,0,50 }
	);
	DrawRectangle(bar.x, bar.y, bar.width, bar.height, GRAY);
}

void Control_bar::draw_button(int y) {
	DrawRectangle(button.x + position, button.y, button.width, button.height, BLUE);
}

void Control_bar::move_button() {
	if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
		;		position = GetMouseX() - button.x - button.width / 2;
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
	int y = 0;
	draw_bar(y);
	draw_button(y);
	move_button();
	adjust();
	draw_toggle();

}

void update_others() {

}

Color color = BLACK;

void draw_toggle() {
	DrawRectangle(100, 100, 50, 50, color);
	if (CheckCollisionPointRec(GetMousePosition(),
		{ 100,100,50,50 }) && IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
		ToggleFullscreen();
	}

	if (IsWindowFullscreen()) {
		color = RED;
	}
	else {
		color = BLACK;
	}
}