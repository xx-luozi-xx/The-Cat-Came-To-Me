#include "OOLC.h"
#include <string>
namespace tiejiangpu_NPC {
    class shi : public NPC {
    public:
        int age;
        point begin;
        point end;
        shi(const point& pos) :NPC(1, pos, { 0,1 }), begin(pos), end(pos + point(0, 12)), age(0) { name = "师"; }
        virtual void playerDo(player* p, Map* m) {
            say("师：让我看看是谁在进行面向CSDN的编程！");
            sayyes();
            sayclear();
        }
        virtual void selfDo(player* p, Map* m) {
            age++, age %= 50;
            if (age <= 6) {
                ifMove = 1;
            }
            else {
                ifMove = 0;
            }
            if (position == begin) {
                velocity = point(0, 1);
            }
            else if (position == end) {
                velocity = point(0, -1);
            }
        }
        virtual ~shi() {}
    };
    class ke : public NPC {
    public:
        int age;
        const char* s;
        point begin;
        point end;
        ke(const point& pos, const char* s, int age) :NPC(1, pos, { 0,1 }), begin(pos), end(pos + point(0, 12)),age(age) , s(s) { name = "客"; }
        virtual void playerDo(player* p, Map* m) {
            using namespace std;
            say((string("客：")+s).c_str());
            sayyes();
            sayclear();
        }
        virtual void selfDo(player* p, Map* m) {
            age++, age %= 30;
            if (age <= 2) {
                ifMove = 1;
            }
            else {
                ifMove = 0;
            }
            if (position == begin) {
                velocity = point(0, 1);
            }
            else if (position == end) {
                velocity = point(0, -1);
            }
        }
        virtual ~ke() {}
    };
}

static void sceneReady(scene& scn, player& p);
static void sceneEnd(scene& scn);
void tiejiangpu(player& p) {
	scene tiejiangpu;
	sceneReady(tiejiangpu, p);
	tiejiangpu.gameStart();
    //动画
    try {
        while (1) {
            tiejiangpu.printMap();
 
            tiejiangpu.playerDo();//其他按键功能
            tiejiangpu.NPCDo();
            tiejiangpu.playerMove();
            tiejiangpu.NPCMove();
            tiejiangpu.esc();

            Sleep(50);
        }
    }
    catch (int) {//换地图，地图文件存档

    }
    catch (const char*) {//退出
        p.exit = 1;
    }
    sceneEnd(tiejiangpu);
}

