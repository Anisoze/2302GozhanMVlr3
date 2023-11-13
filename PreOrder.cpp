#pragma once
#include "include.h"1

void PreOrder(Node** root, std::fstream& g) {
	if (*root == NULL) {
		return;
	}
	g << (*root)->key << "\n";
	std::cout << (*root)->key << "\n";
	PreOrder(&(*root)->l_child, g);
	PreOrder(&(*root)->r_child, g);
}