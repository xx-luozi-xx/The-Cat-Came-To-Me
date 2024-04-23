#include "point_C.h"
//xx 实现 xx
point::point(int x, int y) :x(x), y(y){}
point point::operator+(const point& a)const{
	return point(x + a.x, y + a.y);
}
point point::operator-(const point& a)const{
	return point(x - a.x, y - a.y);
}
point point::operator+=(const point& a){
	return point(x += a.x, y += a.y);
}
point point::operator-=(const point& a){
	return point(x -= a.x, y -= a.y);
}
bool point::operator==(const point& a)const {
	return x == a.x && y == a.y;
}
bool point::operator!=(const point& a)const {
	return x != a.x || y != a.y;
}
std::istream& operator >> (std::istream& is, point& p) {
	is >> p.x >> p.y;
	return is;
}
std::ostream& operator << (std::ostream& os, const point& p) {
	os << p.x << " " << p.y;
	return os;
}