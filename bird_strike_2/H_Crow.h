
/* GAM100

Seohyeon Min

All content © 2023 DigiPen (USA) Corporation, all rights reserved. */

#ifndef CROW_H
#define CROW_H
#include <raylib.h> 
#include <vector>

constexpr int max_crow =20;
constexpr int crow_per_sec = 3;

struct Crow;

extern bool is_gameover;
extern Vector2 drag_position;
extern std::vector<Crow> crows;
extern int erase_number;
extern bool holding;
extern bool erase_flag;
extern bool crow_just_erased;

struct Crow {
private:
    int radius = GetScreenWidth() / 30.72;//30
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
    bool marked = false;  //mark the crow that will be deleted
    Vector2 get_position();
    void _crow();
    bool mouse_click();
    bool intersection(float x, float y);
    void add_crow();
    void first_move();
    void move();
    void draw(bool hover);
    void checkdirection();
    void animation_move();
    void fail_to_connect();

};

void ready_to_delete();
void delete_crow();
Vector2 return_delete_crow_position();
void check_game_over();
std::tuple <std::string, float> return_game_over_txt();
int return_order_counter();
int return_crow_size();

#endif