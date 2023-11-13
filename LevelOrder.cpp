#pragma once
#include "include.h"
#include <queue>

void LevelOrder(Node** root, std::fstream& g) {
	std::queue<Node*> q;
	q.push(*root);
	Node* tmp;
	while (!q.empty()) {
		tmp = q.front();
		q.pop();
		g << tmp->key << "\n";
		std::cout << tmp->key << "\n";
		if (tmp->l_child != NULL) {
			q.push(tmp->l_child);
		}
		if (tmp->r_child != NULL) {
			q.push(tmp->r_child);
		}
	}
}