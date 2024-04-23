#pragma once
#include "scene_C.h"
#include "player_C.h"

int gameStart(player& p);
void getInformation(player& p);
int newInformation();
void saveInformation(const scene& scn, const player& p);
void about();
void msgbox(const char* s);
bool YoNbox(const char* s);
void sayclear();
void say(const char* s, int l = 1, bool time = 1);
void sayyes();