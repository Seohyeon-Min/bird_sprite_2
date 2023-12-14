/* GAM100

Hyeonseong Bae

All content © 2023 DigiPen (USA) Corporation, all rights reserved. */

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
