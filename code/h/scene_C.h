#pragma once
#include <vector>
#include "map_C.h"
#include "NPC_C.h"
#include "player_C.h"

class scene {
public:
	std::vector<NPC*> NPCs;
	Map mp;
	player* p;

	void gameStart();
	void playerMove();
	void NPCMove();
	void playerDo();//空格交互
	void NPCDo();//自主行为
	void printMap();
	void esc();
};