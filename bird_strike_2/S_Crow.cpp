#include <raylib.h>
#include <iostream>
#include <vector>
#include "H_Crow.h"
#include "H_Drag.h"
#include "H_Image.h"
#include "H_Beat_system.h"
#include "H_Main.h"
#include "H_Score.h"

std::vector<Crow> crows{};
std::vector<Vector2> marked_crow_positions;

double animation_timer = 0;
const double animation_speed = 15;
float sprite_scale{ 1.5 };
int texture_sizes{ 50 };
int erase_number = 1;
int Switch = 1;
int order_counter = 1;
bool holding = false;
bool erase_flag = false;
int wait_for = target_frame_rate * 3;

Vector2 Crow::get_position() {
	return position;
}

bool Crow::intersection(float x, float y) {
	if (x > position.x - radius && x < position.x + radius
		&&
		y > position.y - radius && y < position.y + radius) {
		return true;
	}
	else {
		return false;
	}
}

void Crow::draw(bool hover) {
	if (hover)
	{
		DrawCircle(position.x, position.y, radius, Color{ 0,0,0 , 80 });
	}
	if (marked) {


		if (!((int)animation_timer % 15)) {
			animation_timer = 15;

		}
		DrawTexturePro(
			crow_click_outline_texture,
			{
				float(((float)texture_sizes * (int)animation_timer)),
				0,
				float((direction * 2 - 1) * texture_sizes),
				float(texture_sizes)
			},
			{
				(float)(position.x - texture_sizes * sprite_scale / 2),
				(float)(position.y - texture_sizes * sprite_scale / 2),
				float(texture_sizes * sprite_scale),
				float(texture_sizes * sprite_scale)
			},
			{ 0, 0 },
			0.0f,
			WHITE
		);

	}
	else {
		//DrawCircle(position.x, position.y, radius, BLACK);
		DrawTexturePro(
			Sprite_crow_outline_texture,
			{
				float(((float)texture_sizes * (int)animation_timer)),
				0,
				float((direction * 2 - 1) * texture_sizes),
				float(texture_sizes)
			},
			{
				(float)(position.x - texture_sizes * sprite_scale / 2),
				(float)(position.y - texture_sizes * sprite_scale / 2),
				float(texture_sizes * sprite_scale),
				float(texture_sizes * sprite_scale)
			},
			{ 0, 0 },
			0.0f,
			WHITE
		);
	}
}

void Crow::first_move() {

	position.x += speed.x;
	speed.y += acc.y;
	position.y += speed.y;
	spawn_count--;
}

void Crow::animation_move() {
	animation_timer += GetFrameTime() * animation_speed;
}

void Crow::move() {

	speed.y += acc.y;

	position.y += speed.y;
	position.x += speed.x;


	if (GetRandomValue(0, 200) == 0) {
		speed.x *= -1;
	}
	if (GetRandomValue(0, 150) == 0) {
		acc.y *= -1;
	}
	if (GetRandomValue(0, 150) == 0) {
		speed.y *= -1;
	}


	if (position.x > GetRenderWidth() - radius) {
		position.x = GetRenderWidth() - radius;
		speed.x *= -1;
		if (GetRandomValue(0, 1) == 0)
			speed.y *= -1;
	}
	else if (position.x < radius) {
		position.x = radius;
		speed.x *= -1;
		if (GetRandomValue(0, 1) == 0)
			speed.y *= -1;
	}
	if (position.y > GetScreenHeight() - GetScreenHeight() / 3) {
		position.y = GetScreenHeight() - GetScreenHeight() / 3;
		speed.y *= -1;
		if (GetRandomValue(0, 1) == 0)
			speed.x *= -1;
	}
	else if (position.y < radius) {
		position.y = radius;
		speed.y *= -1;
		if (GetRandomValue(0, 1) == 0)
			speed.x *= -1;
	}
}

