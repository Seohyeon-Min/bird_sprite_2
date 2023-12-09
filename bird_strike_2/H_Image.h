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
extern Image grass_2_image;
extern Texture2D grass_2_texture;
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
extern Image sun_stage_2_image;
extern Texture2D sun_stage_2_texture;
extern Image sun_gradation_image;
extern Texture2D sun_gradation_texture;
extern Image setting_icon_image;
extern Texture2D setting_icon_texture;
extern Image star_icon_image;
extern Texture2D star_icon_texture;
extern Image challenge_icon_image;
extern Texture2D challenge_icon_texture;
extern Image vignetting_image;
extern Texture2D vignetting_texture;
extern Image Nice_to_meet_you_1_image;
extern Texture2D Nice_to_meet_you_1_texture;
extern Image Nice_to_meet_you_2_image;
extern Texture2D Nice_to_meet_you_2_texture;
extern Image Its_my_first_day_1_image;
extern Texture2D Its_my_first_day_1_texture;
extern Image Its_my_first_day_2_image;
extern Texture2D Its_my_first_day_2_texture;
extern Image best_aimer_1_image;
extern Texture2D best_aimer_1_texture;
extern Image best_aimer_2_image;
extern Texture2D best_aimer_2_texture;
extern Image carzy_aimer_1_image;
extern Texture2D carzy_aimer_1_texture;
extern Image carzy_aimer_2_image;
extern Texture2D carzy_aimer_2_texture;
extern Image strike_1_image;
extern Texture2D strike_1_texture;
extern Image strike_2_image;
extern Texture2D strike_2_texture;
extern Image player_stop_image;
extern Texture2D player_stop_texture;
extern Font font;
extern Font font2;

void loadimage();

#endif