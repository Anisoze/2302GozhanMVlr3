#pragma once
#include "include.h"
#include <chrono>

void Delete(Node** root, Node** Rroot, int var) {
	Node* tmp = NULL;
	Node* elem = NULL;
	Node* parent = NULL;
	bool side = false; // true = левая ; false = правая


	if ((*root)->l_child == NULL || (*root)->r_child == NULL) {
		tmp = *root;
	}
	else {
		elem = *root;
		tmp = Successor(&elem);
	}


	if (tmp->l_child != NULL) {
		elem = tmp->l_child;
	}
	else {
		elem = tmp->r_child;
	}




	if (elem != NULL) {
		elem->parent = tmp->parent;
	}
	if (var != 1) {
		parent = tmp->parent;
	}



	if (tmp->parent == NULL) {
		*Rroot = elem;
	}
	else if (tmp == tmp->parent->l_child) {
		tmp->parent->l_child = elem;
		side = true;
	}
	else {
		tmp->parent->r_child = elem;
	}



	if (tmp != *root) {
		(*root)->key = tmp->key;
	}
	if (var == 2) {
		auto begin = std::chrono::steady_clock::now();
		RBfixDel(&elem, &parent, &*Rroot);
		auto end = std::chrono::steady_clock::now();
		auto time = end - begin;
		auto elapsed_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(time);
	
		std::cout << " Время работы: " << elapsed_ns.count() << " наносекунд \n";
	}
	else if (var == 3) {
		auto begin = std::chrono::steady_clock::now();
		AVLfixDel(&parent, side, &*Rroot);
		auto end = std::chrono::steady_clock::now();
		auto time = end - begin;
		auto elapsed_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(time);
		
		std::cout << " Время работы: " << elapsed_ns.count() << " наносекунд \n";
	}
}