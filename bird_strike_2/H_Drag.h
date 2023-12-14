#ifndef DRAG_H
#define DRAG_H
#include <vector>
#include "H_Crow_pattern.h"

constexpr Color drag_color{ BLACK };
constexpr Color drag_outline = Color{ 255,255,255,178 };
constexpr int drag_ex{ 4 };
using namespace std;
extern int Switch;

struct NewLine;
struct ConLine;

extern std::vector<NewLine> nlines;
extern std::vector<ConLine> clines;


struct NewLine
{
private:
	Vector2 prepostion{ 0,0 };
	Vector2 postion{ 0,0 };
	int Line_ex{ 0 };
	Color Line_color{ drag_color };
	Color Outline_color{ drag_outline };
public:
	NewLine(Vector2 prepos, Vector2 post, int ex, Color color);
	void newdraw();
};

struct ConLine
{
private:
	Vector2 prepostion{ 0,0 };
	Vector2 postion{ 0,0 };
	int Line_ex{ 0 };
	Color Line_color{ drag_color };
	Color Outline_color{ drag_outline };

public:
	ConLine(Vector2 prepos, Vector2 post, int ex, Color color);
	void condraw();
	friend Crow_pattern;
};

struct Drag {
private:
	int Dradius = 20;
	bool a = false;
	bool b = false;

public:
	void check_Fdrag(Vector2 pos);
	void check_Sdrag(Vector2 pos);
	void givedrag(Vector2 pos);
	void makeNewDrag();
	void makeConDrag();
	void fail_drag();
	void Fx();
};






#endif