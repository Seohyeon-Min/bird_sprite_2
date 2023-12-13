#include <raylib.h>
#include <iostream>
#include <vector>
#include "H_Crow.h"
#include "H_Player.h"
#include "H_Image.h"

Vector2 distance;
Vector2 destination; //why it doesn't work when it moves to header file?
const double playeranimation_speed = 0.01;


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
    playeranimation += (GetFrameTime() * playeranimation_speed);
    //std::cout << playeranimation << std::endl;
    if (speed.x > 0) {
        direction = 1;
        playerdirection = (direction * 2 - 1);
        directiontheta = atan2((double)pos.y - return_delete_crow_position().y, (double)pos.x - return_delete_crow_position().x) * 90;
    }
    else if (speed.x == 0 || speed.y == 0) {

        DrawTexturePro(player_stop_texture,
            { 
                float(((float)(player_stop_image.width / 5) * (int)playeranimation)),
                0,
                float(playerdirection * player_stop_image.width / 5),
                (float)player_stop_image.height 
            },
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

    else {
        direction = 0;
        playerdirection = (direction * 2 - 1);
        directiontheta = atan2((double)return_delete_crow_position().y - pos.y, (double)return_delete_crow_position().x - pos.x) * 90;
    }

    if (speed.x != 0) {

        DrawTexturePro(player_go_texture,
            { 0,0,float(playerdirection * player_go_image.width),(float)player_go_image.height },
            {
                position.x ,
                position.y ,
                float(player_go_image.width * sprite_scale),
                float(player_go_image.height * sprite_scale) 
            },
            { (float)(player_go_image.width * sprite_scale / 2) ,(float)(player_go_image.height * sprite_scale / 2) },
            directiontheta,
            WHITE
        );
    }

    playeranimation += GetFrameTime() * player_animation_speed;

}

void Player::get_destination() {
    destination = return_delete_crow_position();
    speed.x = get_distance_x(position.x, destination.x) / reaching_time;
    speed.y = get_distance_y(position.y, destination.y) / reaching_time;

    if ((return_delete_crow_position().x == 0 && return_delete_crow_position().y == 0)|| is_gameover) {
        speed = { 0,0 };
        position = { (float)(GetScreenWidth() / 2) ,(float)(GetScreenHeight() - GetScreenHeight() / 8) };
        sprite_scale = (float)(GetScreenWidth() / 512.0f);
        direction = 0;
    }
}

float floating = 5.0f;

void Player::move() {
    if (speed.x == 0) {
        speed.y = 0;
    }

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