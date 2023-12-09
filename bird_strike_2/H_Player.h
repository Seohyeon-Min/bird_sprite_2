#include <vector>
#include <raylib.h>

#ifndef PLAYER_H
#define PLAYER_H

struct Player {
private:
	Vector2 position;
	float reaching_time = 2;
	Vector2 speed = { -1,-1 };
	int radius = 30;
	float sprite_scale;
	

public:
	void _player();
	void draw(Vector2);
	void move();
	void get_destination();
	float floating_value = 5.0f;
};

#endif