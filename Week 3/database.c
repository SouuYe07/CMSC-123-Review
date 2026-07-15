#include <stdio.h>
#include <stdlib.h>

#define LEFT 1
#define RIGHT 2
#define SINGLEL 1
#define SINGLER 2
#define DOUBLEL 3
#define DOUBLER 4
#define FALSE 0
#define TRUE 1

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
    init->height = 0;
    return init;
}

int max(int a, int b){
    int toReturn = (a >= b) ? a : b;
    return toReturn;
}

int difference(struct Node* head){
    int right = -1, left = -1;

    if (head->rightChild != NULL) right = head->rightChild->height;
    if (head->leftChild != NULL) left = head->leftChild->height;

    return abs(left - right);
}

int determineRotation(struct Node* head, int id){
    int first = 0, second = 0, rotation;
    struct Node* traverse = NULL;

    printf("Anomaly at head: %i\n", head->id);

    if (id < head->id){
        first = LEFT;
        traverse = head->leftChild;
    }
    
    else if (id > head->id){
        first = RIGHT;
        traverse = head->rightChild;
    }

    printf("Rotation: %i ", first);

    if (traverse->leftChild != NULL){
        if (id == traverse->leftChild->id){
            second = LEFT;
        }
    }
    else if (traverse->rightChild != NULL){
        if (id == traverse->rightChild->id){
            second = RIGHT;
        }
    }

    if (first == LEFT){
        rotation = DOUBLEL;
        if (second == LEFT) rotation = SINGLEL;
    }
    else if (first == RIGHT){
        rotation = DOUBLER;
        if (second == RIGHT) rotation = SINGLER;
    }

    return rotation;
}

void singleLeftRotation(struct Node* head){
    struct Node* child = head->leftChild;
    struct Node* temp = child->rightChild;
    child->rightChild = head;
    head->leftChild = temp;
    return;
}

struct Node* insert(struct Node *head, int id){
    int direction = 0, rotation = 0;

    if (head == NULL){
        head = initNode();
        head->id = id;
        head->height = 0;
    }
    
    if (id < head->id){
        direction = LEFT;
        head->leftChild = insert(head->leftChild, id);

        if (head->rightChild != NULL){
            head->height = max(head->leftChild->height, head->rightChild->height) + 1;
        }
        else {
            head->height = head->leftChild->height + 1;
        }
    }
    else if (id > head->id){
        direction = RIGHT;
        head->rightChild = insert(head->rightChild, id);

        if (head->leftChild != NULL){
            head->height = max(head->leftChild->height, head->rightChild->height) + 1;
        }
        else {
            head->height = head->rightChild->height + 1;
        }
    }

    if (difference(head) > 1) rotation = determineRotation(head, id);
    switch (rotation){
        case SINGLEL:
            singleLeftRotation(head);
            break;
    }
    
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

void displayDatabase(struct Node *head){
    printf("--- Current DB Index Structure (Level-Order) ---\n");
    if (head == NULL){
        return;
    }
    
    int level = 1, front = 0, rear = 2;
    struct Node* queue[100];

    queue[0] = head;
    queue[1] = NULL;

    printf("Level 0: ");

    do {
        head = queue[front];
        
        if (head == NULL){
            printf("\nLevel %i: ", level);
            queue[rear] == NULL;
            rear++;
            level++;
            front++;
        }

        if (head->leftChild != NULL){
            queue[rear] = head->leftChild;
            rear++;
        }
        if (head->rightChild != NULL){
            queue[rear] = head->rightChild;
            rear++;
        }

        printf("[ID: %i, Height: %i] ", head->id, head->height);
        front++;
    } while (front != rear);
}

int main(void){
    int choice, amount = 0;
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
                break;
            case 2:
                displayDatabase(head);
                break;
        }
        printf("\n");
    }
}
