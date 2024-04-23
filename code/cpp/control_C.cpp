#include "control_C.h"
#include <windows.h>
#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0) //必要的，我是背下来的(螺子抄来的)

bool check(char c) {//检测某个按键是否按下
	return KEY_DOWN(c);   
}
void printColor(int a) {//改变输出的颜色，比system("color x")快得多
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), a);
    /*
    <span style="white-space:pre">    </span>字
        1   深蓝色
        2   深绿色
        3   深青色
        4   深红色
        5   深粉色
        6   黄色
        7   深白色
        8   灰色
        9   浅蓝色
        10  浅绿色
        11  浅青色
        12  浅红色
        13  浅粉色
        14  浅黄色
        15  浅白色

        背景
        1~15        黑色
        16~31       深蓝色
        32~47       深绿色
        48~63       深青色
        64~79       深红色
        80~95       深粉色
        96~111      深黄色
        112~127     深白色
        128~143     灰色
        144~159     浅蓝色
        160~175     浅绿色
        176~191     浅青色
        192~207     浅红色
        208~223     浅粉色
        224~239     浅黄色
        240~255     浅白色
    */
}

void printGoto(int x, int y) {
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;            //横坐标
	pos.Y = y;            //纵坐标

	SetConsoleCursorPosition(hOut, pos);
}
void printGoto(const point& p) {
	printGoto(p.x, p.y);
}
void printHide(bool open) {
	CONSOLE_CURSOR_INFO cursor; //定义结构体 控制台光标信息
	cursor.bVisible = open; //设置不显示
	cursor.dwSize = 1; //bzd
	HANDLE hand = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorInfo(hand, &cursor); //设置光标信息
}

