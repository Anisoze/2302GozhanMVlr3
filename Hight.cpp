#pragma once
#include "include.h"

int Hight(Node** root) {
	if (*root == NULL) {
		return 0;
	}
	int hl = Hight(&(*root)->l_child);
	int hr = Hight(&(*root)->r_child);
	if (hl > hr) {
		return hl + 1;
	}
	else {
		return hr + 1;
	}

}