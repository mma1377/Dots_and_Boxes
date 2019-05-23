#include "Game_Data.h"

#ifndef NULL
#define NULL 0
#endif

#ifndef INT_MIN
#define INT_MIN -2147483648
#endif

#ifndef INT_MAX
#define INT_MAX +2147483647
#endif


Game_Data::Game_Data(int _n)
{
	n = _n;
	_boxes_list = new Boxes_List(n);
	score = 0;
	vertical_lines = new bool*[n + 1];
	horizontal_lines = new bool*[n];
	for (int i = 0; i < n; i++) {
		horizontal_lines[i] = new bool[n + 1];
		for (int j = 0; j < n + 1; j++)
			horizontal_lines[i][j] = false;
	}
	for (int i = 0; i < n + 1; i++) {
		vertical_lines[i] = new bool[n];
		for (int j = 0; j < n; j++)
			vertical_lines[i][j] = false;
	}
}

int Game_Data::Select_Line(bool direction, int x, int y)
{
	int gain_score = 0; // if gain score doesnt change, it means player who selected line 
	// will not gain any score 

	if (direction == 0) { // line is vertical
		if (x > 0 && x < n) {
			_boxes_list->Boxes_Data[x - 1][y].numbers_of_adjacency_nodes--;
		}
		if (x < n && x > 0) {
			_boxes_list->Boxes_Data[x][y].numbers_of_adjacency_nodes--;
		}
		vertical_lines[x][y] = true;
		if (x < n && y < n + 1 &&
			horizontal_lines[x][y] == true &&
			horizontal_lines[x][y + 1] == true &&
			vertical_lines[x + 1][y] == true) { //right box is filled
			gain_score = 1; 
		}
		if (x > 0 && y < n + 1 &&
			horizontal_lines[x - 1][y] == true &&
			horizontal_lines[x - 1][y + 1] == true &&
			vertical_lines[x - 1][y] == true) { //left box is filled
			if (gain_score == 0) {
				gain_score = 2; //just left box is filled
			}
			else
				gain_score = 3; //both left and right boxes are filled
		}
	}
	else { //line is horizontal
		horizontal_lines[x][y] = true;
		if (y > 0 && y < n) {
			_boxes_list->Boxes_Data[x][y - 1].numbers_of_adjacency_nodes--;
		}
		if (y < n && y > 0) {
			_boxes_list->Boxes_Data[x][y].numbers_of_adjacency_nodes--;
		}
		if (y < n && x < n + 1 &&
			vertical_lines[x][y] == true &&
			vertical_lines[x + 1][y] == true &&
			horizontal_lines[x][y + 1] == true) { //the box abow is filled
			gain_score = 1;
		}
		if (y > 0 && x < n + 1 &&
			vertical_lines[x][y - 1] == true &&
			vertical_lines[x + 1][y - 1] == true &&
			horizontal_lines[x][y - 1] == true) { //the box below is filled
			if (gain_score == 0) {
				gain_score = 2; //just the box below it filled
			}
			else
				gain_score = 3; //both boxes are filled
		}
	}
	
	return gain_score; //return result to alter ui
}

