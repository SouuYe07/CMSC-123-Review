#include <stdio.h>
#include <stdlib.h>

struct Node{
    int id;
    int height;
    struct Node *leftChild;
    struct Node *rightChild;
};

struct Node* initNode(){
    struct Node *init = (struct Node *)malloc(sizeof(struct Node));
    init->leftChild = NULL;
    init->rightChild = NULL;
}

struct Node *insertNode(struct Node *head){
    int id;
    printf("Enter Used ID: ");
    scanf("%d", &id);

    printf("User %i indexed.\n", id);
}

int main(void){
    int choice;
    struct Node *head = NULL;

    while (1){
        printf("*********************************\n");
        printf("Welcome to the MazeDB Indexing Engine!\n");
        printf("*********************************\n");
        printf("[1] Insert User ID\n");
        printf("[2] Display Database Structure\n");
        printf("[3] Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                head = insertNode(head);
        }
        printf("\n");
    }
}
