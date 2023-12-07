#include <vector>
#include <raylib.h>

#ifndef PLAYER_H
#define PLAYER_H

struct Player {
private:
	Vector2 position = { 300,300 };
	float reaching_time = 2;
	Vector2 speed = { 0,0 };
	int radius = 30;

public:
	void _player();
	void draw(Vector2);
	void move();
	void get_destination();
};

#endif