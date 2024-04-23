#pragma once
#include "point_C.h"

class player {
public:

	point position;//地图中具体位置。
	point face;//交互位置

	int scene;//位于某场景
	int exit; //退出变量
};
