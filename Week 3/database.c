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

int max(int a, int b){
    int toReturn = (a >= b) ? a: b;
    return toReturn;
}

struct Node * insert(struct Node *head, int id){
    if (head == NULL){
        printf("Added Null\n");
        head = initNode();
        head->id = id;
        head->height = -1;
    }
    
    if (id < head->id){
        printf("Went left\n");
        head->leftChild = insert(head->leftChild, id);

        if (head->rightChild != NULL){
            head->height = max(head->leftChild->height, head->rightChild->height) + 1;
        }
        else {
            head->height = head->leftChild->height + 1;
        }
    }
    else if (id > head->id){
        printf("Went right\n");
        head->rightChild = insert(head->rightChild, id);

        if (head->leftChild != NULL){
            head->height = max(head->leftChild->height, head->rightChild->height) + 1;
        }
        else {
            head->height = head->rightChild->height+ 1;
        }
    }

    printf("New height of ID %d: %d\n", head->id, head->height);
    return head;
}

struct Node *insertNode(struct Node *head){
    int id;
    printf("Enter Used ID: ");
    scanf("%d", &id);

    head = insert(head, id);

    printf("User %i indexed.\n", id);
    return head;
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
