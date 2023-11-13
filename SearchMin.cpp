#pragma once
#include "include.h"

Node* SearchMin(Node** root) {
	if ((*root)->l_child != NULL) {
		return SearchMin(&(*root)->l_child);
	}
	else {
		return *root;
	}
}