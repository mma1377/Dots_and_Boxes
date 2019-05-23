#pragma once
#include "Box_Node.h"

class Boxes_List {
	friend class Game_Data;
private:
	int n;
	Box_Node** Boxes_Data;
public:
	Boxes_List(int _n);
	Boxes_List(Boxes_List&);
};