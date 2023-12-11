#include <raylib.h>
#include "H_Option.h"

void Control_bar::draw() {
	DrawRectangle(padding, padding,GetScreenWidth()-padding*2,50,GRAY);
}

void Control_bar::update_all() {
	draw();
}