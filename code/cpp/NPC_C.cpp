#include "OOLC.h"

//xx 实现 xx
NPC::NPC(int id, const point& position, const point& velocity, bool ifMove) :base_word(id), position(position), velocity(velocity), ifMove(ifMove), crazyMove(0), TimeOfDo(0) {}

door::door(const point& position, const point& gotoPosition, int gotoScene) : NPC(2, position, { 0,0 }, 0), gotoPosition(gotoPosition), gotoScene(gotoScene) {}

void door::playerDo(player* p, Map* m) {
	p->face = p->position = gotoPosition;
	p->scene = gotoScene;
	throw door::gotoScene;
}
DOOR::DOOR(const point& position, const point& gotoPosition, int gotoScene) : NPC(3, position, { 0,0 }, 0), gotoPosition(gotoPosition), gotoScene(gotoScene) {}

void DOOR::selfDo(player* p, Map* m) {
	if (p->position == position) {
		p->face = p->position = gotoPosition;	
		p->scene = gotoScene;
		throw DOOR::gotoScene;
	}
}
through::through(const point& position, const char*s) :s(s),age(0), NPC(1, position, {0,0}, 0) { visible = 0; }
void through::playerDo(player* p, Map* m) {
	age++;
	say(s);
	sayyes();
	sayclear();
}
void through::selfDo(player* p, Map* m) {
	if(age == 1 || age == 2) {
		point v = p->face - p->position;
		m->crt(p->position)--;
		p->position += v;
		p->face += v;
		m->crt(p->position)++;
		
		age++;
	}
	else if (age == 3) {
		age = 0;
	}
}
tell::tell(const point& position,const char* s1, const char* s2, const char* s3, const char* s4, bool l1, bool l2, bool l3, bool l4) :s1(s1), s2(s2), s3(s3), s4(s4), NPC(0, position) {
	l[1] = l1, l[2] = l2, l[3] = l3, l[4] = l4;
}
tell::tell(const char* name, const point& position, const char* s1) : NPC(1, position), s1(s1) { 
	this->name = name; 	
	l[1] = 1, l[2] = 0, l[3] = 0, l[4] = 0;
}
void tell::playerDo(player* p, Map* m) {
	l[1] ? say(s1,1,1), 0 : 0;
	l[2] ? say(s2,2,1), 0 : 0;
	l[3] ? say(s3,3,1), 0 : 0;
	l[4] ? say(s4,4,1), 0 : 0;
	sayyes();
	sayclear();
}
