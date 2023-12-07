#include <raylib.h>
#include <iostream>
#include <vector>
#include "H_Crow.h"
#include "H_Player.h"
#include "H_Image.h"

Vector2 distance;
Vector2 destination; //why it doesn't work when it moves to header file?

std::ostream& operator<<(std::ostream& ostr, Vector2 vec)
{
    return ostr << vec.x << ", " << vec.y;
}

//Vector2 get_distance(Vector2 pos, Vector2 des) {
//    distance = sqrt(pow(pos.x - des.x, 2) + pow(pos.y - des.y, 2));
//    return distance;
//}

float get_distance_x(float posx, float desx) {
    distance.x = posx - desx;
    return distance.x;
}
float get_distance_y(float posy, float desy) {
    distance.y = posy - desy;
    return distance.y;
}

void Player::draw(Vector2 pos) {
    DrawCircle(pos.x, pos.y, radius, BLUE);
    DrawTexturePro(player_go_texture,
        { 0,0,(float)player_go_image.width,(float)player_go_image.height },
        { pos.x,pos.y, 100,100 },
        { 50,50 },
        0,
        WHITE
    );
}

void Player::get_destination() {
    destination = return_delete_crow_position();
    speed.x = get_distance_x(position.x, destination.x) / reaching_time;
    speed.y = get_distance_y(position.y, destination.y) / reaching_time;
}

void Player::move() {
    std::cout << position.x << std::endl;
    get_destination();
    position.x -= speed.x;
    position.y -= speed.y;
}

void Player::_player() {
    move();
    draw(position);
}