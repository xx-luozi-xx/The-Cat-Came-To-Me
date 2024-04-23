#include "OOLC.h"
#include <windows.h>

int main() {
	//init windows cmd 
 	SetConsoleOutputCP(CP_UTF8);

	while (1) {
		player luozi;

		if (gameStart(luozi)) { break; }; //初始页面-标题信息，继续游戏，新建存档，退出游戏。

		while (!luozi.exit) {
			if (luozi.scene == 0) { world(luozi); }
			if (luozi.scene == 1) { shatan(luozi); }
			if (luozi.scene == 2) { suidao(luozi); }
			if (luozi.scene == 3) { senlin(luozi); }
			if (luozi.scene == 4) { nongchang(luozi); }
			if (luozi.scene == 5) { chunzhang(luozi); }
			if (luozi.scene == 6) { tushuguan(luozi); }
			if (luozi.scene == 7) { zhanxingwu(luozi); }
			if (luozi.scene == 8) { tiejiangpu(luozi); }
			if (luozi.scene == 9) { zahuopu(luozi); }
			if (luozi.scene == 10) { nongmaoshichang(luozi); }
			if (luozi.scene == 11) { baihuagu(luozi); }
			if (luozi.scene == 12) { senlinfangjian(luozi); }
		}
	}
	fflush(stdin);
	return 0;
}
/*

物品基类
背包（物品列表）

种地（记录游戏刻），
经验升级

剧情与存档

*/
