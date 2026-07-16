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
    return init;
}

struct Node* insertNode(struct Node* head, int id){
    if (head == NULL){
        head = initNode();
        head->id = id;
        return head;
    }

    else if (id < head->id) head->leftChild = insertNode(head->leftChild, id);
    else if (id > head->id) head->rightChild = insertNode(head->rightChild, id);
    else if (id == head->id) return head;

    return head;
}

struct Node* accessInsertRoute(struct Node* head){
    int id;
    printf("Enter Routing Key (IP ID): ");
    scanf("%d", &id);

    head = insertNode(head, id);

    printf("Key %i inserted. Root is now %i.\n", id, id);
    return head;
}

void displayHierarchy(struct Node* head){
    if (head == NULL){
        return;
    }

    displayHierarchy(head->leftChild);
    printf("woier%i\n", head->id);
    displayHierarchy(head->rightChild);
}

int main(void){
    int choice;
    struct Node* head;

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
                head = accessInsertRoute(head);
                break;
            case 4:
                printf("--- Current Cache Hierarchy (Inorder)---\n");
                displayHierarchy(head);
        }
        printf("\n");
    }
    return 0;
}
