#ifndef CROW_H
#define CROW_H
#include <raylib.h> 
#include <vector>

constexpr int drag_ex{ 5 };
constexpr int max_crow = 20;
constexpr int crow_per_sec = 3;

struct Crow;

extern Vector2 drag_position;
extern std::vector<Crow> crows;

struct Crow {
private:
    int radius = 25;
    Vector2 position = { 0, 0 };
    Vector2 speed = { 2, 1 };
    Vector2 acc = { 0.05, 0.008 };
    int spawn_count = 60;
    int animation_timer{ 0 };
    bool direction = true;

public:
    
    Crow();
    bool mouse_click();
    bool marked = false;
    Vector2 get_position();
    void add_crow();
    void check_game_over();
    bool intersection(float x, float y);
    void first_move();
    void _crow();
    void draw(bool hover);
    void move();
    void checkdirection();
    void animation_move();
};



#endif