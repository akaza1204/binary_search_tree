#define BINARY_SEARCH_TREE_H


struct Node {
	int data;
	struct Node* left;
	struct Node* right;
};

struct Node* newNode(int data);
struct Node* insert(struct Node* node, int data);
struct Node* deleteNode(struct Node* node, int data);
struct Node* search(struct Node* root, int data);


void printBST(struct Node* root, int indent, int isLeft);
void deleteTree(struct Node* root);