#include "H_Audio.h"

Music music;
Music option_music;
Sound crow_blow;
Sound to_two_phase;


void loadaudio() {
	music = LoadMusicStream("audio/test_sound.mp3");
	option_music = LoadMusicStream("audio/option.mp3");

	crow_blow = LoadSound("audio/crow_blow.mp3");
	to_two_phase = LoadSound("audio/to_2phase.mp3");
	
	
}
