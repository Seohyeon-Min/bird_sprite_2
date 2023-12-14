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
Image star_icon_image;
Texture2D star_icon_texture;
Image challenge_icon_image;
Texture2D challenge_icon_texture;
Image grass_2_image;
Texture2D grass_2_texture;
Image sun_stage_2_image;
Texture2D sun_stage_2_texture;
Image vignetting_image;
Texture2D vignetting_texture;
Image Nice_to_meet_you_1_image;
Texture2D Nice_to_meet_you_1_texture;
Image Nice_to_meet_you_2_image;
Texture2D Nice_to_meet_you_2_texture;
Image Its_my_first_day_1_image;
Texture2D Its_my_first_day_1_texture;
Image Its_my_first_day_2_image;
Texture2D Its_my_first_day_2_texture;
Image best_aimer_1_image;
Texture2D best_aimer_1_texture;
Image best_aimer_2_image;
Texture2D best_aimer_2_texture;
Image carzy_aimer_1_image;
Texture2D carzy_aimer_1_texture;
Image carzy_aimer_2_image;
Texture2D carzy_aimer_2_texture;
Image strike_1_image;
Texture2D strike_1_texture;
Image strike_2_image;
Texture2D strike_2_texture;
Image player_stop_image;
Texture2D player_stop_texture;
Image player_stop_uncon_image;
Texture2D player_stop_uncon_texture;
Image BIRD_STRIKER_1_image;
Texture2D  BIRD_STRIKER_1_texture;
Image BIRD_STRIKER_2_image;
Texture2D  BIRD_STRIKER_2_texture;
Image not_done_1_image;
Texture2D  not_done_1_texture;
Image not_done_2_image;
Texture2D  not_done_2_texture;
Image THE_BIRD_1_image;
Texture2D  THE_BIRD_1_texture;
Image THE_BIRD_2_image;
Texture2D  THE_BIRD_2_texture;
Image check_image;
Texture2D  check_texture;
Image check2_image;
Texture2D  check2_texture;
Image tutorial_1_image;
Texture2D tutorial_1_texture;
Image tutorial_2_image;
Texture2D tutorial_2_texture;
Image tutorial_3_image;
Texture2D tutorial_3_texture;
Image tutorial_4_image;
Texture2D tutorial_4_texture;
Image tutorial_5_image;
Texture2D tutorial_5_texture;
Image tutorial_6_image;
Texture2D tutorial_6_texture;
Image kingturi_image;
Texture2D kingturi_texture;
Image credit_image;
Texture2D  credit_texture;




