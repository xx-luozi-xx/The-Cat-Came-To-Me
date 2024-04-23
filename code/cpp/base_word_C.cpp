#include "OOLC.h"
//新加属性要加三个位置！！！！
base_word::base_word(int num):id(num), name("  "),breakable(0), passable(1), interactive(0), visible(1) {
	switch (num) {
	case 0 :name = "  ", breakable = 0, passable = 1, interactive = 0, visible = 0; return;
	case 1 :name = "墙", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 2 :name = "门", breakable = 0, passable = 0, interactive = 1, visible = 1; return;
	case 3 :name = "門", breakable = 0, passable = 1, interactive = 0, visible = 0; return;//依托穿越判断的传送門
	case 4 :name = "砖", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 5 :name = "井", breakable = 0, passable = 0, interactive = 1, visible = 1; return;
	case 6 :name = "石", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 7 :name = "细", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 8 :name = "小", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 9 :name = "中", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 10:name = "大", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 11:name = "巨", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 12:name = "远", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 13:name = "森", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 14:name = "林", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 15:name = "木", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 16:name = "树", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 17:name = "叶", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 18:name = "枝", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 19:name = "根", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 20:name = "老", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 21:name = "山", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 22:name = "路", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 23:name = "裂", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 24:name = "缝", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 25:name = "隙", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 26:name = "窗", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 27:name = "村", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 28:name = "长", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 29:name = "之", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 30:name = "屋", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 31:name = "图", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 32:name = "书", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 33:name = "馆", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 34:name = "占", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 35:name = "星", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 36:name = "铁", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 37:name = "匠", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 38:name = "铺", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 39:name = "杂", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 40:name = "货", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 41:name = "农", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 42:name = "贸", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 43:name = "市", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 44:name = "场", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 45:name = "高", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 46:name = "台", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 47:name = "桶", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 48:name = "栅", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 49:name = "栏", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 50:name = "沙", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 51:name = "瓦", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 52:name = "房", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 53:name = "后", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 54:name = "桌", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 55:name = "椅", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 56:name = "架", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 57:name = "钟", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 58:name = "袋", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 59:name = "炉", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 60:name = "床", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 61:name = "柜", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 62:name = "一", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 63:name = "个", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 64:name = "隐", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 65:name = "藏", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 66:name = "间", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 67:name = "杯", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 68:name = "土", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 69:name = "蔷", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 70:name = "笔", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 71:name = "电", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 72:name = "脑", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 73:name = "天", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 74:name = "球", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 75:name = "日", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 76:name = "月", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 77:name = "地", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 78:name = "杆", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 79:name = "镜", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 80:name = "支", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 81:name = "目", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 82:name = "望", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 83:name = "刀", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 84:name = "钢", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 85:name = "管", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 86:name = "轮", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 87:name = "板", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 88:name = "锁", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 89:name = "子", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 90:name = "甲", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 91:name = "缸", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 92:name = "锤", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 93:name = "炭", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 94:name = "煤", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 95:name = "凿", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 96:name = "叉", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 97:name = "鞭", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 98:name = "锏", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 99:name = "戈", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 100:name = "镋", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 101:name = "槊", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 102:name = "矛", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 103:name = "钩", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 104:name = "钺", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 105:name = "斧", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 106:name = "戟", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 107:name = "剑", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 108:name = "枪", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 109:name = "仓", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 110:name = "破", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 111:name = "库", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 112:name = "网", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 113:name = "蜘", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 114:name = "蛛", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 115:name = "酒", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 116:name = "烟", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 117:name = "凳", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 118:name = "摊", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 119:name = "筐", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 120:name = "扁", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 121:name = "担", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 122:name = "菜", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 123:name = "肉", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 124:name = "砧", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 125:name = "瓜", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 126:name = "盘", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 127:name = "平", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 128:name = "公", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 129:name = "秤", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 130:name = "冰", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 131:name = "鱼", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 132:name = "螺", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 133:name = "葡", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 134:name = "萄", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 135:name = "榴", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 136:name = "莲", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 137:name = "苹", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 138:name = "果", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 139:name = "蛋", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 140:name = "鸡", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 141:name = "鸭", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 142:name = "鹅", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 143:name = "蛇", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 144:name = "黄", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 145:name = "西", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 146:name = "冬", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 147:name = "南", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 148:name = "健", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 149:name = "康", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 150:name = "码", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 151:name =  "■", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 152:name = "碎", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 153:name = "窟", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 154:name = "草", breakable = 0, passable = 1, interactive = 0, visible = 1; return;
	case 155:name = "水", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 156:name = "池", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 157:name = "断", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 158:name = "崖", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 159:name = "径", breakable = 0, passable = 1, interactive = 0, visible = 1; return;
	case 160:name = "火", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 161:name = "炬", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 162:name = "柱", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 163:name = "块", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 164:name = "尖", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 165:name = "刺", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 166:name = "背", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 167:name = "布", breakable = 0, passable = 1, interactive = 0, visible = 1; return;
	case 168:name = "红", breakable = 0, passable = 1, interactive = 0, visible = 1; return;
	case 169:name = "金", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 170:name = "田", breakable = 0, passable = 1, interactive = 0, visible = 1; return;
	case 171:name = "麦", breakable = 0, passable = 1, interactive = 0, visible = 1; return;
	case 172:name = "薯", breakable = 0, passable = 1, interactive = 0, visible = 1; return;
	case 173:name = "围", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 174:name = "花", breakable = 0, passable = 1, interactive = 0, visible = 1; return;
	case 175:name = "龙", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 176:name = "粮", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 177:name = "棚", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 178:name = "牌", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 179:name = "萝", breakable = 0, passable = 1, interactive = 0, visible = 1; return;
	case 180:name = "卜", breakable = 0, passable = 1, interactive = 0, visible = 1; return; 
	case 181:name = "窝", breakable = 0, passable = 1, interactive = 0, visible = 1; return;
	case 182:name = "枯", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 183:name = "白", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 184:name = "篝", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 185:name = "桩", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 186:name = "屑", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 187:name = "倒", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 188:name = "下", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 189:name = "的", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 190:name = "垃", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 191:name = "圾", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 192:name = "顶", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 193:name = "囱", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 194:name = "凉", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 195:name = "帐", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 196:name = "篷", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 197:name = "画", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 198:name = "锅", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 199:name = "瓶", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 200:name = "疣", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 201:name = "魂", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 202:name = "灵", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 203:name = "狱", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 204:name = "奇", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 205:name = "怪", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 206:name = "药", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 207:name = "品", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 208:name = "炼", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 209:name = "沝", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 210:name = "淼", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 211:name = "洋", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 212:name = "壁", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 213:name = "锈", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 214:name = "藻", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 215:name = "贝", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 216:name = "辟", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 217:name = "底", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 218:name = "氏", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 219:name = "壳", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 220:name = "啬", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 221:name = "旗", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 222:name = "洞", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 223:name = "锚", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 224:name = "磊", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 225:name = "扇", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 226:name = "蟹", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 227:name = "伞", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 228:name = "堡", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 229:name = "坑", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 230:name = "董", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 231:name = "椰", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 232:name = "礁", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 233:name = "学", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 234:name = "琦", breakable = 0, passable = 0, interactive = 0, visible = 1; return;
	case 235:name = "徒", breakable = 0, passable = 0, interactive = 0, visible = 1; return;


	}
}
void swap(base_word& lhs, base_word& rhs) {
	using namespace std;
	swap(lhs.name, rhs.name);
	swap(lhs.id, rhs.id);
	swap(lhs.breakable, rhs.breakable);
	swap(lhs.interactive, rhs.interactive);
	swap(lhs.passable, rhs.passable);
	swap(lhs.visible, rhs.visible);
}
base_word& base_word::operator=(int num) {
	base_word temp(num);
	swap(*this, temp);
	return *this;
}
base_word::operator int() {
	return id;
}