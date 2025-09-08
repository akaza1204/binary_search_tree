#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


//binary search tree node

struct Node {
	int data;
	struct Node* left;
	struct Node* right;
};


struct Node* newNode(int data) {
	struct Node* node = (struct Node*)malloc(sizeof(struct Node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return node;
}

struct Node* insert(struct Node* node, int data) {
	if (node == NULL) {
		return newNode(data);
	}
	else if (data < node->data) {
		node->left = insert(node->left, data);
	}
	else if (data > node->data) {
		node->right = insert(node->right, data);
	}	return node;
}

struct Node* deleteNode(struct Node* node, int data) {
	if (node == NULL) {
		return node; ///노드가 없을때는 삭제할게 없음
	}
	else if (data < node->data) {
		node->left = deleteNode(node->left, data); //삭제할 데이터가 작으면 왼쪽으로 탐색
	}
	else if (data > node->data) {
		node->right = deleteNode(node->right, data);  // 삭제할 데이터가 크면 오른쪽으로 탐색
	}
	else {  ///삭제할 데이터를 찾았을때
		if (node->left == NULL) {//왼쪽 자식이 없을때
			struct Node* temp = node->right;
			free(node);
			return temp;
		}
		if (node->right == NULL) { //오른쪽 자식이 없을때
			struct Node* temp = node->left;
			free(node);
			return temp;
		}
		else { //양쪽 다 자식이 있을때 오른쪽 서브트리에서 가장 작은노드를 찾아서 삭제할 노드에 복사
			struct Node* temp = node->right;
			while (temp->left != NULL) {
				temp = temp->left;
			}
			node->data = temp->data;
			node->right = deleteNode(node->right, temp->data);
			return node;
		}
		return node;
	}
}

struct Node* search(struct Node* root, int data) {
	if (root == NULL || root->data == data) {
		return root;
	}
	else if (data < root->data) {
		return search(root->left, data);
	}
	else
	{
		return search(root->right, data);
	}
}

void printBST(struct Node* root, int indent, int isLeft) {
	if (root == NULL) return;

	// 오른쪽 서브트리 먼저 출력 (위쪽)
	printBST(root->right, indent + 4, 0);

	// 현재 노드 출력
	for (int i = 0; i < indent; i++) printf(" ");

	if (indent == 0)           // 루트
		printf("*%d\n", root->data);
	else
		printf("%s%d\n", isLeft ? "└─" : "┌─", root->data);

	// 왼쪽 서브트리 출력 (아래쪽)
	printBST(root->left, indent + 4, 1);
}


void deleteTree(struct Node* root) {
	if (root == NULL) return;
	deleteTree(root->left);
	deleteTree(root->right);
	free(root);
}

