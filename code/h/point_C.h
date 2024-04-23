#pragma once
#include <iostream>

struct point {
	int x = 0;
	int y = 0;

	point(int x = 0, int y = 0);
	point operator+(const point& a)const;
	point operator-(const point& a)const;
	point operator+=(const point& a);
	point operator-=(const point& a);
	bool operator==(const point& a)const;
	bool operator!=(const point& a)const;

	friend std::istream& operator >> (std::istream& is, point& p);
	friend std::ostream& operator << (std::ostream& os, const point& p);

};
