#ifndef CROW_H
#define CROW_H
#include <raylib.h> 
#include <vector>


constexpr int max_crow = 30;
constexpr int crow_per_sec = 3;

struct Crow;

extern Vector2 drag_position;
extern std::vector<Crow> crows;
extern int erase_number;
extern bool holding;
extern bool erase_flag;
extern bool crow_just_erased;

struct Crow {
private:
    int radius = 30;
    Vector2 position = { 0, 0 };
    Vector2 speed = { 2, 1 };
    Vector2 acc = { 0.05, 0.008 };
    int spawn_count = 60;
    double animation_timer;
    bool direction = true;


public:

    Crow();
    ~Crow();

    int erase_index = 0;
    int order = 0;
    bool mouse_click();
    bool marked = false;  //mark the crow that will be deleted
    Vector2 get_position();
    void add_crow();
    bool intersection(float x, float y);
    void first_move();
    void _crow();
    void draw(bool hover);
    void move();
    void checkdirection();
    void animation_move();
    void delete_crow();

};

std::string check_game_over();
int return_order_counter();
int return_crow_size();

#endif