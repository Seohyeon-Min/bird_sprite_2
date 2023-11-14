#include <raylib.h>
#include <iostream>
#include <vector>
#include <thread>
#include <ctime>
#include "drag.h"
#include "crow.h"

NewLine::NewLine(Vector2 prepos, Vector2 post, int ex, Color color)
{
	prepostion = prepos;
	postion = post;
	Line_ex = ex;
	Line_color = color;
}

ConLine::ConLine(Vector2 prepos, Vector2 post, int ex, Color color)
{
	prepostion = prepos;
	postion = post;
	Line_ex = ex;
	Line_color = color;
}



//new+mouse line struct
void NewLine::newdraw() {
	do {
		DrawLineEx(prepostion, postion, Line_ex, Line_color);
	} while (false);
}

//connection line struct
void ConLine::condraw() {
	do {
		DrawLineEx(prepostion, postion, Line_ex, Line_color);
	} while (false);
}


//Effect when dragging mouse

//make new line
void Drag::makeNewDrag() { //TODO: how can I get crow here?
	nlines.clear();
	if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
		if (mouse_click.x == -1 && mouse_click.y == -1) {
			mouse_click = { float(GetMouseX()), float(GetMouseY()) };
		}
		if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
			if (Sdrag_position.x != 0 && Sdrag_position.y != 0) {
				NewLine new_line(Fdrag_position, Sdrag_position, drag_ex, drag_color);
				nlines.push_back(new_line);
			}
		}
	}
}

void Drag::check_Fdrag(Vector2 pos) {
	Fdrag_position = pos;
	mousepostion = Fdrag_position;
	Switch *= -1;
	markedcount++;
	click = true;
}

void Drag::check_Sdrag(Vector2 pos) {
	Sdrag_position = pos;
	mousepostion = Sdrag_position;
	Switch *= -1;
	markedcount++;
	click = true;
}


void Drag::not_click(){
	if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
		click = false;
		markedcount = 0;
	}
}

//make connection line
void Drag::makeConDrag() {
	if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
		if (mouse_click.x == -1 && mouse_click.y == -1) {
			mouse_click = { float(GetMouseX()), float(GetMouseY()) };
		}
		if (markedcount >= 2) {
			int count = 0;
			ConLine new_cline(Fdrag_position, Sdrag_position, drag_ex, drag_color);
			clines.push_back(new_cline);
		}
	}
}

void Drag::Fx() {
	std::cout << clines.size() << endl;
	if (click) {
		makeConDrag(); //why does it need spawn_point? >> Don't need
		makeNewDrag();


		//draw line
		for (size_t i = 0; i < nlines.size(); i++) {
			nlines[i].newdraw();
		}

		for (size_t i = 0; i < clines.size(); i++) {
			clines[i].condraw();
		}
	}



	if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
		do {
			clines.clear();
			nlines.clear();
		} while (false);
		for (int i = crows.size() - 1; i >= 0; i--) { //delete the crow
			if (crows[i].marked == true) {
				crows.erase(crows.begin() + i);
			}
		}


	}
}