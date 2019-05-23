#include "Boxes_List.h"

Boxes_List::Boxes_List(int _n)
{
	n = _n;
	Boxes_Data = new Box_Node*[n];
	for (int i = 0; i < n; i++) {
		Boxes_Data[i] = new Box_Node[n];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			Boxes_Data[i][j].x = i;
			Boxes_Data[i][j].y = j;
			if (i < n - 1) {
				Boxes_Data[i][j].numbers_of_adjacency_nodes++;
			}
			if (i > 0) {
				Boxes_Data[i][j].numbers_of_adjacency_nodes++;
			}
			if (j > 0) {
				Boxes_Data[i][j].numbers_of_adjacency_nodes++;
			}
			if (j < n - 1) {
				Boxes_Data[i][j].numbers_of_adjacency_nodes++;
			}
		}
	}
	
}

Boxes_List::Boxes_List(Boxes_List &other)
{
	n = other.n;
	Boxes_Data = new Box_Node*[other.n];
	for (int i = 0; i < n; i++) {
		Boxes_Data[i] = new Box_Node[n];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			Boxes_Data[i][j].x = i;
			Boxes_Data[i][j].y = j;
			Boxes_Data[i][j].numbers_of_adjacency_nodes = other.Boxes_Data[i][j].numbers_of_adjacency_nodes;
		}
	}
}
