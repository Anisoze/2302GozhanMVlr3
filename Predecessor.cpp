#pragma once
#include "include.h"

Node* Predecessor(Node** root) {
	Node* elem = *root;
	elem = ToRoot(&elem);
	if (*root == SearchMin(&elem)) {
		return NULL;
	}
	if ((*root)->l_child != NULL) {
		return SearchMax(&(*root)->l_child);
	}
	while (((*root)->parent != NULL) && (*root == (*root)->parent->l_child)) {
		*root = (*root)->parent;
	}
	return (*root)->parent;
}