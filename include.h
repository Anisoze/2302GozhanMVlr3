#pragma once

#include <iostream>
#include <fstream>
#include "Node.h"
Node* Insert(Node** root, Node** n);
bool Read(Node** root, const int N, int var);
Node* ToRoot(Node** root);
void InOrder(Node** root, std::fstream& g);
Node* Search(Node** root, int k);
Node* SearchMin(Node** root);
Node* SearchMax(Node** root);
Node* Successor(Node** root);
Node* Predecessor(Node** root);
void Delete(Node** root, Node** Rroot, int var);
int Hight(Node** root);
void LevelOrder(Node** root, std::fstream& g);
void PreOrder(Node** root, std::fstream& g);
void PostOrder(Node** root, std::fstream& g);
void LeftRotate(Node** root, Node** Rroot);
void RightRotate(Node** root, Node** Rroot);
void RBfixIns(Node** root, Node** Rroot);
void RBfixDel(Node** x, Node** parent, Node** Rroot);
void AVLfixIns(Node** root, Node** Rroot);
void AVLfixDel(Node** root, bool side, Node** Rroot);