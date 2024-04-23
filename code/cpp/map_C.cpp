#include "point_C.h"
#include "map_C.h"
#include <string>
#include <stdio.h>
//xx 实现 xx
Map::Map():High(0),Long(0),map(nullptr),creature(nullptr) {
	map = new base_word* [MAX_MAP_SIZE];
	for (int i = 0; i < MAX_MAP_SIZE; i++) {
		map[i] = new base_word[MAX_MAP_SIZE];
	}
	creature = new int* [MAX_MAP_SIZE];
	for (int i = 0; i < MAX_MAP_SIZE; i++) {
		creature[i] = new int[MAX_MAP_SIZE]{0};
	}
}
Map::Map(const Map& m):High(m.High), Long(m.Long), map(nullptr){
	map = new base_word* [MAX_MAP_SIZE];
	for (int i = 0; i < MAX_MAP_SIZE; i++) {
		map[i] = new base_word[MAX_MAP_SIZE];
	}
	for (int i = 0; i < MAX_MAP_SIZE; i++) {
		for (int j = 0; j < MAX_MAP_SIZE; j++) {
			map[i][j] = m.map[i][j];
		}
	}	
	creature = new int* [MAX_MAP_SIZE];
	for (int i = 0; i < MAX_MAP_SIZE; i++) {
		creature[i] = new int[MAX_MAP_SIZE]{0};
	}
	for (int i = 0; i < MAX_MAP_SIZE; i++) {
		for (int j = 0; j < MAX_MAP_SIZE; j++) {
			creature[i][j] = m.creature[i][j];
		}
	}
}
Map& Map::operator=(const Map& map) {
	Map temp(map);
	swap(*this, temp);
	return *this;
}
Map::~Map() {
	for (int i = 0; i < MAX_MAP_SIZE; i++) {
		delete[] map[i];
		delete[] creature[i];
	}
	delete[] map;
	delete[] creature;
}
base_word Map::operator[](const point& p)const {
	return map[p.x][p.y];
}
base_word& Map::operator[](const point& p) {
	return map[p.x][p.y];
}
base_word* Map::operator[](int a) {
	return map[a];
}
const base_word* Map::operator[](int a)const {
	return map[a];
}
int Map::crt(const point& p)const {
	return creature[p.x][p.y];
}
int& Map::crt(const point& p) {
	return creature[p.x][p.y];
}
void swap(Map& l, Map& r) {
	std::swap(l.map, r.map);
	std::swap(l.creature, r.creature);
	std::swap(l.High, r.High);
	std::swap(l.Long, r.Long);
}
