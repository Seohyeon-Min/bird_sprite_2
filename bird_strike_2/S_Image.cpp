#include "image.h"

Image capybara_image;
Texture2D Capybara_texture;
Image DigiPenlogo_image;
Texture2D DigiPenlogo_texture;

void loadimage() {
    capybara_image = LoadImage("textures/capybara.png");
    Capybara_texture = LoadTextureFromImage(capybara_image);
    UnloadImage(capybara_image);

    DigiPenlogo_image = LoadImage("textures/DigiPen_logo.png");
    DigiPenlogo_texture = LoadTextureFromImage(DigiPenlogo_image);
    UnloadImage(DigiPenlogo_image);
}