#ifndef BEAT_SYSTEM_H
#define BEAT_SYSTEM_H

void IsOnBeat();
void beat_spliting();
void continuous_beat();

extern bool crow_delete_flag;
extern bool prev_judge;
extern bool judge;
extern bool is_changed;
extern bool prev_splited_beat;
extern bool splited_beat;
extern bool continuous_fail;

#endif