// My own red black tree.

#include "MyRBTree.h"

#include <stdlib.h>
#include <stdio.h>

// initialize a new node.
Node* initNode(void *data) {
	Node* n = (Node*) calloc(1, sizeof(Node));
	
	if(!n) {
		fprintf(stderr, "ERROR: Could not allocate Node\n");
		exit(-1);
	}
	
	n->_color = RED;
	n->_data = data;

    return n;
}

// initialize a new tree.
Tree* initTree() {
    Tree *tree = (Tree*) calloc(1, sizeof(Tree));

    if (!tree) {
        fprintf(stderr, "ERROR: Could not allocate Tree\n");
        exit(-2);
    }

	return tree;
}

// insert a node into the tree
void insert(Tree* tree, void *data, compare cFunc) {
    Node *node = initNode(data);

    // case 1: tree is empty
    if(tree->_size == 0) {
        tree->_root = node;
        node->_color = BLACK;

        tree->_size ++;

        return;
    }

    Node *ptr = tree->_root;

    int comparison = cFunc(data, ptr->_data), res;

    if (comparison == 0)
        return;
    else
		(comparison < 0) ? insertLeft(ptr, node, cFunc) : insertRight(ptr, node, cFunc);
	
    return;
}

// recursive function that inserts to the left of a node
int insertLeft(Node *ptr, Node *newNode, compare cFunc) {
    if(ptr->_left == NULL) { // insert to the left of ptr
        ptr->_left = newNode;
        newNode->_parent = ptr;
        
        // check that the tree has maintained the RB property.
        if (ptr->_color != BLACK) {
			// Get the parent's sibling
			Node *pSibling = (ptr->_parent->_left == ptr) ? ptr->_parent->_right : ptr->_parent->_left;
			
			// Case A: Parent's sibling is black or null
			if (!pSibling || pSibling->_color == BLACK) {
				
			}
		}

        return 1;
    }

    ptr = ptr->_left;

    int comparison = cFunc(newNode->_data, ptr->_data);

    if (comparison == 0)
        return 0;
    else
        return (comparison < 0) ? insertLeft(ptr, newNode, cFunc) : insertRight(ptr, newNode, cFunc);
}

// recursive function that inserts to the right of a node
int insertRight(Node *ptr, Node *newNode, compare cFunc) {
    if(ptr->_right == NULL) { // insert to the right of ptr
        ptr->_right = newNode;
        newNode->_parent = ptr;
        
		// check that the tree has maintained the RB property.
        if (newNode->_parent->_color != BLACK) {
			
		}

        return 1;
    }

    ptr = ptr->_right;

    int comparison = cFunc(newNode->_data, ptr->_data);

    if (comparison == 0)
        return 0;
    else
        return (comparison < 0) ? insertLeft(ptr, newNode, cFunc) : insertRight(ptr, newNode, cFunc);
}

// query if a tree contains a value
int search(Tree* tree, void *data, compare cFunc) {
    if (tree->_size == 0)
        return 0;

    return searchHelper(tree->_root, data, cFunc);
}

// recursive helper function for search
int searchHelper(Node *ptr, void *data, compare cFunc) {
    int comparison = cFunc(ptr->_data, data);

    if (comparison == 0)
        return 1;
    else
        return (comparison < 0) ? searchHelper(ptr->_left, data, cFunc) : searchHelper(ptr->_right, data, cFunc);
}
