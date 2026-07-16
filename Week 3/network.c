#include <stdio.h>
#include <stdlib.h>

struct Node{
    int id;
    struct Node* leftChild;
    struct Node* rightChild;
};

struct Node* initNode(){
    struct Node* init = (struct Node*) malloc(sizeof(struct Node));
    init->leftChild = NULL;
    init->rightChild = NULL;
}

int main(void){
    int choice;
    struct Node* head = initNode();

    while (1) {
        printf("*********************************\n");
        printf("Welcome to the MazeRoute Cache Engine!\n");
        printf("*********************************\n");
        printf("[1] Access / Insert Routing IP\n");
        printf("[2] Search Cache\n");
        printf("[3] Show Curernt Cache Root\n");
        printf("[4] Display Cache Hierarchy (Inorder)\n");
        printf("[5] Exit\n\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice){
            case 1:
                break;
        }
    }
    return 0;
}
