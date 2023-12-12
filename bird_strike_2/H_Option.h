#ifndef OPTION_H
#define OPTION_H

constexpr float default_SFX = 0.3;

class Control_bar
{
public:
	void draw_bar(int y);
	void draw_button(int y);
	void update_all();
	void move_button();
	void adjust();

private:
	float value_added;
	float value;
	void limit_button_movement();
	Rectangle bar{ 500,200,400,40 };
	Rectangle button{ 608,200,40,40 };
	Vector2 padding = { 250,50 };
};

void update_others();
void draw_toggle();

#endif 