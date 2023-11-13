#pragma once
#include "include.h"

void LeftRotate(Node** root, Node** Rroot) {
	Node* parent = NULL;
	Node* c = NULL;
	Node* a = NULL;
	Node* b = NULL;
	a = *root;
	parent = a->parent;
	b = a->r_child;
	if (b == NULL) {
		return;
	}
	c = b->l_child;
	b->l_child = a;
	a->r_child = c;
	if (c != NULL) {
		c->parent = a;
	}
	b->parent = parent;
	if (parent != NULL) {
		if (parent->l_child == a) {
			parent->l_child = b;
		}
		else {
			parent->r_child = b;
		}
	}
	a->parent = b;
	if (parent == NULL) {
		*Rroot = b;
	}
}



