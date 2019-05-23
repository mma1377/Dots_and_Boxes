#pragma once

class Box_Node {
	friend class Boxes_List;
	friend class Game_Data;
private:
	int x, y;
	int numbers_of_adjacency_nodes;
public:
	Box_Node();
};