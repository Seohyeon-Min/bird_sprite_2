#ifndef IMAGE_H
#define IMAGE_H
#include "raylib.h"
#include <iostream>

constexpr float capybara_size{ 250 };

extern Image capybara_image;
extern Texture2D Capybara_texture;
extern Image DigiPenlogo_image;
extern Texture2D DigiPenlogo_texture;
extern Image grass_image;
extern Texture2D grass_texture;
extern Image Sprite_crow_image;
extern Texture2D Sprite_crow_texture;
extern Image Sprite_crow_outline_image;
extern Texture2D Sprite_crow_outline_texture;
extern Image player_go_image;
extern Texture2D player_go_texture;
extern Image crow_click_outline_image;
extern Texture2D crow_click_outline_texture;
extern Image title_Sheet_image;
extern Texture2D title_Sheet_texture;
extern Image crow_die_Sheet_image;
extern Texture2D crow_die_Sheet_texture;
extern Image title_background_image;
extern Texture2D title_background_texture;
extern Image stage1_background_image;
extern Texture2D stage1_background_texture;
extern Image sun_back_image;
extern Texture2D sun_back_texture;
extern Image sun_front_image;
extern Texture2D sun_front_texture;
extern Image sun_gradation_image;
extern Texture2D sun_gradation_texture;


void loadimage();

#endif
