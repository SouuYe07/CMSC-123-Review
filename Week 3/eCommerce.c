#include <stdio.h>

struct node{
    int id;
    int quantity;
    struct node *leftChild;
    struct node *rightChild;
};

int main(void){
    int choice;

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
                
        }
    }
}
