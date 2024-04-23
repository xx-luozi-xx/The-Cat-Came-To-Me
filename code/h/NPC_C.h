#pragma once
#include "point_C.h"
#include "player_C.h"
#include "base_word_C.h"

class NPC :public base_word {
public:

	point position;
	point velocity;

	bool ifMove;
	bool crazyMove;
	int TimeOfDo;

	NPC(int id, const point& position, const point& velocity = {0,0}, bool ifMove = 1);

	virtual void selfDo(player* p, Map* m = nullptr) {}
	virtual void playerDo(player* p, Map* m = nullptr) {}

	virtual ~NPC() {}
};
class door : public NPC {//门
public:
	point gotoPosition;
	int gotoScene;
	
	door(const point& position, const point& gotoPosition, int gotoScene);

	virtual void playerDo(player* p, Map* m = nullptr);

	virtual ~door() {}
};
class DOOR : public NPC {//門
public:
	point gotoPosition;
	int gotoScene;

	DOOR(const point& position, const point& gotoPosition, int gotoScene);

	virtual void selfDo(player* p, Map* m = nullptr);

	virtual ~DOOR() {}
};
class through :public NPC {
public:
	int age;
	const char* s;

	through(const point& position, const char* s);
	virtual void playerDo(player* p, Map* m = nullptr);
	virtual void selfDo(player* p, Map* m = nullptr);
	virtual ~through() {};
};
class tell : public NPC {
public:
	bool l[5] = { 0 };
	const char* s1;
	const char* s2;
	const char* s3;
	const char* s4;

	tell(const point& position, const char* s1="", const char* s2="", const char* s3="", const char* s4="", bool l1=1, bool l2=0, bool l3=0, bool l4=0);
	tell(const char* name,const point& position, const char* s1);
	virtual void playerDo(player* p, Map* m = nullptr);
	virtual ~tell() {}
};
