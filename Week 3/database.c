#include <stdio.h>
#include <stdlib.h>

struct node{
    int id;
    int height;
    struct node *leftChild;
    struct node *rightChild; 
};



void insert(struct node* head, int id){
    if (head == NULL){
        head = (struct node*)malloc(sizeof(struct node));
        head->leftChild = NULL;
        head->rightChild = NULL;
        head->id = id;
        head->height = -1;
    }
    else if(id < head->id) insert(head->leftChild, id);
    else if(id > head->id) insert(head->rightChild, id);
    head->height++;
}

void insertUser(struct node** head){
    int id, quantity;
    printf("Enter User ID: ");
    scanf("%d", &id);

    insert(*head, id);
}

int main(void){
    int choice;
    struct node* head = NULL;

    while(1){
        printf("*********************************\n");
        printf("Welcome to the MazeDB Indexing Engine!\n");
        printf("*********************************\n");
        printf("[1] Insert User ID\n");
        printf("[2] Display Database Structure\n");
        printf("[3] Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice){
            case 1:
                insertUser(&head);
        }
    }
    return 0;
}
