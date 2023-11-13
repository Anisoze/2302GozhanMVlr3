#pragma once
#include "include.h"1

void PostOrder(Node** root, std::fstream& g) {
	if ((*root) == NULL) {
		return;
	}
	PostOrder(&(*root)->l_child, g);
	PostOrder(&(*root)->r_child, g);
	g << (*root)->key << "\n";
	std::cout << (*root)->key << "\n";
}