static void sceneReady(scene& scn, player& p) {
    using namespace tiejiangpu_NPC;
	//玩家
    scn.p = &p;
    //地图
    scn.mp.High = 21, scn.mp.Long = 31;
    {
        Map& m = scn.mp;
            m[0][0] = 1, m[1][0] = 1, m[2][0] = 1, m[3][0] = 1, m[4][0] = 1, m[5][0] = 1, m[6][0] = 1, m[7][0] = 1, m[8][0] = 1, m[9][0] = 1, m[10][0] = 1, m[11][0] = 1, m[12][0] = 1, m[13][0] = 1, m[14][0] = 1, m[15][0] = 1, m[16][0] = 1, m[17][0] = 1, m[18][0] = 1, m[19][0] = 1, m[20][0] = 1, m[21][0] = 1, m[22][0] = 1, m[23][0] = 1, m[24][0] = 1, m[25][0] = 1, m[26][0] = 1, m[27][0] = 1, m[28][0] = 1, m[29][0] = 1, m[30][0] = 1;
        m[0][1] = 1, m[1][1] = 0, m[2][1] = 0, m[3][1] = 0, m[4][1] = 0, m[5][1] = 0, m[6][1] = 83, m[7][1] = 91, m[8][1] = 1, m[9][1] = 0, m[10][1] = 0, m[11][1] = 0, m[12][1] = 0, m[13][1] = 0, m[14][1] = 0, m[15][1] = 0, m[16][1] = 0, m[17][1] = 0, m[18][1] = 0, m[19][1] = 0, m[20][1] = 0, m[21][1] = 0, m[22][1] = 0, m[23][1] = 0, m[24][1] = 0, m[25][1] = 0, m[26][1] = 0, m[27][1] = 0, m[28][1] = 0, m[29][1] = 0, m[30][1] = 1;
        m[0][2] = 1, m[1][2] = 59, m[2][2] = 59, m[3][2] = 233, m[4][2] = 0, m[5][2] = 0, m[6][2] = 91, m[7][2] = 91, m[8][2] = 1, m[9][2] = 0, m[10][2] = 0, m[11][2] = 84, m[12][2] = 85, m[13][2] = 84, m[14][2] = 85, m[15][2] = 84, m[16][2] = 0, m[17][2] = 0, m[18][2] = 0, m[19][2] = 0, m[20][2] = 0, m[21][2] = 0, m[22][2] = 0, m[23][2] = 0, m[24][2] = 0, m[25][2] = 0, m[26][2] = 0, m[27][2] = 0, m[28][2] = 0, m[29][2] = 0, m[30][2] = 1;
        m[0][3] = 1, m[1][3] = 59, m[2][3] = 59, m[3][3] = 235, m[4][3] = 0, m[5][3] = 0, m[6][3] = 56, m[7][3] = 56, m[8][3] = 1, m[9][3] = 0, m[10][3] = 0, m[11][3] = 0, m[12][3] = 0, m[13][3] = 0, m[14][3] = 84, m[15][3] = 87, m[16][3] = 0, m[17][3] = 0, m[18][3] = 0, m[19][3] = 0, m[20][3] = 56, m[21][3] = 56, m[22][3] = 0, m[23][3] = 0, m[24][3] = 0, m[25][3] = 0, m[26][3] = 56, m[27][3] = 56, m[28][3] = 0, m[29][3] = 0, m[30][3] = 1;
        m[0][4] = 1, m[1][4] = 0, m[2][4] = 0, m[3][4] = 0, m[4][4] = 0, m[5][4] = 0, m[6][4] = 56, m[7][4] = 56, m[8][4] = 1, m[9][4] = 0, m[10][4] = 0, m[11][4] = 0, m[12][4] = 84, m[13][4] = 87, m[14][4] = 84, m[15][4] = 87, m[16][4] = 84, m[17][4] = 0, m[18][4] = 0, m[19][4] = 0, m[20][4] = 56, m[21][4] = 96, m[22][4] = 0, m[23][4] = 0, m[24][4] = 0, m[25][4] = 0, m[26][4] = 103, m[27][4] = 56, m[28][4] = 0, m[29][4] = 0, m[30][4] = 1;
        m[0][5] = 1, m[1][5] = 0, m[2][5] = 0, m[3][5] = 0, m[4][5] = 0, m[5][5] = 0, m[6][5] = 92, m[7][5] = 56, m[8][5] = 1, m[9][5] = 0, m[10][5] = 0, m[11][5] = 0, m[12][5] = 86, m[13][5] = 86, m[14][5] = 86, m[15][5] = 86, m[16][5] = 86, m[17][5] = 0, m[18][5] = 0, m[19][5] = 0, m[20][5] = 56, m[21][5] = 56, m[22][5] = 0, m[23][5] = 0, m[24][5] = 0, m[25][5] = 0, m[26][5] = 56, m[27][5] = 56, m[28][5] = 0, m[29][5] = 0, m[30][5] = 1;
        m[0][6] = 1, m[1][6] = 59, m[2][6] = 59, m[3][6] = 233, m[4][6] = 0, m[5][6] = 0, m[6][6] = 83, m[7][6] = 91, m[8][6] = 1, m[9][6] = 0, m[10][6] = 0, m[11][6] = 0, m[12][6] = 0, m[13][6] = 0, m[14][6] = 0, m[15][6] = 0, m[16][6] = 0, m[17][6] = 0, m[18][6] = 0, m[19][6] = 0, m[20][6] = 56, m[21][6] = 97, m[22][6] = 0, m[23][6] = 0, m[24][6] = 0, m[25][6] = 0, m[26][6] = 104, m[27][6] = 56, m[28][6] = 0, m[29][6] = 0, m[30][6] = 1;
        m[0][7] = 1, m[1][7] = 59, m[2][7] = 59, m[3][7] = 235, m[4][7] = 0, m[5][7] = 0, m[6][7] = 91, m[7][7] = 91, m[8][7] = 1, m[9][7] = 0, m[10][7] = 0, m[11][7] = 0, m[12][7] = 0, m[13][7] = 0, m[14][7] = 0, m[15][7] = 0, m[16][7] = 0, m[17][7] = 0, m[18][7] = 0, m[19][7] = 0, m[20][7] = 56, m[21][7] = 56, m[22][7] = 0, m[23][7] = 0, m[24][7] = 0, m[25][7] = 0, m[26][7] = 56, m[27][7] = 56, m[28][7] = 0, m[29][7] = 0, m[30][7] = 1;
        m[0][8] = 1, m[1][8] = 0, m[2][8] = 0, m[3][8] = 0, m[4][8] = 0, m[5][8] = 0, m[6][8] = 56, m[7][8] = 56, m[8][8] = 1, m[9][8] = 0, m[10][8] = 0, m[11][8] = 56, m[12][8] = 56, m[13][8] = 56, m[14][8] = 56, m[15][8] = 56, m[16][8] = 56, m[17][8] = 56, m[18][8] = 0, m[19][8] = 0, m[20][8] = 56, m[21][8] = 98, m[22][8] = 0, m[23][8] = 0, m[24][8] = 0, m[25][8] = 0, m[26][8] = 105, m[27][8] = 56, m[28][8] = 0, m[29][8] = 0, m[30][8] = 1;
        m[0][9] = 1, m[1][9] = 94, m[2][9] = 93, m[3][9] = 0, m[4][9] = 0, m[5][9] = 0, m[6][9] = 56, m[7][9] = 56, m[8][9] = 1, m[9][9] = 0, m[10][9] = 0, m[11][9] = 56, m[12][9] = 56, m[13][9] = 88, m[14][9] = 89, m[15][9] = 90, m[16][9] = 56, m[17][9] = 56, m[18][9] = 0, m[19][9] = 0, m[20][9] = 56, m[21][9] = 56, m[22][9] = 0, m[23][9] = 0, m[24][9] = 0, m[25][9] = 0, m[26][9] = 56, m[27][9] = 56, m[28][9] = 0, m[29][9] = 0, m[30][9] = 1;
        m[0][10] = 1, m[1][10] = 93, m[2][10] = 94, m[3][10] = 0, m[4][10] = 0, m[5][10] = 0, m[6][10] = 92, m[7][10] = 56, m[8][10] = 1, m[9][10] = 0, m[10][10] = 0, m[11][10] = 0, m[12][10] = 0, m[13][10] = 0, m[14][10] = 0, m[15][10] = 0, m[16][10] = 0, m[17][10] = 0, m[18][10] = 0, m[19][10] = 0, m[20][10] = 56, m[21][10] = 99, m[22][10] = 0, m[23][10] = 0, m[24][10] = 0, m[25][10] = 0, m[26][10] = 106, m[27][10] = 56, m[28][10] = 0, m[29][10] = 0, m[30][10] = 1;
        m[0][11] = 1, m[1][11] = 94, m[2][11] = 93, m[3][11] = 0, m[4][11] = 0, m[5][11] = 0, m[6][11] = 92, m[7][11] = 56, m[8][11] = 1, m[9][11] = 0, m[10][11] = 0, m[11][11] = 0, m[12][11] = 0, m[13][11] = 0, m[14][11] = 0, m[15][11] = 0, m[16][11] = 0, m[17][11] = 0, m[18][11] = 0, m[19][11] = 0, m[20][11] = 56, m[21][11] = 56, m[22][11] = 0, m[23][11] = 0, m[24][11] = 0, m[25][11] = 0, m[26][11] = 56, m[27][11] = 56, m[28][11] = 0, m[29][11] = 0, m[30][11] = 1;
        m[0][12] = 1, m[1][12] = 0, m[2][12] = 0, m[3][12] = 0, m[4][12] = 0, m[5][12] = 0, m[6][12] = 56, m[7][12] = 56, m[8][12] = 1, m[9][12] = 0, m[10][12] = 0, m[11][12] = 56, m[12][12] = 56, m[13][12] = 56, m[14][12] = 56, m[15][12] = 56, m[16][12] = 56, m[17][12] = 56, m[18][12] = 0, m[19][12] = 0, m[20][12] = 56, m[21][12] = 100, m[22][12] = 0, m[23][12] = 0, m[24][12] = 0, m[25][12] = 0, m[26][12] = 107, m[27][12] = 56, m[28][12] = 0, m[29][12] = 0, m[30][12] = 1;
        m[0][13] = 1, m[1][13] = 59, m[2][13] = 59, m[3][13] = 233, m[4][13] = 0, m[5][13] = 0, m[6][13] = 91, m[7][13] = 91, m[8][13] = 1, m[9][13] = 0, m[10][13] = 0, m[11][13] = 56, m[12][13] = 87, m[13][13] = 90, m[14][13] = 56, m[15][13] = 36, m[16][13] = 90, m[17][13] = 56, m[18][13] = 0, m[19][13] = 0, m[20][13] = 56, m[21][13] = 56, m[22][13] = 0, m[23][13] = 0, m[24][13] = 0, m[25][13] = 0, m[26][13] = 56, m[27][13] = 56, m[28][13] = 0, m[29][13] = 0, m[30][13] = 1;
        m[0][14] = 1, m[1][14] = 59, m[2][14] = 59, m[3][14] = 235, m[4][14] = 0, m[5][14] = 0, m[6][14] = 107, m[7][14] = 91, m[8][14] = 1, m[9][14] = 0, m[10][14] = 0, m[11][14] = 0, m[12][14] = 0, m[13][14] = 0, m[14][14] = 0, m[15][14] = 0, m[16][14] = 0, m[17][14] = 0, m[18][14] = 0, m[19][14] = 0, m[20][14] = 56, m[21][14] = 101, m[22][14] = 0, m[23][14] = 0, m[24][14] = 0, m[25][14] = 0, m[26][14] = 108, m[27][14] = 56, m[28][14] = 0, m[29][14] = 0, m[30][14] = 1;
        m[0][15] = 1, m[1][15] = 0, m[2][15] = 0, m[3][15] = 0, m[4][15] = 0, m[5][15] = 0, m[6][15] = 56, m[7][15] = 56, m[8][15] = 1, m[9][15] = 0, m[10][15] = 0, m[11][15] = 0, m[12][15] = 0, m[13][15] = 0, m[14][15] = 0, m[15][15] = 0, m[16][15] = 0, m[17][15] = 0, m[18][15] = 0, m[19][15] = 0, m[20][15] = 56, m[21][15] = 56, m[22][15] = 0, m[23][15] = 0, m[24][15] = 0, m[25][15] = 0, m[26][15] = 56, m[27][15] = 56, m[28][15] = 0, m[29][15] = 0, m[30][15] = 1;
        m[0][16] = 1, m[1][16] = 0, m[2][16] = 0, m[3][16] = 0, m[4][16] = 0, m[5][16] = 0, m[6][16] = 56, m[7][16] = 56, m[8][16] = 1, m[9][16] = 0, m[10][16] = 0, m[11][16] = 56, m[12][16] = 56, m[13][16] = 56, m[14][16] = 56, m[15][16] = 56, m[16][16] = 56, m[17][16] = 56, m[18][16] = 0, m[19][16] = 0, m[20][16] = 56, m[21][16] = 102, m[22][16] = 0, m[23][16] = 0, m[24][16] = 0, m[25][16] = 0, m[26][16] = 83, m[27][16] = 56, m[28][16] = 0, m[29][16] = 0, m[30][16] = 1;
        m[0][17] = 1, m[1][17] = 0, m[2][17] = 0, m[3][17] = 0, m[4][17] = 0, m[5][17] = 0, m[6][17] = 56, m[7][17] = 56, m[8][17] = 1, m[9][17] = 0, m[10][17] = 0, m[11][17] = 56, m[12][17] = 36, m[13][17] = 92, m[14][17] = 56, m[15][17] = 36, m[16][17] = 95, m[17][17] = 56, m[18][17] = 0, m[19][17] = 0, m[20][17] = 56, m[21][17] = 56, m[22][17] = 0, m[23][17] = 0, m[24][17] = 0, m[25][17] = 0, m[26][17] = 56, m[27][17] = 56, m[28][17] = 0, m[29][17] = 0, m[30][17] = 1;
        m[0][18] = 1, m[1][18] = 0, m[2][18] = 0, m[3][18] = 0, m[4][18] = 0, m[5][18] = 0, m[6][18] = 0, m[7][18] = 0, m[8][18] = 0, m[9][18] = 0, m[10][18] = 0, m[11][18] = 0, m[12][18] = 0, m[13][18] = 0, m[14][18] = 0, m[15][18] = 0, m[16][18] = 0, m[17][18] = 0, m[18][18] = 0, m[19][18] = 0, m[20][18] = 0, m[21][18] = 0, m[22][18] = 0, m[23][18] = 0, m[24][18] = 0, m[25][18] = 0, m[26][18] = 0, m[27][18] = 0, m[28][18] = 0, m[29][18] = 0, m[30][18] = 1;
        m[0][19] = 1, m[1][19] = 0, m[2][19] = 0, m[3][19] = 0, m[4][19] = 0, m[5][19] = 0, m[6][19] = 0, m[7][19] = 0, m[8][19] = 0, m[9][19] = 0, m[10][19] = 0, m[11][19] = 0, m[12][19] = 0, m[13][19] = 0, m[14][19] = 0, m[15][19] = 0, m[16][19] = 0, m[17][19] = 0, m[18][19] = 0, m[19][19] = 0, m[20][19] = 0, m[21][19] = 0, m[22][19] = 0, m[23][19] = 0, m[24][19] = 0, m[25][19] = 0, m[26][19] = 0, m[27][19] = 0, m[28][19] = 0, m[29][19] = 0, m[30][19] = 1;
        m[0][20] = 1, m[1][20] = 1, m[2][20] = 1, m[3][20] = 1, m[4][20] = 1, m[5][20] = 1, m[6][20] = 1, m[7][20] = 1, m[8][20] = 1, m[9][20] = 1, m[10][20] = 1, m[11][20] = 1, m[12][20] = 1, m[13][20] = 1, m[14][20] = 1, m[15][20] = 1, m[16][20] = 1, m[17][20] = 1, m[18][20] = 1, m[19][20] = 1, m[20][20] = 1, m[21][20] = 1, m[22][20] = 1, m[23][20] = 2, m[24][20] = 2, m[25][20] = 1, m[26][20] = 1, m[27][20] = 1, m[28][20] = 1, m[29][20] = 1, m[30][20] = 1;
    }
    {//地图传送門设置
        scn.NPCs.push_back(new door({ 23, 20 }, { 141, 85 }, 0));//world
        scn.NPCs.push_back(new door({ 24, 20 }, { 142, 85 }, 0));
    }
    {
        for (int i = 0; i < 31; i++)
            for (int j = 0; j < 21; j++)
            {
                if (scn.mp[i][j].id == 56) { scn.NPCs.push_back(new tell({ i,j }, "一个普通的架子。")); }//架
                if (scn.mp[i][j].id == 84 || scn.mp[i][j].id == 85 || scn.mp[i][j].id == 86 || scn.mp[i][j].id == 87) { scn.NPCs.push_back(new tell({ i,j }, "一种奇怪的，有着五对轮子的钢铁造物。")); }//坦克
                if (scn.mp[i][j].id == 83 || scn.mp[i][j].id == 92 || scn.mp[i][j].id == 107 || scn.mp[i][j].id == 88 || scn.mp[i][j].id == 89 || (i == 15 && j == 9) || (i == 16 && j == 13) || (i == 13 && j == 13) || scn.mp[i][j].id == 87 || scn.mp[i][j].id == 36 || scn.mp[i][j].id == 95 || (scn.mp[i][j].id >= 96 && scn.mp[i][j].id <= 108)) { scn.NPCs.push_back(new tell({ i,j }, "一些奇怪的铁疙瘩。")); }//
                if (scn.mp[i][j].id == 90) { scn.NPCs.push_back(new tell({ i,j }, "一个装满了水的水缸。")); }//缸
                if (scn.mp[i][j].id == 59) { scn.NPCs.push_back(new tell({ i,j }, "一个熊熊燃烧的火炉，好烫，还是离远点好了。")); }//炉
                if (scn.mp[i][j].id == 93 || scn.mp[i][j].id == 94) { scn.NPCs.push_back(new tell({ i,j }, "一种黑乎乎的方块。")); }//煤炭
                if (scn.mp[i][j].id == 233 || scn.mp[i][j].id == 235) { scn.NPCs.push_back(new tell({ i,j }, "正在对铁炉上的铁疙瘩敲敲打打。")); }//煤炭

            }
        scn.NPCs.push_back(new shi({4,2})); //炉
        scn.NPCs.push_back(new ke({ 23,4 },"嗯，挺锋利的，针不戳",0)); //炉
        scn.NPCs.push_back(new tell("客",{ 14, 11 }, "嚯嚯嚯……")); //炉
        scn.NPCs.push_back(new ke({ 24,4 }, "好武器！",20)); //炉

    }
}
static void sceneEnd(scene& scn) {
    while (!scn.NPCs.empty()) {
        delete scn.NPCs.back();
        scn.NPCs.pop_back();
    }
}