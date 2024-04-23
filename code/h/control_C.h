#pragma once
#include "point_C.h"

bool check(char c); //检测用户按某键
void printColor(int a);//改变输出的颜色，比system("color x")快得多
void printGoto(int x = 0, int y = 0); //光标定位
void printGoto(const point& position);
void printHide(bool open); //光标显示开关
