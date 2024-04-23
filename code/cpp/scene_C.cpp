#include "OOLC.h"
#include <string.h>
//xx 实现 xx
void scene::gameStart() {
	//设置实体
	for (int i = 0; i < NPCs.size(); ++i) {
		if(NPCs[i]->passable == 0)
			mp.creature[NPCs[i]->position.x][NPCs[i]->position.y]++;
	}
	mp.crt(p->position)++;
	{//过场动画
		{//闭幕
			const point O1(22, 5);
			const point mainSize(33, 23);

			int y;
			for (y = O1.y + 1; y < O1.y + (mainSize.y) / 2 - 3; ++y) {
				printGoto(O1 + point(2, y - O1.y));
				for (int i = 0; i < mainSize.x - 2; ++i) {
					printf("■");
				}
				printGoto(O1 + point(2, mainSize.y - 1) - point(0, y - O1.y));
				for (int i = 0; i < mainSize.x - 2; ++i) {
					printf("■");
				}
				Sleep(50);
			}
			printGoto(O1 + point(2, y - O1.y));
			for (int i = 0; i < mainSize.x - 2; ++i) {
				printf("一");
			}
			printGoto(O1 + point(2, mainSize.y - 1) - point(0, y - O1.y));
			for (int i = 0; i < mainSize.x - 2; ++i) {
				printf("一");
			}
			Sleep(50), ++y;
			printGoto(O1 + point(2, y - O1.y));
			for (int i = 0; i < mainSize.x - 2; ++i) {
				printf("  ");
			}
			printGoto(O1 + point(2, mainSize.y - 1) - point(0, y - O1.y));
			for (int i = 0; i < mainSize.x - 2; ++i) {
				printf("  ");
			}
			++y;
			printGoto(O1 + point(2, y - O1.y));
			for (int i = 0; i < mainSize.x - 2; ++i) {
				printf("  ");
			}
			printGoto(O1 + point(2, mainSize.y - 1) - point(0, y - O1.y));
			for (int i = 0; i < mainSize.x - 2; ++i) {
				printf("  ");
			}
			++y;
			printGoto(O1 + point(2, y - O1.y));
			for (int i = 0; i < mainSize.x - 2; ++i) {
				printf("  ");
			}

			const char* s = nullptr;
			if (p->scene == 0) { s = "呆呆兽山庄"; }
			else if (p->scene == 1) { s = "沙  滩"; }
			else if (p->scene == 2) { s = "滴水石洞"; }
			else if (p->scene == 3) { s = "森  林"; }
			else if (p->scene == 4) { s = "心爱农场"; }
			else if (p->scene == 5) { s = "村长之屋"; }
			else if (p->scene == 6) { s = "图书馆"; }
			else if (p->scene == 7) { s = "占星屋"; }
			else if (p->scene == 8) { s = "铁匠铺"; }
			else if (p->scene == 9) { s = "杂货铺"; }
			else if (p->scene == 10) { s = "农贸市场"; }
			else if (p->scene == 11) { s = "龙脊古廊"; }
			else if (p->scene == 12) { s = "密林小屋"; }
			printGoto(mainSize.x + O1.x - (strlen(s) / 2 + 1), y);
			printf("%s", s);
		
		Sleep(1000);
		//开幕
			const point O2(12 * 2, 6);//输出原点
			const point out(31, 21);//输出的地图尺寸

			int Y = p->position.y - out.y / 2;//处理打印地图下标区间
			int X = p->position.x - out.x / 2;
			Y + out.y >= mp.High ? Y = mp.High - out.y : 0;
			Y < 0 ? Y = 0 : 0;
			X + out.x >= mp.Long ? X = mp.Long - out.x : 0;
			X < 0 ? X = 0 : 0;

			for (int y = Y; y < Y + out.y/2; y++) {
				printGoto(O2.x, O2.y + y - Y);
				for (int x = X; x < X + out.x; x++) {
					bool p = 1;
					for (int i = 0; i < NPCs.size(); ++i) {
						if (NPCs[i]->visible && Y <= NPCs[i]->position.y && NPCs[i]->position.y < Y + out.y && X <= NPCs[i]->position.x && NPCs[i]->position.x < X + out.x) {
							if (NPCs[i]->position == point(x, y)) {
								printf("%s", NPCs[i]->name);
								p = 0;
							}
						}
					}
					if (p) {
						if (mp[x][y].visible)
							printf("%s", mp[x][y].name);
						else
							printf("  ");
					}

				}
				printGoto(O2.x, O2.y + y - Y + out.y - 2* ( y - Y ) - 1);
				for (int x = X; x < X + out.x; x++) {
					bool p = 1;
					for (int i = 0; i < NPCs.size(); ++i) {
						if (NPCs[i]->visible && Y <= NPCs[i]->position.y && NPCs[i]->position.y < Y + out.y && X <= NPCs[i]->position.x && NPCs[i]->position.x < X + out.x) {
							if (NPCs[i]->position == point(x, y + out.y - 2 * (y - Y) - 1)) {
								printf("%s", NPCs[i]->name);
								p = 0;
							}
						}
					}
					if (p) {
						if (mp[x][y + out.y - 2 * (y - Y) - 1].visible)
							printf("%s", mp[x][y + out.y - 2 * (y - Y) - 1].name);
						else
							printf("  ");
					}
				}
				Sleep(50);
			}
		}
	}
}
void scene::playerMove() {
	if (check('W')) {
		if ((mp[p->position.x][p->position.y - 1].passable) && mp.creature[p->position.x][p->position.y - 1] == 0) {
			mp.crt(p->position)--;
			p->position.y--;
			mp.crt(p->position)++;
		}
		p->face = p->position + point(0, -1);
	}
	if (check('S')) {
		if ((mp[p->position.x][p->position.y + 1].passable) && mp.creature[p->position.x][p->position.y + 1] == 0) {
			mp.crt(p->position)--;
			p->position.y++;
			mp.crt(p->position)++;
		}
		p->face = p->position + point(0, 1);
	}
	if (check('A')) {
		if ((mp[p->position.x - 1][p->position.y].passable) && mp.creature[p->position.x - 1][p->position.y] == 0) {
			mp.crt(p->position)--;
			p->position.x--;
			mp.crt(p->position)++;
		}
		p->face = p->position + point(-1, 0);
	}
	if (check('D')) {
		if ((mp[p->position.x + 1][p->position.y].passable) && mp.creature[p->position.x + 1][p->position.y] == 0) {
			mp.crt(p->position)--;
			p->position.x++;
			mp.crt(p->position)++;
		}
		p->face = p->position + point(1, 0);
	}
}
void scene::NPCMove() {
	for (int i = 0; i < NPCs.size(); ++i) {
		if (NPCs[i]->crazyMove||(NPCs[i]->ifMove && mp[NPCs[i]->position + NPCs[i]->velocity].passable && mp.crt(NPCs[i]->position + NPCs[i]->velocity) == 0)) {
			NPCs[i]->passable ? 0 : mp.crt(NPCs[i]->position)--;
			NPCs[i]->position += NPCs[i]->velocity;
			NPCs[i]->passable ? 0 : mp.crt(NPCs[i]->position)++;
		}
	}
}
void scene::NPCDo() {
	for (int i = 0; i < NPCs.size(); ++i) {
		NPCs[i]->selfDo(p, &mp);
	}
}
void scene::playerDo() {
	if (check(' ')) {
		for (int i = 0; i < NPCs.size(); ++i) {
			if (p->face == NPCs[i]->position) {
				NPCs[i]->playerDo(p, &mp);
			}
		}
	}
}
void scene::printMap() {
	const point O(12 * 2, 6);//输出原点
	const point out(31, 21);//输出的地图尺寸

	int Y = p->position.y - out.y / 2;//处理打印地图下标区间
	int X = p->position.x - out.x / 2;
	Y + out.y >= mp.High ? Y = mp.High - out.y : 0;
	Y < 0 ? Y = 0 : 0;
	X + out.x >= mp.Long ? X = mp.Long - out.x : 0;
	X < 0 ? X = 0 : 0;

	for (int y = Y; y < Y + out.y; y++) {
		printGoto(O.x, O.y + y - Y);
		for (int x = X; x < X + out.x; x++) {
			if (mp[x][y].visible)
				printf("%s", mp[x][y].name);
			else
				printf("  ");
		}
	}

	for (int i = 0; i < NPCs.size(); ++i) {
		if (NPCs[i]->visible && Y <= NPCs[i]->position.y && NPCs[i]->position.y < Y + out.y && X <= NPCs[i]->position.x && NPCs[i]->position.x < X + out.x) {
			printGoto(O.x + 2 * (NPCs[i]->position.x - X), O.y + NPCs[i]->position.y - Y);
			printf("%s", NPCs[i]->name);
		}
	}

	printGoto(O.x + 2*(p->position.x - X), O.y + p->position.y - Y);
	printColor(12);
	printf("%s", "猫");
	printColor(7);

}
void scene::esc() {
	
	if (check(27)) {
		
			const point O(32, 10);
			const point mainSize(23, 13);
			const point say(O + point(0, mainSize.y));//(22,28)
			//有效区域x:[0,5+31+5],y:[0,5+21+5](以汉字为单位)
			{//打印屏幕边框
				//清空中心区
				rechoose:
				for (int y = O.y; y < O.y + mainSize.y; ++y) {
					printGoto(O+point(0,y-O.y));
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
				printGoto(mainSize.x + O.x - (4 + 1), O.y + 2);
				printf("游戏菜单");
				printGoto(mainSize.x + O.x - 5 - 8 - 2,O.y + 5);
				printf("->继续游戏");
				printGoto(mainSize.x + O.x - 5 + 8,O.y + 5);
				printf("我要存档");
				printGoto(mainSize.x + O.x - 5 - 8, O.y + 8);
				printf("关于作者");
				printGoto(mainSize.x + O.x - 5 + 8, O.y + 8);
				printf("存档退出");

			}
			{//用户选择
				int choose = 0;
				while (check(' ')||check(27));//防误触
				while (!check(' ')&&!check(27)) {
					if (check('W') || check('A') || check('S') || check('D')) {
						if (check('W')){
							choose+=2, choose %= 4;
						}
						else if (check('A')) {
							choose+=3, choose %= 4;
						}
						else if (check('S')) {
							choose += 2, choose %= 4;
						}
						else if (check('D')) {
							choose++, choose %= 4;
						}

						if (choose == 0) {//继续游戏
							printGoto(mainSize.x + O.x - 5 - 8 - 2, O.y + 5);
							printf("->");
							printGoto(mainSize.x + O.x - 5 + 8 - 2, O.y + 5);
							printf("  ");
							printGoto(mainSize.x + O.x - 5 - 8 - 2, O.y + 8);
							printf("  ");
							printGoto(mainSize.x + O.x - 5 + 8 - 2, O.y + 8);
							printf("  ");
						}
						else if (choose == 1) {//我要存档
							printGoto(mainSize.x + O.x - 5 - 8 - 2, O.y + 5);
							printf("  ");
							printGoto(mainSize.x + O.x - 5 + 8 - 2, O.y + 5);
							printf("->");
							printGoto(mainSize.x + O.x - 5 - 8 - 2, O.y + 8);
							printf("  ");
							printGoto(mainSize.x + O.x - 5 + 8 - 2, O.y + 8);
							printf("  ");
						}
						else if (choose == 2) {//关于作者
							printGoto(mainSize.x + O.x - 5 - 8 - 2, O.y + 5);
							printf("  ");
							printGoto(mainSize.x + O.x - 5 + 8 - 2, O.y + 5);
							printf("  ");
							printGoto(mainSize.x + O.x - 5 - 8 - 2, O.y + 8);
							printf("->");
							printGoto(mainSize.x + O.x - 5 + 8 - 2, O.y + 8);
							printf("  ");
						}
						else if (choose == 3) {//存档退出
							printGoto(mainSize.x + O.x - 5 - 8 - 2, O.y + 5);
							printf("  ");
							printGoto(mainSize.x + O.x - 5 + 8 - 2, O.y + 5);
							printf("  ");
							printGoto(mainSize.x + O.x - 5 - 8 - 2, O.y + 8);
							printf("  ");
							printGoto(mainSize.x + O.x - 5 + 8 - 2, O.y + 8);
							printf("->");
						}
						while ((check('W') || check('A') || check('S') || check('D'))) {}//松开跳出
					}
				}
				if (check(27)) {//esc again
					while (check(27));//防误触
				}
				else if (choose == 0) {//继续游戏

				}
				else if (choose == 1) {//我要存档
					saveInformation(*this, *p);
				}
				else if (choose == 2) {//关于作者
					about();
					goto rechoose;
				}
				else if (choose == 3) {//存档退出
					saveInformation(*this, *p);
					throw "exit";
				}
			}
	}
}