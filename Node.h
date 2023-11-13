#pragma once
#include "include.h"

class Node {
public:
	int key;
	int balance;
	Node* l_child;
	Node* r_child;
	Node* parent;
	bool color; // false = красный ; true = чёрный


	Node(int k) {
		parent = NULL;
		r_child = NULL;
		l_child = NULL;
		color = false;
		key = k;
		balance = 0;
	}
};