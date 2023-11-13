#pragma once
#include "include.h"

bool Read(Node** root, const int N, int var) {
	std::fstream f;
	Node* Elem;
	f.open("in.txt", std::ios::in);
	if (f.is_open()) {
		int tmp;
		for (int i = 0; i < N; i++) {
			f >> tmp;
			Node* n = new Node(tmp);			
			n = Insert(*&root, &n);
			Elem = n;
			if (var == 2) {
				*root = ToRoot(&Elem);
				Elem = n;
				RBfixIns(&n, &*root);
			}
			else if (var == 3) {
				*root = ToRoot(&Elem);
				Elem = n;
				AVLfixIns(&n, &*root);
			}
			*root = ToRoot(&Elem);				
		}
		return true;
	}
	else {
		return false;
	}
}