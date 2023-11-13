#pragma once
#include "include.h"

void RBfixDel(Node** x, Node** parent, Node** Rroot) {
	Node* w;
	while (*x != *Rroot && (*x == NULL || (*x)->color == true)) {
		if ((*x) == (*parent)->l_child) {
			w = (*parent)->r_child;
			if (w != NULL && w->color == false) {
				w->color = true;
				(*parent)->color = false;
				LeftRotate(&*parent, &*Rroot);
				w = (*parent)->r_child;
			}
			if (w != NULL && (w->l_child == NULL || w->l_child->color == true) && (w->r_child == NULL || w->r_child->color == true)) {
				w->color = false;
				*x = *parent;
				*parent = (*parent)->parent;

			}
			else if ((w != NULL) && (w->r_child == NULL || w->r_child->color == true) && w->l_child != NULL && w->l_child->color == false) {
				w->l_child->color = true;
				w->color = false;
				RightRotate(&w, &*Rroot);
				w = (*parent)->r_child;
				
				w->color = (*parent)->color;
				(*parent)->color = true;
				if (w->r_child != NULL) {
					w->r_child->color = true;
				}
				LeftRotate(&*parent, &*Rroot);
				*x = *Rroot;
			}
			else {
				if (w != NULL) {
					w->color = (*parent)->color;
				}
				(*parent)->color = true;
				if (w != NULL && w->r_child != NULL) {
					w->r_child->color = true;
				}
				LeftRotate(&*parent, &*Rroot);
				*x = *Rroot;
			}

		}





		else {
			w = (*parent)->l_child;
			if (w != NULL && w->color == false) {
				w->color = true;
				(*parent)->color = false;
				RightRotate(&*parent, &*Rroot);
				w = (*parent)->l_child;
			}
			if (w != NULL && (w->l_child == NULL || w->l_child->color == true) && (w->r_child == NULL || w->r_child->color == true)) {
				w->color = false;
				*x = *parent;

			}
			else if (w != NULL && (w->l_child == NULL || w->l_child->color == true) && w->r_child != NULL && w->r_child->color == false) {
				w->r_child->color = true;
				w->color = false;
				LeftRotate(&w, &*Rroot);
				w = (*parent)->l_child;

				w->color = (*parent)->color;
				(*parent)->color = true;
				if (w->l_child != NULL) {
					w->l_child->color = true;
				}
				RightRotate(&*parent, &*Rroot);
				*x = *Rroot;
			}
			else {
				if (w != NULL) {
					w->color = (*parent)->color;
				}
				(*parent)->color = true;
				if (w != NULL && w->l_child != NULL) {
					w->l_child->color = true;
				}
				RightRotate(&*parent, &*Rroot);
				*x = *Rroot;
			}

		}




	}
	if ((*x) != NULL) {
		(*x)->color = true;
	}
}