#include "MyRBTree.h"

#include <stdlib.h>
#include <stdio.h>

int dataCompare(void* val1, void* val2) {
	int *v1 = (int*) val1, *v2 = (int*) val2;
	
	if (v1 == v2)
		return 0;
	else if (v1 < v2)
		return -1;
	else
		return 1;
}

// class used to test the red black tree implementation.
int main(int argc, char **argv) {
	Tree *myTree = initTree();
	
	int values[] = {10, 7, 5};
	
	insert(myTree, (void*) values, &dataCompare);
	insert(myTree, (void*) values+1, &dataCompare);
	
	printf("Root: %d\n", *((int*) myTree->_root->_data));
	printf("Root left: %d\n", *((int*) myTree->_root->_left->_data));
	
	return 0;
}
