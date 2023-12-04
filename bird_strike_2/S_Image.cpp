#include "H_Image.h"

Image capybara_image;
Texture2D Capybara_texture;
Image DigiPenlogo_image;
Texture2D DigiPenlogo_texture;
Image grass_image;
Texture2D grass_texture;
Image Sprite_crow_image;
Texture2D Sprite_crow_texture;
Image Sprite_crow_outline_image;
Texture2D Sprite_crow_outline_texture;
Image player_go_image;
Texture2D player_go_texture;
Image crow_click_outline_image;
Texture2D crow_click_outline_texture;
Image title_Sheet_image;
Texture2D title_Sheet_texture;
Image crow_die_Sheet_image;
Texture2D crow_die_Sheet_texture;
Image title_background_image;
Texture2D title_background_texture;
Image stage1_background_image;
Texture2D stage1_background_texture;
Image sun_back_image;
Texture2D sun_back_texture;
Image sun_front_image;
Texture2D sun_front_texture;
Image sun_gradation_image;
Texture2D sun_gradation_texture;
Image setting_icon_image;
Texture2D setting_icon_texture;

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

    Sprite_crow_outline_image = LoadImage("textures/Sprite_crow_outline.png");
    Sprite_crow_outline_texture = LoadTextureFromImage(Sprite_crow_outline_image);
    UnloadImage(Sprite_crow_outline_image);

    player_go_image = LoadImage("textures/player_go.png");
    player_go_texture = LoadTextureFromImage(player_go_image);
    UnloadImage(player_go_image);

    crow_click_outline_image = LoadImage("textures/crow_click_outline.png");
    crow_click_outline_texture = LoadTextureFromImage(crow_click_outline_image);
    UnloadImage(crow_click_outline_image);

    title_Sheet_image = LoadImage("textures/title_Sheet.png");
    title_Sheet_texture = LoadTextureFromImage(title_Sheet_image);
    UnloadImage(title_Sheet_image);

    crow_die_Sheet_image = LoadImage("textures/crow_die_Sheet.png");
    crow_die_Sheet_texture = LoadTextureFromImage(crow_die_Sheet_image);
    UnloadImage(crow_die_Sheet_image);

    title_background_image = LoadImage("textures/title_background.png");
    title_background_texture = LoadTextureFromImage(title_background_image);
    UnloadImage(title_background_image);

    stage1_background_image = LoadImage("textures/background/background_sample.png");
    stage1_background_texture = LoadTextureFromImage(stage1_background_image);
    UnloadImage(stage1_background_image);

    sun_back_image = LoadImage("textures/sun/sun_back.png");
    sun_back_texture = LoadTextureFromImage(sun_back_image);
    UnloadImage(sun_back_image);

    sun_front_image = LoadImage("textures/sun/sun_front.png");
    sun_front_texture = LoadTextureFromImage(sun_front_image);
    UnloadImage(sun_front_image);

    sun_gradation_image = LoadImage("textures/sun/sun_gradation.png");
    sun_gradation_texture = LoadTextureFromImage(sun_gradation_image);
    UnloadImage(sun_gradation_image);

    setting_icon_image = LoadImage("textures/setting_icon.png");
    setting_icon_texture = LoadTextureFromImage(setting_icon_image);
    UnloadImage(setting_icon_image);
}




