#include <iostream>
#include <vector>
#include "raylib.h"

#ifndef CROW_PATTERN__H
#define CROW_PATTERN__H

class Crow_pattern {
private:

	int LR;
	float angle;
	float distance;


	bool hold;
	bool aim;
	bool fire;
	bool at_toggle;

	Vector2 start_pos;
	Vector2 pre_end_pos;
	Vector2 end_pos;
	Vector2 crow_pos;
	Vector2 Lhitbox_pos;
	Vector2 Lhitbox_back;
	Vector2 Rhitbox_pos;
	Vector2 Rhitbox_back;

public:
	void aim_line();
	void fire_crow();
	void draw();
	void line_colide();

};
bool return_is_colide();
#endif 

//int Crow_pattern::angle_decider(int x, int y) {
//	int dislocate = 0;
//	float max_angle = 0;
//	float min_angle = 0;
//
//	if (LR == 1) { //vertical 
//		dislocate = x - (GetScreenWidth() / 2);
//	}
//	else if (LR == 0) {//horizental right
//		dislocate = y - (GetScreenHeight() / 2);
//	}
//	else if (LR == 2) {//horizental left
//		dislocate = y - (GetScreenHeight() / 2);
//	}
//
//	int abs_dislocate = std::abs(dislocate);
//
//	int max_max_angle = 200;
//	int max_min_angle = 150;
//
//	int min_max_angle = 50;
//	int min_min_angle = 33;
//
//	if (LR == 1) { //vertical 
//		max_angle = (((max_max_angle - max_min_angle) / (GetScreenWidth() / 2)) * abs_dislocate + max_min_angle);
//	}
//	else if (LR == 0) {//horizental right
//		max_angle = (((max_max_angle - max_min_angle) / (GetScreenHeight() / 2)) * abs_dislocate + max_min_angle);
//	}
//	else if (LR == 2) {//horizental left
//		max_angle = (((max_max_angle - max_min_angle) / (GetScreenHeight() / 2)) * abs_dislocate + max_min_angle);
//	}
//
//	if (LR == 1) { //vertical 
//		min_angle = (((min_max_angle - min_min_angle) / (GetScreenWidth() / 2)) * abs_dislocate + min_min_angle);
//	}
//	else if (LR == 0) {//horizental right
//		min_angle = (((min_max_angle - min_min_angle) / (GetScreenHeight() / 2)) * abs_dislocate + min_min_angle);
//	}
//	else if (LR == 2) {//horizental left
//		min_angle = (((min_max_angle - min_min_angle) / (GetScreenHeight() / 2)) * abs_dislocate + min_min_angle);
//	}
//
//	 return GetRandomValue(min_angle, max_angle);
//}
