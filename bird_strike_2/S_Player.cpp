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
    DrawTexturePro(player_go_texture,
        { 0,0,(float)player_go_image.width,(float)player_go_image.height },
        {
                position.x ,
                position.y ,
                float(player_go_image.width * sprite_scale),
                float(player_go_image.height * sprite_scale)
        }, 
        { (float)(player_go_image.width * sprite_scale / 2) ,(float)(player_go_image.height * sprite_scale / 2) },
        0,
        WHITE
    );
}

void Player::get_destination() {
    destination = return_delete_crow_position();
    speed.x = get_distance_x(position.x, destination.x) / reaching_time;
    speed.y = get_distance_y(position.y, destination.y) / reaching_time;

    if (return_delete_crow_position().x == 0 && return_delete_crow_position().y == 0) {
        speed = { 0,0 };
        position = { (float)(GetScreenWidth() / 2) ,(float)(GetScreenHeight() - GetScreenHeight() / 8) };
        sprite_scale = (float)(GetScreenWidth() / 512.0f);
    }
}

float floating = 5.0f;

void Player::move() {
    if (speed.x == 0) {
        speed.y = 0;
    }
    //std::cout <<"position:" << position << "   destination:" << return_delete_crow_position() << "  speed:"<<speed<< " floating: " <<floating<< std::endl;
    get_destination();
    position.x -= speed.x;
    position.y -= speed.y;
    //if (position.y > GetScreenHeight() - GetScreenHeight() / 3) {
    //    position.y += floating;
    //}

}

void Player::_player() {
    move();
    draw(position);
}