Font font;
Font font2;




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

    star_icon_image = LoadImage("textures/star_icon.png");
    star_icon_texture = LoadTextureFromImage(star_icon_image);
    UnloadImage(star_icon_image);

    challenge_icon_image = LoadImage("textures/challenge_icon.png");
    challenge_icon_texture = LoadTextureFromImage(challenge_icon_image);
    UnloadImage(challenge_icon_image);

    grass_2_image = LoadImage("textures/grass_2.png");
    grass_2_texture = LoadTextureFromImage(grass_2_image);
    UnloadImage(grass_2_image);

    sun_stage_2_image = LoadImage("textures/sun/sun_stage_2.png");
    sun_stage_2_texture = LoadTextureFromImage(sun_stage_2_image);
    UnloadImage(sun_stage_2_image);

    Nice_to_meet_you_1_image = LoadImage("textures/challenge/Nice_to_meet_you_1.png");
    Nice_to_meet_you_1_texture = LoadTextureFromImage(Nice_to_meet_you_1_image);
    UnloadImage(Nice_to_meet_you_1_image);

    Nice_to_meet_you_2_image = LoadImage("textures/challenge/Nice_to_meet_you_2.png");
    Nice_to_meet_you_2_texture = LoadTextureFromImage(Nice_to_meet_you_2_image);
    UnloadImage(Nice_to_meet_you_2_image);

    Its_my_first_day_1_image = LoadImage("textures/challenge/Its_my_first_day_1.png");
    Its_my_first_day_1_texture = LoadTextureFromImage(Its_my_first_day_1_image);
    UnloadImage(Its_my_first_day_1_image);

    Its_my_first_day_2_image = LoadImage("textures/challenge/Its_my_first_day_2.png");
    Its_my_first_day_2_texture = LoadTextureFromImage(Its_my_first_day_2_image);
    UnloadImage(Its_my_first_day_2_image);

    best_aimer_1_image = LoadImage("textures/challenge/best_aimer_1.png");
    best_aimer_1_texture = LoadTextureFromImage(best_aimer_1_image);
    UnloadImage(best_aimer_1_image);

    best_aimer_2_image = LoadImage("textures/challenge/best_aimer_2.png");
    best_aimer_2_texture = LoadTextureFromImage(best_aimer_2_image);
    UnloadImage(best_aimer_2_image);

    carzy_aimer_1_image = LoadImage("textures/challenge/carzy_aimer_1.png");
    carzy_aimer_1_texture = LoadTextureFromImage(carzy_aimer_1_image);
    UnloadImage(carzy_aimer_1_image);

    carzy_aimer_2_image = LoadImage("textures/challenge/carzy_aimer_2.png");
    carzy_aimer_2_texture = LoadTextureFromImage(carzy_aimer_2_image);
    UnloadImage(carzy_aimer_2_image);

    strike_1_image = LoadImage("textures/challenge/strike_1.png");
    strike_1_texture = LoadTextureFromImage(strike_1_image);
    UnloadImage(strike_1_image);

    strike_2_image = LoadImage("textures/challenge/strike_2.png");
    strike_2_texture = LoadTextureFromImage(strike_2_image);
    UnloadImage(strike_2_image);

    player_stop_image = LoadImage("textures/player_stop.png");
    player_stop_texture = LoadTextureFromImage(player_stop_image);
    UnloadImage(player_stop_image);

    player_stop_uncon_image = LoadImage("textures/player_stop_uncon.png");
    player_stop_uncon_texture = LoadTextureFromImage(player_stop_uncon_image);
    UnloadImage(player_stop_uncon_image);

    BIRD_STRIKER_1_image = LoadImage("textures/challenge/BIRD_STRIKER_1.png");
    BIRD_STRIKER_1_texture = LoadTextureFromImage(BIRD_STRIKER_1_image);
    UnloadImage(BIRD_STRIKER_1_image);

    BIRD_STRIKER_2_image = LoadImage("textures/challenge/BIRD_STRIKER_2.png");
    BIRD_STRIKER_2_texture = LoadTextureFromImage(BIRD_STRIKER_2_image);
    UnloadImage(BIRD_STRIKER_2_image);

    not_done_1_image = LoadImage("textures/challenge/not_done_1.png");
    not_done_1_texture = LoadTextureFromImage(not_done_1_image);
    UnloadImage(not_done_1_image);

    not_done_2_image = LoadImage("textures/challenge/not_done_2.png");
    not_done_2_texture = LoadTextureFromImage(not_done_2_image);
    UnloadImage(not_done_2_image);

    THE_BIRD_1_image = LoadImage("textures/challenge/THE_BIRD_1.png");
    THE_BIRD_1_texture = LoadTextureFromImage(THE_BIRD_1_image);
    UnloadImage(THE_BIRD_1_image);


    THE_BIRD_2_image = LoadImage("textures/challenge/THE_BIRD_2.png");
    THE_BIRD_2_texture = LoadTextureFromImage(THE_BIRD_2_image);
    UnloadImage(THE_BIRD_2_image);

    check_image = LoadImage("textures/check.png");
    check_texture = LoadTextureFromImage(check_image);
    UnloadImage(check_image);

    check2_image = LoadImage("textures/check2.png");
    check2_texture = LoadTextureFromImage(check2_image);
    UnloadImage(check2_image);

    tutorial_1_image = LoadImage("textures/tutorial/tutorial_1.png");
    tutorial_1_texture = LoadTextureFromImage(tutorial_1_image);
    UnloadImage(tutorial_1_image);

    tutorial_2_image = LoadImage("textures/tutorial/tutorial_2.png");
    tutorial_2_texture = LoadTextureFromImage(tutorial_2_image);
    UnloadImage(tutorial_2_image);

    tutorial_3_image = LoadImage("textures/tutorial/tutorial_3.png");
    tutorial_3_texture = LoadTextureFromImage(tutorial_3_image);
    UnloadImage(tutorial_3_image);

    tutorial_4_image = LoadImage("textures/tutorial/tutorial_4.png");
    tutorial_4_texture = LoadTextureFromImage(tutorial_4_image);
    UnloadImage(tutorial_4_image);


    tutorial_5_image = LoadImage("textures/tutorial/tutorial_5.png");
    tutorial_5_texture = LoadTextureFromImage(tutorial_5_image);
    UnloadImage(tutorial_5_image);

    tutorial_6_image = LoadImage("textures/tutorial/tutorial_6.png");
    tutorial_6_texture = LoadTextureFromImage(tutorial_6_image);
    UnloadImage(tutorial_6_image);

    kingturi_image = LoadImage("textures/kingturi.png");
    kingturi_texture = LoadTextureFromImage(kingturi_image);
    UnloadImage(kingturi_image);

    credit_image = LoadImage("textures/credit.png");
    credit_texture = LoadTextureFromImage(credit_image);
    UnloadImage(credit_image);

    vignetting_image = LoadImage("textures/vignette_white.png");
    vignetting_texture = LoadTextureFromImage(vignetting_image);
    UnloadImage(vignetting_image);


    font = LoadFont("resources/romulus.png");
    font2 = LoadFont("resources/mecha.png");
}