void Game_Data::Copy_Structure(bool **& vertical_lines_copied, bool **& horizontal_lines_copied, Boxes_List *& _boxes_list_copied)
{
	vertical_lines_copied = new bool*[n + 1];
	horizontal_lines_copied = new bool*[n];
	for (int i = 0; i < n + 1; i++) {
		vertical_lines_copied[i] = new bool[n];
		for (int j = 0; j < n; j++) {
			vertical_lines_copied[i][j] = vertical_lines[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		horizontal_lines_copied[i] = new bool[n + 1];
		for (int j = 0; j < n + 1; j++) {
			horizontal_lines_copied[i][j] = horizontal_lines[i][j];
		}
	}
	_boxes_list_copied = new Boxes_List(*_boxes_list);
}

int Game_Data::Start_Abstract_Game(int levels, bool& max_direction,int& x_max,int& y_max)
{
	bool ** vertical_lines_copied;
	bool ** horizontal_lines_copied;
	Boxes_List* _boxes_list_copied;

	int max = INT_MIN;
	x_max = -1;
	y_max = -1;

	Copy_Structure(vertical_lines_copied, horizontal_lines_copied, _boxes_list_copied);
	//copy from game data to use in abstract game and to avoid changing main game data

	////nested loops below determine maximum score algorithm can get as result of selecting each 
	//possible available line hence algorithm can make the best possible decision

	for (int i = 0; i < n + 1; i++) {
		for (int j = 0; j < n; j++) {
			if (!vertical_lines_copied[i][j]) {
				int ret_val = Play_func_Bot(0, i, j, levels - 1, vertical_lines_copied, horizontal_lines_copied, _boxes_list_copied , true, levels - 1, false);
				
				if (ret_val > max) {
					max = ret_val;
					x_max = i;
					y_max = j;
					max_direction = 0;
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n + 1; j++) {
			if (!horizontal_lines_copied[i][j]) {
				int ret_val = Play_func_Bot(1, i, j, levels - 1, vertical_lines_copied, horizontal_lines_copied, _boxes_list_copied , true, levels - 1, false);
				
				if (ret_val > max) {
					max = ret_val;
					x_max = i;
					y_max = j;
					max_direction = 1;
				}
			}
		}
	}
	
	//if all the possible choices in constant number of levels cause negetive points, the algorithm 
	//will be required to call chain function to determine the least amount of score that opponent 
	//can get based on algorithm's decision
	if (max < 0) {
		max = INT_MIN;
		
		for (int i = 0; i < n + 1; i++) {
			for (int j = 0; j < n; j++) {
				if (!vertical_lines_copied[i][j]) {
					int ret_val = Play_func_Bot(0, i, j, levels - 1, vertical_lines_copied, horizontal_lines_copied, _boxes_list_copied, true, levels - 1 , true);
					
					if (ret_val > max) {
						max = ret_val;
						x_max = i;
						y_max = j;
						max_direction = 0;
					}
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n + 1; j++) {
				if (!horizontal_lines_copied[i][j]) {
					int ret_val = Play_func_Bot(1, i, j, levels - 1, vertical_lines_copied, horizontal_lines_copied, _boxes_list_copied, true, levels - 1, true);
					
					if (ret_val > max) {
						max = ret_val;
						x_max = i;
						y_max = j;
						max_direction = 1;
						
					}
				}
			}
		}

	}

	delete[] _boxes_list_copied->Boxes_Data;
	delete[] vertical_lines_copied;
	delete[] horizontal_lines_copied;
	
	if (x_max == -1) //if the game is finished
		return -1;
	
	return Select_Line(max_direction, x_max, y_max); //Choose the best choice in main game and return result to UI
}

int Game_Data::Play_func_Bot(bool direction, int x, int y, int levels, bool ** vertical_lines_copied, bool ** horizontal_lines_copied, Boxes_List* _boxes_list_copied, bool is_bot_turn, int max_levels, bool require_chain_func)
{
	
	int gain_score = 0;
	if (direction == 0) {
		if (x > 0 && x < n) {
			_boxes_list_copied->Boxes_Data[x - 1][y].numbers_of_adjacency_nodes--;
		}
		if (x < n && x > 0) {
			_boxes_list_copied->Boxes_Data[x][y].numbers_of_adjacency_nodes--;
		}
		
		vertical_lines_copied[x][y] = true; //select the line in abstract game data
		if (x < n && y < n + 1 &&
			horizontal_lines_copied[x][y] == true &&
			horizontal_lines_copied[x][y + 1] == true &&
			vertical_lines_copied[x + 1][y] == true) {
			if (is_bot_turn)
				gain_score++;
			else
				gain_score--;
		}
		if (x > 0 && y < n + 1 &&
			horizontal_lines_copied[x - 1][y] == true &&
			horizontal_lines_copied[x - 1][y + 1] == true &&
			vertical_lines_copied[x - 1][y] == true) {
			if (is_bot_turn)
				gain_score++;
			else
				gain_score--;
		}
	}
	else {
		horizontal_lines_copied[x][y] = true; //select the line in abstract game data
		if (y > 0 && y < n) {
			_boxes_list_copied->Boxes_Data[x][y - 1].numbers_of_adjacency_nodes--;
		}
		if (y < n && y > 0) {
			_boxes_list_copied->Boxes_Data[x][y].numbers_of_adjacency_nodes--;
		}
		
		if (y < n && x < n + 1 &&
			vertical_lines_copied[x][y] == true &&
			vertical_lines_copied[x + 1][y] == true &&
			horizontal_lines_copied[x][y + 1] == true) {
			if (is_bot_turn)
				gain_score++;
			else
				gain_score--;
		}
		if (y > 0 && x < n + 1 &&
			vertical_lines_copied[x][y - 1] == true &&
			vertical_lines_copied[x + 1][y - 1] == true &&
			horizontal_lines_copied[x][y - 1] == true) {
			if (is_bot_turn)
				gain_score++;
			else
				gain_score--;
		}
	}

	if (gain_score != 0) { //change turn in abstract game tree
		is_bot_turn = !is_bot_turn;
	}

	int max = INT_MIN; //if next turn is bot's turn, it will maximize bot's choice
	if (is_bot_turn)
		max = INT_MAX; //if it is bot turn, it will minimize user's choice by finding minimum
	int y_max = -1;
	int x_max = -1;
	bool max_direction;

	if (levels > 1) {
		for (int i = 0; i < n + 1; i++) {
			for (int j = 0; j < n; j++) {
				if (!vertical_lines_copied[i][j]) {
					
					int ret_val = Play_func_Bot(0, i, j, levels - 1, vertical_lines_copied, horizontal_lines_copied, _boxes_list_copied, !is_bot_turn, max_levels, !require_chain_func);
					
					if ((!is_bot_turn && ret_val > max) || (is_bot_turn && ret_val < max)) {
						max = ret_val;
						x_max = i;
						y_max = j;
						max_direction = 0;
					}
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n + 1; j++) {
				if (!horizontal_lines_copied[i][j]) {
					int ret_val = Play_func_Bot(1, i, j, levels - 1, vertical_lines_copied, horizontal_lines_copied, _boxes_list_copied, !is_bot_turn, max_levels, !require_chain_func);
					
					if ((!is_bot_turn && ret_val > max) || (is_bot_turn && ret_val < max)) {
						max = ret_val;
						x_max = i;
						y_max = j;
						max_direction = 1;
					}
				}
			}
		}
		if (require_chain_func && levels == max_levels) { //if is is required to use chain function, it will call it in first level
			
			int ret_chain_fucn = Play_func_Bot_Chain_Boxes(direction, x, y, levels, vertical_lines_copied, horizontal_lines_copied, _boxes_list_copied, !is_bot_turn);
			ret_chain_fucn *= -1;
			
			if (ret_chain_fucn < max)
				max = ret_chain_fucn;
		}
		
		if (x_max != -1)
			gain_score += max;

	}
	
	

	if (direction == 0) {
		if (x > 0 && x < n) {
			_boxes_list_copied->Boxes_Data[x - 1][y].numbers_of_adjacency_nodes++;
		}
		if (x < n && x > 0) {
			_boxes_list_copied->Boxes_Data[x][y].numbers_of_adjacency_nodes++;
		}
		
		vertical_lines_copied[x][y] = false; //unselect
		
	}
	else {
		if (y > 0 && y < n) {
			_boxes_list_copied->Boxes_Data[x][y - 1].numbers_of_adjacency_nodes++;
		}
		if (y < n && y > 0) {
			_boxes_list_copied->Boxes_Data[x][y].numbers_of_adjacency_nodes++;
		}

		
		horizontal_lines_copied[x][y] = false; //unselect
		
	}

	return gain_score;
}

int Game_Data::Play_func_Bot_Chain_Boxes(bool direction, int x, int y, int levels, bool ** vertical_lines_copied, bool ** horizontal_lines_copied, Boxes_List* _boxes_list_copied, bool is_bot_turn)
{
	

	int state1 = 0;
	int state2 = 0;
	int state3 = 0;
	int state4 = 0;

	int gain_score = 0;


	if (direction == 0) {
		vertical_lines_copied[x][y] = true;
		if (x < n && (_boxes_list_copied->Boxes_Data[x][y].numbers_of_adjacency_nodes == 1 || _boxes_list_copied->Boxes_Data[x][y].numbers_of_adjacency_nodes == 0)) {
			if (!horizontal_lines_copied[x][y]) {

				_boxes_list_copied->Boxes_Data[x][y].numbers_of_adjacency_nodes--;

				if (y > 0) {
					_boxes_list_copied->Boxes_Data[x][y - 1].numbers_of_adjacency_nodes--;
				}

				gain_score++;
				gain_score += Play_func_Bot_Chain_Boxes(1, x, y, levels, vertical_lines_copied, horizontal_lines_copied, _boxes_list_copied, is_bot_turn);
				state1 = 1;

			}
			else if (!horizontal_lines_copied[x][y + 1]) {

				_boxes_list_copied->Boxes_Data[x][y].numbers_of_adjacency_nodes--;

				if (y < n - 1) {
					_boxes_list_copied->Boxes_Data[x][y + 1].numbers_of_adjacency_nodes--;
				}

				gain_score++;
				gain_score += Play_func_Bot_Chain_Boxes(1, x, y + 1, levels, vertical_lines_copied, horizontal_lines_copied, _boxes_list_copied, is_bot_turn);
				state1 = 2;

			}
			else if (!vertical_lines_copied[x + 1][y]) {

				_boxes_list_copied->Boxes_Data[x][y].numbers_of_adjacency_nodes--;

				if (x < n - 1) {
					_boxes_list_copied->Boxes_Data[x + 1][y].numbers_of_adjacency_nodes--;
				}

				gain_score++;
				gain_score += Play_func_Bot_Chain_Boxes(0, x + 1, y, levels, vertical_lines_copied, horizontal_lines_copied, _boxes_list_copied, is_bot_turn);
				state1 = 3;

			}

		}
		if (x > 0 && (_boxes_list_copied->Boxes_Data[x - 1][y].numbers_of_adjacency_nodes == 1 || _boxes_list_copied->Boxes_Data[x - 1][y].numbers_of_adjacency_nodes == 0)) {
			if (!horizontal_lines_copied[x - 1][y]) {

				_boxes_list_copied->Boxes_Data[x - 1][y].numbers_of_adjacency_nodes--;

				if (y > 0) {
					_boxes_list_copied->Boxes_Data[x - 1][y - 1].numbers_of_adjacency_nodes--;
				}

				gain_score++;
				gain_score += Play_func_Bot_Chain_Boxes(1, x - 1, y, levels, vertical_lines_copied, horizontal_lines_copied, _boxes_list_copied, is_bot_turn);
				state2 = 1;

			}
			else if (!horizontal_lines_copied[x - 1][y + 1]) {

				_boxes_list_copied->Boxes_Data[x - 1][y].numbers_of_adjacency_nodes--;

				if (y < n - 1) {
					_boxes_list_copied->Boxes_Data[x - 1][y + 1].numbers_of_adjacency_nodes--;
				}

				gain_score++;
				gain_score += Play_func_Bot_Chain_Boxes(1, x - 1, y + 1, levels, vertical_lines_copied, horizontal_lines_copied, _boxes_list_copied, is_bot_turn);
				state2 = 2;

			}
			else if (!vertical_lines_copied[x - 1][y]) {

				_boxes_list_copied->Boxes_Data[x - 1][y].numbers_of_adjacency_nodes--;

				if (x > 1) {
					_boxes_list_copied->Boxes_Data[x - 2][y].numbers_of_adjacency_nodes--;
				}

				gain_score++;
				gain_score += Play_func_Bot_Chain_Boxes(0, x - 1, y, levels, vertical_lines_copied, horizontal_lines_copied, _boxes_list_copied, is_bot_turn);
				state2 = 3;

			}
		}
	}
	else {
		horizontal_lines_copied[x][y] = true;
		if (y < n && (_boxes_list_copied->Boxes_Data[x][y].numbers_of_adjacency_nodes == 1 || _boxes_list_copied->Boxes_Data[x][y].numbers_of_adjacency_nodes == 0)) {
			if (!vertical_lines_copied[x][y]) {

				_boxes_list_copied->Boxes_Data[x][y].numbers_of_adjacency_nodes--;

				if (x > 0) {
					_boxes_list_copied->Boxes_Data[x - 1][y].numbers_of_adjacency_nodes--;
				}

				gain_score++;
				gain_score += Play_func_Bot_Chain_Boxes(0, x, y, levels, vertical_lines_copied, horizontal_lines_copied, _boxes_list_copied, is_bot_turn);
				state3 = 1;

			}
			else if (!vertical_lines_copied[x + 1][y]) {

				_boxes_list_copied->Boxes_Data[x][y].numbers_of_adjacency_nodes--;

				if (x < n - 1) {
					_boxes_list_copied->Boxes_Data[x + 1][y].numbers_of_adjacency_nodes--;
				}

				gain_score++;
				gain_score += Play_func_Bot_Chain_Boxes(0, x + 1, y, levels, vertical_lines_copied, horizontal_lines_copied, _boxes_list_copied, is_bot_turn);
				state3 = 2;

			}
			else if (!horizontal_lines_copied[x][y + 1]) {
				_boxes_list_copied->Boxes_Data[x][y].numbers_of_adjacency_nodes--;

				if (y < n - 1) {
					_boxes_list_copied->Boxes_Data[x][y + 1].numbers_of_adjacency_nodes--;
				}

				gain_score++;
				gain_score += Play_func_Bot_Chain_Boxes(1, x, y + 1, levels, vertical_lines_copied, horizontal_lines_copied, _boxes_list_copied, is_bot_turn);
				state3 = 3;

			}

		}
		if (y > 0 && (_boxes_list_copied->Boxes_Data[x][y - 1].numbers_of_adjacency_nodes == 1 || _boxes_list_copied->Boxes_Data[x][y - 1].numbers_of_adjacency_nodes == 0)) {

			if (!vertical_lines_copied[x][y - 1]) {

				_boxes_list_copied->Boxes_Data[x][y - 1].numbers_of_adjacency_nodes--;

				if (x > 0) {
					_boxes_list_copied->Boxes_Data[x - 1][y - 1].numbers_of_adjacency_nodes--;
				}

				gain_score++;
				gain_score += Play_func_Bot_Chain_Boxes(0, x, y - 1, levels, vertical_lines_copied, horizontal_lines_copied, _boxes_list_copied, is_bot_turn);
				state4 = 1;

			}
			else if (!vertical_lines_copied[x + 1][y - 1]) {

				_boxes_list_copied->Boxes_Data[x][y - 1].numbers_of_adjacency_nodes--;

				if (x < n - 1) {
					_boxes_list_copied->Boxes_Data[x + 1][y - 1].numbers_of_adjacency_nodes--;
				}

				gain_score++;
				gain_score += Play_func_Bot_Chain_Boxes(0, x + 1, y - 1, levels, vertical_lines_copied, horizontal_lines_copied, _boxes_list_copied, is_bot_turn);
				state4 = 2;

			}
			else if (!horizontal_lines_copied[x][y - 1]) {
				_boxes_list_copied->Boxes_Data[x][y - 1].numbers_of_adjacency_nodes--;

				if (y > 1) {
					_boxes_list_copied->Boxes_Data[x][y - 2].numbers_of_adjacency_nodes--;
				}

				gain_score++;
				gain_score += Play_func_Bot_Chain_Boxes(1, x, y - 1, levels, vertical_lines_copied, horizontal_lines_copied, _boxes_list_copied, is_bot_turn);
				state4 = 3;

			}

		}
	}



	//unselect

	//state1
	if (state1 == 1) {
		_boxes_list_copied->Boxes_Data[x][y].numbers_of_adjacency_nodes++;

		if (y > 0) {
			_boxes_list_copied->Boxes_Data[x][y - 1].numbers_of_adjacency_nodes++;
		}
	}
	else if (state1 == 2) {
		_boxes_list_copied->Boxes_Data[x][y].numbers_of_adjacency_nodes++;

		if (y < n - 1) {
			_boxes_list_copied->Boxes_Data[x][y + 1].numbers_of_adjacency_nodes++;
		}
	}
	else if (state1 == 3) {
		_boxes_list_copied->Boxes_Data[x][y].numbers_of_adjacency_nodes++;

		if (x < n - 1) {
			_boxes_list_copied->Boxes_Data[x + 1][y].numbers_of_adjacency_nodes++;
		}
	}

	//state2
	if (state2 == 1) {
		_boxes_list_copied->Boxes_Data[x - 1][y].numbers_of_adjacency_nodes++;
		
		if (y > 0) {
			_boxes_list_copied->Boxes_Data[x - 1][y - 1].numbers_of_adjacency_nodes++;
		}
	}
	else if (state2 == 2) {
		_boxes_list_copied->Boxes_Data[x - 1][y].numbers_of_adjacency_nodes++;

		if (y < n - 1) {
			_boxes_list_copied->Boxes_Data[x - 1][y + 1].numbers_of_adjacency_nodes++;
		}
	}
	else if (state2 == 3) {
		_boxes_list_copied->Boxes_Data[x - 1][y].numbers_of_adjacency_nodes++;

		if (x > 1) {
			_boxes_list_copied->Boxes_Data[x - 2][y].numbers_of_adjacency_nodes++;
		}
	}

	//state3
	if (state3 == 1) {
		_boxes_list_copied->Boxes_Data[x][y].numbers_of_adjacency_nodes++;

		if (x > 0) {
			_boxes_list_copied->Boxes_Data[x - 1][y].numbers_of_adjacency_nodes++;
		}
	}
	else if (state3 == 2) {
		_boxes_list_copied->Boxes_Data[x][y].numbers_of_adjacency_nodes++;

		if (x < n - 1) {
			_boxes_list_copied->Boxes_Data[x + 1][y].numbers_of_adjacency_nodes++;
		}
	}
	else if (state3 == 3) {
		_boxes_list_copied->Boxes_Data[x][y].numbers_of_adjacency_nodes++;

		if (y < n - 1) {
			_boxes_list_copied->Boxes_Data[x][y + 1].numbers_of_adjacency_nodes++;
		}
	}

	//state4
	if (state4 == 1) {
		_boxes_list_copied->Boxes_Data[x][y - 1].numbers_of_adjacency_nodes++;

		if (x > 0) {
			_boxes_list_copied->Boxes_Data[x - 1][y - 1].numbers_of_adjacency_nodes++;
		}
	}
	else if (state4 == 2) {
		_boxes_list_copied->Boxes_Data[x][y - 1].numbers_of_adjacency_nodes++;

		if (x < n - 1) {
			_boxes_list_copied->Boxes_Data[x + 1][y - 1].numbers_of_adjacency_nodes++;
		}
	}
	else if (state4 == 3) {
		_boxes_list_copied->Boxes_Data[x][y - 1].numbers_of_adjacency_nodes++;

		if (y > 1) {
			_boxes_list_copied->Boxes_Data[x][y - 2].numbers_of_adjacency_nodes++;
		}
	}

	if (direction == 0) {
		vertical_lines_copied[x][y] = false;
	}

	if (direction == 1) {
		horizontal_lines_copied[x][y] = false;
	}

	return gain_score;
}
