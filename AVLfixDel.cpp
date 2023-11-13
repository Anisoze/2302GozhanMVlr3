#pragma once
#include "include.h"

void AVLfixDel(Node** root, bool side, Node** Rroot) {
	do {
		if (*root != NULL) {
			if (side) {
				(*root)->balance--;
			}
			else {
				(*root)->balance++;
			}
			if ((*root)->balance == 1 || (*root)->balance == -1) {
				break;
			}
			else if ((*root)->balance == 2 || (*root)->balance == -2) {
				if ((*root)->balance == 2) {
					if ((*root)->l_child->balance == 1) {
						RightRotate(&*root, &*Rroot);
						(*root)->balance = 0;
						(*root)->parent->balance = 0;
						break;
					}
					else if ((*root)->l_child->balance == -1) {
						LeftRotate(&(*root)->l_child, &*Rroot);
						RightRotate(&*root, &*Rroot);
						int b = (*root)->parent->balance;
						(*root)->parent->balance = 0;
						if (b == 1) {
							(*root)->parent->l_child->balance = 0;
							(*root)->balance = -1;
						}
						else if (b== -1){
							(*root)->parent->l_child->balance = 1;
							(*root)->balance = 0;
						}
						else if (b == 0) {
							(*root)->parent->l_child->balance = 0;
							(*root)->balance = 0;
						}
					}
					break;
				}
				else if ((*root)->balance == -2) {
					if ((*root)->r_child->balance == -1) {
						LeftRotate(&*root, &*Rroot);
						(*root)->balance = 0;
						(*root)->parent->balance = 0;
						break;
					}
					else if ((*root)->r_child->balance == 1) {
						RightRotate(&(*root)->r_child, &*Rroot);
						LeftRotate(&*root, &*Rroot);
						int b = (*root)->parent->balance;
						(*root)->parent->balance = 0;
						if (b == -1) {
							(*root)->parent->r_child->balance = 0;
							(*root)->balance = 1;
						}
						else if (b == 1) {
							(*root)->parent->r_child->balance = -1;
							(*root)->balance = 0;
						}
						else if (b == 0) {
							(*root)->parent->r_child->balance = 0;
							(*root)->balance = 0;
						}
					}
					break;
				}
			}
			else {
				if ((*root)->parent != NULL && (*root) == (*root)->parent->l_child) {
					side = true;
				}
				else {
					side = false;
				}
				(*root) = (*root)->parent;
			}
		}
	} while (*root != NULL);
}
