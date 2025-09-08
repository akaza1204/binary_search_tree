#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "binary_search_tree.h"


int main() {
    int choice;
    int k;
    struct Node* root = NULL;
    while (1) {
        printf("\n====MENU====\n");
        printf("1.INSERT\n");
        printf("2.DELETE\n");
        printf("3.SEARCH\n");
        printf("4.PRINT\n");
        printf("5.CLEAR\n");
        printf("6.EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("insert number: ");
            scanf("%d", &k);
            root = insert(root, k);   // ⭐ root 갱신
            break;

        case 2:
            printf("delete number: ");
            scanf("%d", &k);
            root = deleteNode(root, k);  // ⭐ root 갱신
            break;

        case 3:
            printf("search number: ");
            scanf("%d", &k);
            if (search(root, k) != NULL)
                printf("%d found in tree\n", k);
            else
                printf("%d not found in tree\n", k);
            break;

        case 4:
            if (root == NULL) {
                printf("Tree is empty.\n");
            }
            else {
                printf("\n===== Tree =====\n");
                printBST(root, 0, 0);
            }
            break;


        case 5:
            deleteTree(root);
            root = NULL;   // ⭐ 안전하게 초기화
            printf("Tree has been reset (all nodes deleted).\n");
            break;

        case 6:
            printf("Exit program\n");
            deleteTree(root);
            root = NULL;
            return 0;

        default:
            printf("Invalid choice, try again\n");
            break;
        }
    }
}
