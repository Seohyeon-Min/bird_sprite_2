#include <raylib.h>
#include <iostream>
#include <vector>
#include "H_Player.h"

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
float get_distance_y( float posy, float desy) {
    distance.y = posy - desy;
    return distance.y;
}

void Player::draw(Vector2 pos) {
    DrawCircle(pos.x, pos.y, radius, BLUE);
}

void Player::x() {
    if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
        destination = GetMousePosition();
    }
    speed.x = get_distance_x(position.x, destination.x) / reaching_time;
    speed.y = get_distance_y(position.y, destination.y) / reaching_time;
}

void Player::move() {

    x();
    position.x -= speed.x;
    position.y -= speed.y;
}

void Player::_player() {
    move();
    draw(position);
}