void Crow::checkdirection() {
	if (speed.x > 0) {
		direction = true;
	}
	else if (speed.x == 0 && acc.x == 0) {
		direction = direction;
	}
	else {
		direction = false;
	}
}

bool isMouseInputAllowed = true;

bool Crow::mouse_click() { //checking whether the mouse is down or not
	if (isMouseInputAllowed) {
		if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
			return true;
		}
		if (IsMouseButtonUp(MOUSE_BUTTON_LEFT)) {
			return false;
		}
	}
}


//decide the spawn point (left or right side of window)
Crow::Crow() {
	position.x = GetRandomValue(0, 1) == 0 ? -radius * 2, speed.x *= -1 : GetScreenWidth() + radius * 2, speed.x *= -1;
	position.y = GetRandomValue(radius * 2, GetScreenHeight() - GetScreenHeight() / 3);
	animation_timer = GetRandomValue(0, 15);

	if (position.y > GetScreenHeight() / 3) {
		acc.y *= -1;
		speed.y = -0.5;
	}
}

Crow::~Crow() {

}

void Crow::add_crow() {
	if (crows.size() < max_crow) {
		crows.push_back(*this);
	}
}
bool is_gameover;

void Crow::check_game_over() {
	if (crows.size() == max_crow && !holding && !erase_flag) {
		wait_for--;
		is_gameover = true;
		crows.clear();
	}
}





void Crow::_crow() {
	static bool hasRun = false;
	std::cout << marked_crow_positions.size() << std::endl;
	mouse_click();
	Drag drag;
	Crow* hover = nullptr;
	for (Crow& crow : crows) { //checking whether the mouse is on the crow or not
		if (hover == nullptr && crow.intersection(GetMouseX(), GetMouseY())) {
			hover = &crow;
			if (mouse_click() && judge && !crow.marked && !continuous_fail) { //if mouse is down and on the crow... 
				if (!hasRun) {
					get_score();
					holding = true;
					crow.marked = true;
					crow.speed = { 0,0 };
					crow.acc = { 0,0 };
					crow.order = order_counter;
					marked_crow_positions.push_back(crow.get_position());
					if (Switch == 1)
						drag.check_Fdrag(crow.get_position());
					else if (Switch != 1)
						drag.check_Sdrag(crow.get_position());

					order_counter++;
					hasRun = true;
				}
			}
			if (!judge) {
				hasRun = false;
			}
		}
		if (continuous_fail) {
			lose_score();
			holding = false;
			marked_crow_positions.clear();
			for (Crow& crow : crows) {
				if (crow.marked) {
					crow.speed = { float(GetRandomValue(0,1) == 0 ? 2 : 1), 1 };
					crow.acc = { 0.05, 0.008 };
					crow.order = 0;
					crow.marked = false;
				}
			}
		}
		continuous_fail = false;
	}
	if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT) && holding) {
		erase_flag = true;
		isMouseInputAllowed = false;
		holding = false;
		marked_crow_positions.clear();
	}

	if (erase_flag == true && is_changed == true && splited_beat == true)
	{
		delete_crow();
		erase_number++;
		if (order_counter == erase_number)
		{

			order_counter = 1;
			erase_number = 1;
			erase_flag = false;
			isMouseInputAllowed = true;

		}
	}

	for (int i = crows.size() - 1; i >= 0; i--) {
		if (crows[i].spawn_count == 0) {
			crows[i].move();

		}
		else {
			crows[i].first_move();
		}
		crows[i].animation_move();
		crows[i].checkdirection();
		crows[i].draw(hover == &crows[i]);
	}
	check_game_over();

}

void Crow::delete_crow() {
	for (int i = crows.size() - 1; i >= 0; i--) { //delete the crow
		if (crows[i].marked == true && crows[i].order == erase_number) { //i need a counter to check the order of crow by it clicked
			
			UpdateMusicStream(crow_blow);
			crows.erase(crows.begin() + i);
			break;
		}
	}

}

int return_order_counter() {
	int cnt = order_counter - 1;
	return cnt;
}