#pragma once
#include "include.h"

Node* Successor(Node** root) {
	Node* elem = *root;
	elem = ToRoot(&elem);
	if (*root == SearchMax(&elem)) {
		return NULL;
	}
	if ((*root)->r_child != NULL) {
		return SearchMin(&(*root)->r_child);
	}
	while (((*root)->parent != NULL) && (*root == (*root)->parent->r_child)) {
		*root = (*root)->parent;
	}
	return (*root)->parent;
}