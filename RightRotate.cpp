#pragma once
#include "include.h"

void RightRotate(Node** root, Node** Rroot) {
	Node* parent = NULL;
	Node* c = NULL;
	Node* a = NULL;
	Node* b = NULL;
	
	b = *root;
	parent = b->parent;
	a = b->l_child;
	if (a == NULL) {
		return;
	}
	c = a->r_child;
	a->r_child = b;
	b->l_child = c;
	if (c != NULL) {
		c->parent = b;
	}
	a->parent = parent;
	if (parent != NULL) {
		if (parent->l_child == b) {
			parent->l_child = a;
		}
		else {
			parent->r_child = a;
		}
	}
	b->parent = a;
	if (parent == NULL) {
		*Rroot = a;
	}
}