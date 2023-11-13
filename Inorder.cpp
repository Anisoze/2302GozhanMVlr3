#pragma once
#include "include.h"

void InOrder(Node** root, std::fstream& g) {
	if (*root != NULL) {
		InOrder(&(*root)->l_child, g);
		g << (*root)->key << "\n";
		std::cout << (*root)->key << "\n";
		InOrder(&(*root)->r_child, g);
	}
}