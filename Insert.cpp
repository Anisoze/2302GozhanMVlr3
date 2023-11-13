#pragma once
#include "include.h"

Node* Insert(Node** root, Node** n) {
	Node* tmp = *root;
	while (*root != NULL) {
		tmp = *root;
		if ((*n)->key <= (*root)->key) {
			*root = (*root)->l_child;
		}
		else {
			*root = (*root)->r_child;
		}
	}
	if (tmp != NULL) {
		if ((*n)->key <= tmp->key) {
			tmp->l_child = *n;
			tmp->l_child->parent = tmp;
			return tmp->l_child;
		}
		else {
			tmp->r_child = *n;
			tmp->r_child->parent = tmp;
			return tmp->r_child;
		}
	}
	else {
		tmp = *n;
		return tmp;
	}
}