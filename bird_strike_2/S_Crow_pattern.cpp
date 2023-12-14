#include <iostream>
#include <cmath>
#include "raylib.h"
#include "H_Crow_pattern.h"
#include "H_Beat_system.h"
#include "H_Main.h"
#include "H_Main.h"
#include "H_Drag.h"
#include "H_Image.h"
#include "H_Audio.h"

float up_to_ten;
float SecondTerms_4th;

constexpr int frequency = 4;
//constexpr int range = 732;

int at_beat_count = 0;
int beat_count;

bool hold = { 0 };
bool aim = { 0 };
bool fire = { 0 };
bool at_toggle = { 0 };
bool draw_toggle = { 0 };
bool pos_toggle = { 0 };


void Crow_pattern::fire_crow() {
	double time = double(GetMusicTimePlayed(stage2_music));
	beat_count = time / SecondTerm;

	if (judge == 1 &&
		int(beat_count % frequency) == 0 &&
		hold == 0 &&
		GetMusicTimePlayed(stage2_music) > 5) {
		aim = 1;
		hold = 1;
		at_toggle = 1;
		draw_toggle = 1;
		pos_toggle = 1;
		LR = 0;//GetRandomValue(0, 2);
	}
}

void Crow_pattern::aim_line() {
	float hor_spawn_range = 0.7; //if value is 0.7, spawn range is 70% of each edge. 
	float ver_spawn_range = 0.3; 
	int ver_min = int(GetScreenHeight() * ((1.0f - ver_spawn_range) / 2));
	int ver_max = int(GetScreenHeight() * (ver_spawn_range + ((1 - ver_spawn_range) / 2)));
	int hor_min = int(GetScreenWidth() * ((1.0f - hor_spawn_range) / 2));
	int hor_max = int(GetScreenWidth() * (hor_spawn_range + ((1 - hor_spawn_range) / 2)));

	if (at_toggle == 1) {
		at_beat_count = beat_count;
		at_toggle = 0;
	}

	if (pos_toggle == 1) {
		if (LR == 1) { //vertical 
			start_pos = { float(GetRandomValue(hor_min, hor_max)), 0 };
		}
		else if(LR == 0) {//horizental right
			start_pos = { 0, float(GetRandomValue(ver_min, ver_max)) };
		}
		else if (LR == 2) {//horizental left
			start_pos = { float(GetScreenWidth()), float(GetRandomValue(ver_min, ver_max)) };
			end_pos = { float(GetScreenWidth()), 0 };
		}

		if (LR == 1) { //vertical 
			pre_end_pos = { float(GetRandomValue(hor_min, hor_max)), (float)GetScreenHeight() };
		}
		else if (LR == 0) {//horizental right
			pre_end_pos = { float(GetScreenWidth()), float(GetRandomValue(ver_min, ver_max)) };
		}
		else if (LR == 2) {//horizental left
			pre_end_pos = { 0, float(GetRandomValue(ver_min, ver_max)) };
		}

		if (LR == 1) { //vertical 
			angle = (pre_end_pos.x - start_pos.x) / (pre_end_pos.y - start_pos.y);
		}
		else if (LR == 0) {//horizental right
			angle = (pre_end_pos.y - start_pos.y) / (pre_end_pos.x - start_pos.x);
		}
		else if (LR == 2) {//horizental left
			angle = (pre_end_pos.y - start_pos.y) / (pre_end_pos.x - start_pos.x);
		}
		pos_toggle = 0;
	}

	float SecondTerms_4th = ((SecondTerm * int(beat_count / frequency) * frequency) + (SecondTerm * frequency));
	float up_to_4thTerm = (SecondTerm * frequency) - (SecondTerms_4th - GetMusicTimePlayed(stage2_music));
	float up_to_ten = ((static_cast<float>((1000)) / (SecondTerm * frequency)) * up_to_4thTerm);

	if (aim == 1 && at_beat_count <= beat_count) {
		distance = sqrt(pow((pre_end_pos.x - start_pos.x), 2) + pow((pre_end_pos.x - start_pos.x), 2));
		
		if (LR == 1) {//vertical
			end_pos.y = ((float)GetScreenHeight() / 1000) * up_to_ten;
			end_pos.x = (angle * end_pos.y) + start_pos.x;
		}
		else if(LR == 0) {//horizental right
			end_pos.x = ((float)GetScreenWidth() / 1000) * up_to_ten;
			end_pos.y = (angle * end_pos.x) + start_pos.y;
		}
		else if (LR == 2) {//horizental left
			end_pos.x = (float)GetScreenWidth() - (((float)GetScreenWidth() / 1000) * up_to_ten);
			end_pos.y = (angle * (end_pos.x - (float)GetScreenWidth())) + start_pos.y;
		}
		std::cout << end_pos.x << std::endl;
		DrawLineEx(start_pos, end_pos, 5, WHITE);


		if (LR == 1 && end_pos.y >= GetScreenHeight() - 10) { //vertical
			fire = 1;
			aim = 0;
		}
		else if (LR == 0 && end_pos.x >= GetScreenWidth() - 20) {//horizental right
			fire = 1;
			aim = 0;
		}
		else if (LR == 2 && end_pos.x <= 10) {//horizental left
			fire = 1;
			aim = 0;
		}
	}
}

