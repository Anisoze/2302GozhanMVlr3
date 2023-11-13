#pragma once
#include "include.h"

Node* Search(Node** root, int k) {
	if (*root == NULL || (*root)->key == k) {
		return *root;
	}	
	if (k < (*root)->key) {
		return Search(&(*root)->l_child, k);
	}
	else {
		return Search(&(*root)->r_child, k);
	}	
}