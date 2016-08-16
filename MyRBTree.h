// My personal implementation of a Red-Black tree in C.

typedef struct rb_node Node;
typedef struct rb_tree Tree;

typedef int (*compare)(void*, void*);

struct rb_node {
	void *_data;
	enum {RED, BLACK} _color;
	struct rb_node *_left, *_right, *_parent;
};

struct rb_tree {
	Node *_root;
	int _size;
};

// initialize a new node.
Node* initNode(void *data);

Tree* initTree();

// insert node into red black tree
// cFunc is a pointer to a user function that compares the
// values being stored in the tree with the following signature:
// int cFunc(void* val1, void* val2)
// 		if val1 == val2 it returns 0
//		else if val1 < val2 it returns <0
//		else if val1 > val2 it returns
void insert(Tree* tree, void *data, compare cFunc);

// recursive function that inserts to the left of a node
int insertLeft(Node *ptr, Node *newNode, compare cFunc);

// recursive function that inserts to the right of a node
int insertRight(Node *ptr, Node *newNode, compare cFunc);

// query if a tree contains a value
int search(Tree* tree, void *data, compare cFunc);

// recursive helper function for search
int searchHelper(Node *ptr, void *data, compare cFunc);