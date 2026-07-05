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

void insertProduct(struct node* head){
    int id, quantity;
    struct node** toInsert;

    printf("Enter Product ID: ");
    scanf("%d", &id);

    printf("Enter Strock Quantity: ");
    scanf("%d", &quantity);

    return;
}

int main(void){
    int choice;
    struct node* head = initNode();

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
        }
    }
}
