#pragma once
#include "include.h"

Node* SearchMax(Node** root) {
	if ((*root)->r_child != NULL) {
		return SearchMax(&(*root)->r_child);
	}
	else {
		return *root;
	}
}