#include "H_Audio.h"

Music option_music;
Music lobby_music;
Music stage1_music;
Sound crow_blow;
Sound to_two_phase;

void loadaudio() {
	option_music = LoadMusicStream("audio/option.mp3");
	lobby_music = LoadMusicStream("audio/lobby_audio.mp3");
	stage1_music = LoadMusicStream("audio/stage1.mp3");

	crow_blow = LoadSound("audio/crow_blow.mp3");
	to_two_phase = LoadSound("audio/to_2phase.mp3");


}