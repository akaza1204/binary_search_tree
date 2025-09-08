#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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
			if (temp->left != NULL) {
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

struct Queue {
	struct Node* nodes[100];
	int front;
	int rear;
};
void init_queue(struct Queue* q) {
	q->front = q->rear = 0;
}


void enqueue(struct Queue* q, struct Node* node) {
	q->nodes[q->rear++] = node;
}

bool is_queue_empty(struct Queue* q) {
	return (q->front) >= (q->rear);
}

struct Node* dequeue(struct Queue* q) {
	return q->nodes[q->front++];
}

void printtree(struct Node* root) {
	if (root == NULL) return;
	struct Queue q;
	init_queue(&q);
	enqueue(&q, root);

	while (!is_queue_empty(&q)) {
		int size = q.rear - q.front; // 현재 레벨 노드 개수
		for (int i = 0; i < size; i++) {
			struct Node* node = dequeue(&q);
			printf("%d  ", node->data);

			if (node->left != NULL) { enqueue(&q, node->left); }
			if (node->right != NULL) { enqueue(&q, node->right); }
		}
		printf("\n");
	}
	
}



int main() {
	struct Node* root = NULL;
	root = insert(root, 50);
	root = insert(root, 40);
	root = insert(root, 30);
	root = insert(root, 20);
	root = insert(root, 10);
	root = insert(root, 60);
	root = insert(root, 1000);
	deleteNode(root, 60);
	printtree(root);
	printf("\n");
	return 0;
}

