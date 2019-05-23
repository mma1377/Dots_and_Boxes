#pragma once
#include "Boxes_List.h"

class Game_Data {
private:
	int n;
	Boxes_List* _boxes_list;
	bool** vertical_lines;
	bool** horizontal_lines;
	int score;
public:
	Game_Data(int _n);
	int Select_Line(bool direction, int x, int y); /* if direction == false means vertical
	and true means horizontal.
	if return result == 0 then no score
	if return == 1 then score right
	if return == 2 then score left
	if return == 3 then score both
	*/
	
	void Copy_Structure(bool**&, bool**&, Boxes_List*&);
	
	int Start_Abstract_Game(int levels, bool&, int&, int&);
	
	int Play_func_Bot(bool direction, int x, int y, int levels, bool**, bool**, Boxes_List*, bool is_bot_turn, int levels_max, bool require_chain_func); 
	// if direction == false means vertical and true means horizontal
	
	int Play_func_Bot_Chain_Boxes(bool direction, int x, int y, int levels, bool**, bool**, Boxes_List*, bool is_bot_turn);
};