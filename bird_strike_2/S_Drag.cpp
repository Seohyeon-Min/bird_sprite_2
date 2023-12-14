/* GAM100

Seokhwa Hong

All content © 2023 DigiPen (USA) Corporation, all rights reserved. */

#include <raylib.h>
#include <iostream>
#include <vector>
#include <thread>
#include <ctime>
#include "H_Crow.h"
#include "H_Drag.h"
#include "H_Main.h"
#include "H_Beat_system.h"

Vector2 mouse_click{ -1,-1 };
Vector2 mousepostion{ -1,-1 };
Vector2 Fdrag_position = { -1,-1 };
Vector2 Sdrag_position = { -1,-1 };
Vector2 Firstpos = { -1,-1 };
bool drawonce = false;

std::vector<NewLine> nlines{};
std::vector<ConLine> clines{};

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
		DrawLineEx(prepostion, postion, Line_ex + 2, Outline_color);
		DrawLineEx(prepostion, postion, Line_ex, Line_color);
	} while (false);
}

//connection line struct
void ConLine::condraw() {
	do {
		DrawLineEx(prepostion, postion, Line_ex + 2, Outline_color);
		DrawLineEx(prepostion, postion, Line_ex, Line_color);
	} while (false);
}





//make new line
void Drag::makeNewDrag() {

	nlines.clear();
	if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
		if (mouse_click.x == -1 && mouse_click.y == -1) {
			mouse_click = { float(GetMouseX()), float(GetMouseY()) };
		}
		if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
			if (Fdrag_position.x > 0 || Sdrag_position.x > 0) {
				NewLine new_line(mousepostion, { float(GetMouseX()), float(GetMouseY()) }, drag_ex, drag_color);
				nlines.push_back(new_line);

			}
		}
	}
}

void Drag::givedrag(Vector2 pos) {
	Firstpos = pos;
}

void Drag::check_Fdrag(Vector2 pos) {

	Fdrag_position = pos;
	mousepostion = Fdrag_position;
	Switch *= -1;
	drawonce = true;
}

void Drag::check_Sdrag(Vector2 pos) {
	Sdrag_position = pos;
	mousepostion = Sdrag_position;
	Switch *= -1;
	drawonce = true;
}



//make connection line
void Drag::makeConDrag() {
	if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && drawonce) {
		if (mouse_click.x == -1 && mouse_click.y == -1) {
			mouse_click = { float(GetMouseX()), float(GetMouseY()) };
		}
		if (Sdrag_position.x > 0 && Sdrag_position.y > 0 && Fdrag_position.x > 0 && Fdrag_position.y > 0) {
			ConLine new_cline(Fdrag_position, Sdrag_position, drag_ex, drag_color);
			clines.push_back(new_cline);
		}
		drawonce = false;
	}
}

void Drag::fail_drag() {
	clines.clear();
	nlines.clear();
	mousepostion = { -1,-1 };
	Fdrag_position = { -1,-1 };
	Sdrag_position = { -1,-1 };
	Firstpos = { -1,-1 };
}


void Drag::Fx() {

	makeConDrag();
	makeNewDrag();

	//draw line
	for (size_t i = 0; i < nlines.size(); i++) {
		nlines[i].newdraw();


	}

	for (size_t i = 0; i < clines.size(); i++) {
		clines[i].condraw();
	}

	// Set your variables including SecondTerm value
	extern double SecondTerm; // Replace this with your desired time delay

	if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {

		clines.clear();
		nlines.clear();
		mousepostion = { -1,-1 };
		Fdrag_position = { -1,-1 };
		Sdrag_position = { -1,-1 };
		Firstpos = { -1,-1 };

	}



}


