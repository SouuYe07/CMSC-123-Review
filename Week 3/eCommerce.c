#include <stdio.h>
#include <stdlib.h>

struct node{
    int id;
    int quantity;
    struct node *leftChild;
    struct node *rightChild;
};

struct node* initNode(){
    struct node* initialized = (struct node*)malloc(sizeof(struct node));

    initialized->leftChild = NULL;
    initialized->rightChild = NULL;
    return initialized;
}

struct node* insertNode(struct node* temp, int id){
    if (id == temp->id){
        return NULL;
    }

    else if (id < temp->id){
        if (temp->leftChild == NULL){
            temp->leftChild = initNode();
            return temp->leftChild;
        }
        else insertNode(temp->leftChild, id);
    }

    else if (id > temp->id){
        if (temp->rightChild == NULL){
            temp->rightChild = initNode();
            return temp->rightChild;
        }
        else insertNode(temp->rightChild, id);
    }
}

void insertProduct(struct node** head){
    int id, quantity;
    struct node* toInsert;

    printf("Enter Product ID: ");
    scanf("%d", &id);

    if ((*head) == NULL){
        *head = initNode();
        toInsert = *head;
    }
    
    else{
        toInsert = insertNode((*head), id);
    }

    if (toInsert == NULL){
        printf("Product with ID already exists.\n");
        return;
    }

    printf("Enter Stock Quantity: ");
    scanf("%d", &quantity);


    toInsert->id = id;
    toInsert->quantity = quantity;

    return;
}

int main(void){
    int choice;
    struct node* head = NULL;

    while(1){
        printf("*********************************\n");
        printf("Welcome to the MazeCart Inventory System!\n");
        printf("*********************************\n");
        printf("[1] Insert Product\n");
        printf("[2] Find/Update Stock\n");
        printf("[3] Delete Product\n");
        printf("[4] Display Inventory (Sorted)\n");
        printf("[5] Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice){
            case 1:
                insertProduct(&head);
                break;
            case 2:
                printf("%i\n", head->id);
                break;
            case 3:
                printf("%i\n", head->rightChild->rightChild->id);
                break;
        }
        printf("\n");
    }
}
