#ifndef OPTION_H
#define OPTION_H



class Control_bar
{
public:
	void draw();
	void update_all();

private:
	Vector2 position;
	int padding = 50;
};

#endif 
