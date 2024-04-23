#include "OOLC.h"
#include <windows.h>
#include <string.h>
#include <fstream>

int gameStart(player& p) {

	printHide(0);
	system("mode con cols=111 lines=37");

	const point O(22, 5);
	const point mainSize(33,23);
	const point say(O + point(0, mainSize.y));//(22,28)
	//有效区域x:[0,5+31+5],y:[0,5+21+5](以汉字为单位)
	{//打印屏幕边框
		//清空中心区
		rechoose:
		for (int y = O.y; y < O.y + mainSize.y; ++y) {
			printGoto(O + point(0, y - O.y));
			for (int i = 0; i < mainSize.x; ++i) {
				printf("  ");
			}
		}
		//上横
		printGoto(O);
		printf("丁");
		for (int i = 0; i < mainSize.x-2; ++i) { printf("一"); }
		printf("丁");
		//下横
		printGoto(O+point(0,mainSize.y-1));
		printf("乚");
		for (int i = 0; i < mainSize.x-2; ++i) { printf("一"); }
		printf("亅");
		//两竖
		for (int y = O.y+1; y < O.y+mainSize.y-1; ++y) {
			printGoto(O.x, y), printf("丨");
			printGoto(O.x+(mainSize.x-1)*2, y), printf("丨");
		}
		//交互框
		printGoto(O + point(0, mainSize.y));
		printf("丁");
		for (int i = 0; i < mainSize.x - 2; ++i) { printf("一"); }
		printf("丁");
		for (int y = (O + point(0, mainSize.y + 1)).y; y < (O + point(0, mainSize.y + 1)).y+5; ++y) {
			printGoto(O.x, y), printf("丨");
			printGoto(O.x + (mainSize.x - 1) * 2, y), printf("丨");
		}
		printGoto((O + point(0, mainSize.y + 6)));
		printf("乚");
		for (int i = 0; i < mainSize.x - 2; ++i) { printf("一"); }
		printf("亅");
	}

	{//标题和选项
		printGoto(mainSize.x+O.x-(8+1), mainSize.y/2+O.y-5);
		printf("猫猫降临到我身边");
		printGoto(mainSize.x+O.x-5-10-2, mainSize.y/2+O.y);
		printf("->继续游戏");
		printGoto(mainSize.x + O.x - 5 + 10, mainSize.y / 2 + O.y);
		printf("新的开始");
		printGoto(mainSize.x + O.x - 5 - 10, mainSize.y / 2 + O.y + 3);
		printf("关于作者");
		printGoto(mainSize.x + O.x - 5 + 10, mainSize.y / 2 + O.y + 3);
		printf("退出游戏");
	}
	{//用户选择
		int choose = 0;
		while (check(' '));//防误触
		while (!check(' ')) {
			if (check('W') || check('A') || check('S') || check('D')) {
				if (check('W')) {
					choose += 2, choose %= 4;
				}
				if (check('A')) {
					choose += 3, choose %= 4;
				}
				if (check('S')) {
					choose += 2, choose %= 4;
				}
				if (check('D')) {
					choose ++, choose %= 4;
				}
				if (choose == 0) {
					printGoto(mainSize.x + O.x - 5 - 10 - 2, mainSize.y / 2 + O.y);
					printf("->");
					printGoto(mainSize.x + O.x - 5 + 10 - 2, mainSize.y / 2 + O.y);
					printf("  ");
					printGoto(mainSize.x + O.x - 5 - 10 - 2, mainSize.y / 2 + O.y + 3);
					printf("  ");
					printGoto(mainSize.x + O.x - 5 + 10 - 2, mainSize.y / 2 + O.y + 3);
					printf("  ");
				}
				else if (choose == 1) {
					printGoto(mainSize.x + O.x - 5 - 10 - 2, mainSize.y / 2 + O.y);
					printf("  ");
					printGoto(mainSize.x + O.x - 5 + 10 - 2, mainSize.y / 2 + O.y);
					printf("->");
					printGoto(mainSize.x + O.x - 5 - 10 - 2, mainSize.y / 2 + O.y + 3);
					printf("  ");
					printGoto(mainSize.x + O.x - 5 + 10 - 2, mainSize.y / 2 + O.y + 3);
					printf("  ");
				}
				else if (choose == 2) {
					printGoto(mainSize.x + O.x - 5 - 10 - 2, mainSize.y / 2 + O.y);
					printf("  ");
					printGoto(mainSize.x + O.x - 5 + 10 - 2, mainSize.y / 2 + O.y);
					printf("  ");
					printGoto(mainSize.x + O.x - 5 - 10 - 2, mainSize.y / 2 + O.y + 3);
					printf("->");
					printGoto(mainSize.x + O.x - 5 + 10 - 2, mainSize.y / 2 + O.y + 3);
					printf("  ");
				}
				else if (choose == 3) {
					printGoto(mainSize.x + O.x - 5 - 10 - 2, mainSize.y / 2 + O.y);
					printf("  ");
					printGoto(mainSize.x + O.x - 5 + 10 - 2, mainSize.y / 2 + O.y);
					printf("  ");
					printGoto(mainSize.x + O.x - 5 - 10 - 2, mainSize.y / 2 + O.y + 3);
					printf("  ");
					printGoto(mainSize.x + O.x - 5 + 10 - 2, mainSize.y / 2 + O.y + 3);
					printf("->");
				}
				while ((check('W') || check('A') || check('S') || check('D'))) {}//松开跳出
			}
		}
		if (choose == 0) {//继续游戏
			getInformation(p);//初始化，读档（玩家信息，场景变量）
			return 0;
		}
		else if (choose == 1) {//新的开始
			if (newInformation() == 0) { goto rechoose; };
			getInformation(p);//初始化，读档（玩家信息，场景变量）
			return 0;
		}
		else if (choose == 2) {//关于作者
			about();
			goto rechoose;
		}
		else if (choose == 3) {//退出游戏
			return 1;
		}
	}
}
void getInformation(player& luozi) {
	using namespace std;
	/*获取玩家的数据成员*/
	//按player数据成员格式换行。
	ifstream fin("./save/player", ofstream::in);
	fin >> luozi.position;
	fin >> luozi.face;

	fin >> luozi.scene;
	luozi.exit = 0;
}
void saveInformation(const scene& scn, const player& luozi) {
	using namespace std;
	{//player
		//按player数据成员格式换行。
		ofstream fout("./save/player", ofstream::out);
		fout << luozi.position << endl;
		fout << luozi.face << endl;

		fout << luozi.scene << endl;
	}
	msgbox("**存档成功**");
}
int newInformation() {//是否创建，创建返回1，取消返回0；
	using namespace std;
	if (YoNbox("是否覆盖并创建新存档？")) {
		//创建新存档
		{//player
			//按player数据成员格式换行。
			ofstream fout("./save/player", ofstream::out);
			fout << point(117, 120) << endl;//position
			fout << point(117, 120) << endl;//face

			fout << 0 << endl;//scene
		}
		return 1;
	}
	else {
		return 0;
	}
}
void about() {
	const point O(22, 5);
	const point mainSize(33, 23);
	for (int y = O.y+1; y < O.y + mainSize.y-1; ++y) {//清空
		printGoto(O + point(2, y - O.y));
		for (int i = 1; i < mainSize.x-1; ++i) {
			printf("  ");
		}
	}
	printGoto(O + point(3, 3));
	printf("关于:");
	printGoto(O + point(3, 4));
	printf("C++大作业， 作者：luozi(*)  指导老师：**");
	printGoto(O + point(3, 5));
	printf("鸣谢：");
	printGoto(O + point(3, 6));
	printf("地图创作者：龙猫酱、根号贰、董某");
	printGoto(O + point(3, 7));
	printf("NPC设计协助：龙猫酱、根号贰、董某、地鼠酱");
	printGoto(O + point(3, 8));
	printf("代码协助：ZQY(*)");
	printGoto(O + point(3, 9));
	printf("方案启发者：CZJ（*）");
	printGoto(O + point(3, 10));
	printf("开发思维协助：ZQY(*)");

	printGoto(O + point(9, 15));
	printf("注：这里没好好排版是因为还有10分钟就到截止时间了，啊啊");



	printGoto(mainSize.x + O.x - (2 + 1) - 2, mainSize.y / 2 + O.y + 7);
	printf("->确认");
	while (check(' '));//防误触
	while (!check(' '));
}
void msgbox(const char* s) {
		const point O(38, 13);
		const point mainSize(17, 7);

		{//打印屏幕边框
			//清空中心区
			for (int y = O.y; y < O.y + mainSize.y; ++y) {
				printGoto(O + point(0, y - O.y));
				for (int i = 0; i < mainSize.x; ++i) {
					printf("  ");
				}
			}
			//上横
			printGoto(O);
			printf("丁");
			for (int i = 0; i < mainSize.x - 2; ++i) { printf("一"); }
			printf("丁");
			//下横
			printGoto(O + point(0, mainSize.y - 1));
			printf("乚");
			for (int i = 0; i < mainSize.x - 2; ++i) { printf("一"); }
			printf("亅");
			//两竖
			for (int y = O.y + 1; y < O.y + mainSize.y - 1; ++y) {
				printGoto(O.x, y), printf("丨");
				printGoto(O.x + (mainSize.x - 1) * 2, y), printf("丨");
			}
		}

		{//标题和选项
			printGoto(mainSize.x + O.x - (strlen(s)/2 + 1), O.y + 2);
			printf("%s",s);
			printGoto(mainSize.x + O.x - (2 + 1) - 2, O.y + 4);
			printf("->确认");
			while (check(' '));//防误触
			while (!check(' '));
		}
}
bool YoNbox(const char* s) {
	const point O(38, 13);
	const point mainSize(17, 7);

	{//打印屏幕边框
		//清空中心区
		for (int y = O.y; y < O.y + mainSize.y; ++y) {
			printGoto(O + point(0, y - O.y));
			for (int i = 0; i < mainSize.x; ++i) {
				printf("  ");
			}
		}
		//上横
		printGoto(O);
		printf("丁");
		for (int i = 0; i < mainSize.x - 2; ++i) { printf("一"); }
		printf("丁");
		//下横
		printGoto(O + point(0, mainSize.y - 1));
		printf("乚");
		for (int i = 0; i < mainSize.x - 2; ++i) { printf("一"); }
		printf("亅");
		//两竖
		for (int y = O.y + 1; y < O.y + mainSize.y - 1; ++y) {
			printGoto(O.x, y), printf("丨");
			printGoto(O.x + (mainSize.x - 1) * 2, y), printf("丨");
		}
	}

	{//标题和选项
		printGoto(mainSize.x + O.x - (strlen(s) / 2 + 1), O.y + 2);
		printf("%s", s);
		printGoto(mainSize.x + O.x - (2 + 1) - 4 - 2, O.y + 4);
		printf("->取消");
		printGoto(mainSize.x + O.x - (2 + 1) + 4, O.y + 4);
		printf("确认");
	}
	{//用户选择
		int choose = 0;
		while (check(' '));//防误触
		while (!check(' ')) {
			if (check('W') || check('A') || check('S') || check('D')) {
				choose++, choose %= 2;
				if (choose == 0) {
					printGoto(mainSize.x + O.x - (2 + 1) - 4 - 2, O.y + 4);
					printf("->");
					printGoto(mainSize.x + O.x - (2 + 1) + 4 - 2, O.y + 4);
					printf("  ");
				}
				else if (choose == 1) {
					printGoto(mainSize.x + O.x - (2 + 1) - 4 - 2, O.y + 4);
					printf("  ");
					printGoto(mainSize.x + O.x - (2 + 1) + 4 - 2, O.y + 4);
					printf("->");
				}				
				while ((check('W') || check('A') || check('S') || check('D'))) {}//松开跳出
			}
		}
		return choose;
	}
}
void sayclear() {
	const point O(22, 5);
	const point mainSize(33, 23);
	const point say(O + point(0, mainSize.y));

		for (int y = (O + point(0, mainSize.y + 1)).y; y < (O + point(0, mainSize.y + 1)).y + 5; ++y) {
			printGoto(O.x + 2, y);
			for (int i = 0; i < mainSize.x - 2; ++i) { 
				printf("  "); 
			}
		}
}
void say(const char*s, int l, bool time){
	if (l <= 0 || 6 <= l) { return; }

	const point O(22, 5);
	const point mainSize(33, 23);
	const point say(O + point(0, mainSize.y));
	printGoto(O.x + 2, (O + point(0, mainSize.y + l)).y);//清空此行
	for (int i = 0; i < mainSize.x - 2; ++i) {
		printf("  ");
	}
	printGoto(O.x + 2, (O + point(0, mainSize.y + l)).y);
	if (time) {
		for (int i = 0; i < strlen(s); i += 2) {
			char c[3] = { 0 };
			c[0] = s[i], c[1] = s[i + 1];
			printf("%s", c);
			Sleep(75);
		}
	}
	else { printf("%s", s); }
}
void sayyes() {
	say("                                                      ->确认", 5, 0);
	while (!check(' '));
	say("", 5, 0);
	while (check(' '));//防误触
}
