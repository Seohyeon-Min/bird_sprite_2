#include "H_Image.h"

Image capybara_image;
Texture2D Capybara_texture;
Image DigiPenlogo_image;
Texture2D DigiPenlogo_texture;
Image grass_image;
Texture2D grass_texture;
Image Sprite_crow_image;
Texture2D Sprite_crow_texture;

void loadimage() {
    capybara_image = LoadImage("textures/capybara.png");
    Capybara_texture = LoadTextureFromImage(capybara_image);
    UnloadImage(capybara_image);

    DigiPenlogo_image = LoadImage("textures/DigiPen_logo.png");
    DigiPenlogo_texture = LoadTextureFromImage(DigiPenlogo_image);
    UnloadImage(DigiPenlogo_image);

    grass_image = LoadImage("textures/grass.png");
    grass_texture = LoadTextureFromImage(grass_image);
    UnloadImage(grass_image);

    Sprite_crow_image = LoadImage("textures/Sprite_crow.png");
    Sprite_crow_texture = LoadTextureFromImage(Sprite_crow_image);
    UnloadImage(Sprite_crow_image);
}