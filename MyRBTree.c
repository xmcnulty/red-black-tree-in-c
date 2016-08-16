// My own red black tree.

#include "MyRBTree.h"

#include <stdlib.h>
#include <stdio.h>

// initialize a new node.
Node* initNode(void *_data) {
	Node* n = (Node*) calloc(1, sizeof(Node));
	
	if(!n) {
		fprintf(stderr, "ERROR: Could not allocate Node\n");
		exit(-1);
	}
	
	n->color = RED;
	n->data = _data;
}

// initialize a new tree.
Tree* initTree() {
	return (Tree*) calloc(1, sizeof(Tree));
}

// TESTING ONLY
int main() {
	return 0;
}
