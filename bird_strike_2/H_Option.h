#ifndef OPTION_H
#define OPTION_H

constexpr float default_SFX = 0.8;
constexpr float default_music = 0.8;

class Control_bar
{
public:
	Control_bar();
	Control_bar(const char* name, int y);
	void draw();
	void update_all();
	void move_button();
	float adjust();

private:
	int position;
	const char* name;
	int y;
	void limit_button_movement();
	const Rectangle bar{ 500,200,400,40 };
	const Rectangle button{ 788,200,40,40 };
	const Vector2 padding = { 250,50 };
};

void make_bars();
void draw_toggle();

#endif 