#ifndef IMAGE_H
#define IMAGE_H
#include "raylib.h"
#include <iostream>

constexpr float capybara_size{ 250 };


extern Image capybara_image;
extern Texture2D Capybara_texture;
extern Image DigiPenlogo_image;
extern Texture2D DigiPenlogo_texture;

void loadimage();

#endif
