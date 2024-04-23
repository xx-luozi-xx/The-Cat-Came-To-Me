#pragma once
#define MAX_MAP_SIZE 300
#define PRINT_LONG 50
#define PRINT_HIGH 50

#include "point_C.h"
#include "base_word_C.h"

class Map {
public:

	int Long;//x
	int High;//y

	base_word** map;
	int** creature;

	Map();
	Map(const Map& map);
	Map& operator=(const Map& map);
	~Map();

	const base_word* operator[](int a)const;
	base_word* operator[](int a);
	base_word operator[](const point &p)const;
	base_word& operator[](const point& p);
	int crt(const point& p)const;
	int& crt(const point& p);

};
void swap( Map& l, Map& r);