void Crow_pattern::draw() {
	constexpr int speed = 30;
	constexpr int hitbox_size = 40;

	if (fire == 1) {
		if (draw_toggle == 1) {
			crow_pos = { start_pos.x, start_pos.y };
			draw_toggle = 0;
		}

		Rectangle image_source = { 0,0,(float)pattern_crow_image.width, (float)pattern_crow_image.height };
		Rectangle image_dest = { crow_pos.x, crow_pos.y, (float)pattern_crow_image.width * 2,(float)pattern_crow_image.height * 2 };
		float rotate = atan2(pre_end_pos.y - start_pos.y, pre_end_pos.x - start_pos.x) * 180 / PI;

		DrawTexturePro(pattern_crow_texture, image_source, image_dest, { 0, 0 }, rotate, WHITE);

		Lhitbox_pos = { crow_pos.x - hitbox_size, crow_pos.y };
		Lhitbox_back = { crow_pos.x + hitbox_size, crow_pos.y + hitbox_size };
		Rhitbox_pos = { crow_pos.x + hitbox_size, crow_pos.y };
		Rhitbox_back = { crow_pos.x - hitbox_size, crow_pos.y + hitbox_size };

		DrawLineV(Lhitbox_pos, Lhitbox_back, { 0, 0, 0, 255 });
		DrawLineV(Rhitbox_pos, Rhitbox_back, { 0, 0, 0, 255 });
		//DrawRectangle(Lhitbox_pos.x, Lhitbox_pos.y, hitbox_size * 2, hitbox_size, WHITE);

		if (LR == 1) {//vertical
			crow_pos.y += speed;
			crow_pos.x = (angle * crow_pos.y) + start_pos.x;
		}
		else if (LR == 0) {//horizental right
			crow_pos.x += speed;
			crow_pos.y = (angle * crow_pos.x) + start_pos.y;
		}
		else if (LR == 2) {//horizental left
			crow_pos.x -= speed;
			crow_pos.y = (angle * (crow_pos.x - (float)GetScreenWidth())) + start_pos.y;
		}

		if (LR == 1 && crow_pos.y >= GetScreenHeight() - 10) { //vertical
			crow_pos.x = 0;
			crow_pos.y = 0;
			hold = 0;
			fire = 0;
			at_toggle = 0;
			pos_toggle = 1;
		}
		else if (LR == 0 && crow_pos.x >= GetScreenWidth() - 10) {//horizental right
			crow_pos.x = 0;
			crow_pos.y = 0;
			hold = 0;
			fire = 0;
			at_toggle = 0;
			pos_toggle = 1;
		}
		else if (LR == 2 && crow_pos.x <= 10) {//horizental left
			crow_pos.x = 0;
			crow_pos.y = 0;
			hold = 0;
			fire = 0;
			at_toggle = 0;
			pos_toggle = 1;
		}
	}
}

bool Crow_pattern::line_colide() {
	for (int i = 0; i < clines.size(); i++) {
		ConLine crow_lines = clines[i];

		if (CheckCollisionLines(crow_lines.prepostion, crow_lines.postion, Lhitbox_pos, Lhitbox_back, nullptr) ||
			CheckCollisionLines(crow_lines.prepostion, crow_lines.postion, Rhitbox_pos, Rhitbox_back, nullptr)) {
			return true;
		}
		else {
			return false;
		}
	}
}
