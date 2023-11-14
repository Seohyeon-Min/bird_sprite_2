#ifndef DRAG_H
#define DRAG_H
#include <vector>

constexpr Color ball_color{ BLUE };
constexpr Color drag_color{ BLACK };
using namespace std;
extern int Switch;

struct NewLine
{
	private:
		Vector2 prepostion{ 0,0 };
		Vector2 postion{ 0,0 };
		int Line_ex{ 0 };
		Color Line_color{ drag_color };
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
	public:
		ConLine(Vector2 prepos, Vector2 post, int ex, Color color);
		void condraw();
};

struct Drag {
private:
	
	int markedcount = 0;
	int Dradius = 20;
	bool click = false;
	bool a = false;
	bool b = false;
	std::vector<NewLine> nlines;
	std::vector<ConLine> clines;
	Vector2 mousepostion{ 0,0 };
	Vector2 mouse_click{ -1,-1 };
	Vector2 Fdrag_position = { 0,0 };
	Vector2 Sdrag_position = { 0,0 };

public:
	void not_click();
	void check_Fdrag(Vector2 pos);
	void check_Sdrag(Vector2 pos);
	void makeNewDrag();
	void makeConDrag();
	void Fx();
};






#endif