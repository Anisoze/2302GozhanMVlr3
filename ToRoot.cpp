#pragma once
#include "include.h"

Node* ToRoot(Node** root) {
	Node* tmp = *root;
	while (*root != NULL) {
		tmp = *root;
		*root = (*root)->parent;
	}
	return tmp;
}