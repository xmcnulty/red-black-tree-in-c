// My personal implementation of a Red-Black tree in C.

typedef struct rb_node Node;
typedef struct rb_tree Tree;

typedef int (*compare)(void*, void*);

struct rb_node {
	void *data;
	enum {RED, BLACK} color;
	struct rb_node *left, *right, *parent;
};

struct rb_tree {
	Node* root;
	int size;
};

// initialize a new node.
Node* initNode(void *_data;

Tree* initTree();

void insert(Tree* t, void *_data, compare *c);
