#pragma once
#include "include.h"

void RBfixIns(Node** root, Node** Rroot) {
	if ((*root)->parent != NULL) {
		while (((*root)->parent != NULL) && ((*root)->parent->color == false)) {
			if ((*root)->parent->parent != NULL) {
				if ((*root)->parent == (*root)->parent->parent->l_child) { 
					Node* uncle = (*root)->parent->parent->r_child;
					if (uncle != NULL && uncle->color == false) {                       // 1
						(*root)->parent->color = true;
						uncle->color = true;
						uncle->parent->color = false;
						(*root) = uncle->parent;
					}
					else if ((*root) == (*root)->parent->r_child) { // 2
						(*root) = (*root)->parent;
						LeftRotate(&*root, &*Rroot);
						(*root)->parent->color = true; // 3
						(*root)->parent->parent->color = false;
						RightRotate(&(*root)->parent->parent, &*Rroot);
					}
					else {
						(*root)->parent->color = true; // 3
						(*root)->parent->parent->color = false;			
						RightRotate(&(*root)->parent->parent, &*Rroot);
					}
				}



				else {
					Node* uncle = (*root)->parent->parent->l_child; 					
					if (uncle != NULL && uncle->color == false) {               //1
						(*root)->parent->color = true;
						uncle->color = true;
						uncle->parent->color = false;
						(*root) = uncle->parent;
					}
					else if ((*root) == (*root)->parent->l_child) { // 2
						(*root) = (*root)->parent;
						RightRotate(&*root, &*Rroot);
						(*root)->parent->color = true; // 3
						(*root)->parent->parent->color = false;
						LeftRotate(&(*root)->parent->parent, &*Rroot);
					}
					else {
						(*root)->parent->color = true; // 3
						(*root)->parent->parent->color = false;
						LeftRotate(&(*root)->parent->parent, &*Rroot);					
					}
				}
			}
			
		}
	}
	(*Rroot)->color = true;
}