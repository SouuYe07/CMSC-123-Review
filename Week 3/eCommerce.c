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

struct node* findNode(struct node* head, int id){
    if (head->id == id) return head;
    else if (id < head->id) return findNode(head->leftChild, id);
    else if (id > head->id) return findNode(head->rightChild, id);
    return NULL;
}

struct node* findMin(struct node* head){
    if (head->leftChild){
        return findMin(head->leftChild);
    }
    return head;
}

void insertToParent(struct node* parent, struct node* child, int isLeft){
    if(isLeft){
        head->leftChild = child;
    }
    else{
        head->rightChild = child;
    }
}

void deleteNode(struct node* head, int id){
    int isLeft;
    struct node *toDelete = NULL;

    if (head->leftChild->id == id){
        toDelete = head->leftChild;
        isLeft = 1;
    }
    else if(head->rightChild->id == id){
        toDelete = head->rightChild;
        isLeft = 0;
    }

    if (toDelete){
        if(toDelete->leftChild && toDelete->rightChild){
            if(isLeft){
                head->leftChild = findMin(toDelete->rightChild);
            }
            else{
                head->rightChild = findMin(toDelete->rightChild);
            }

            
        }

        free(toDelete);
    }

    if (id < head->id){
        deleteNode(head->leftChild, id);
    }
    else if (id > head->id){
        deleteNode(head->rightChild, id);
    }

    printf("Product not found. \n");
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

    printf("Enter Stock Quantity: ");
    scanf("%d", &quantity);


    toInsert->id = id;
    toInsert->quantity = quantity;

    return;
}

void findUpdate(struct node* head){
    int id, quantity, choice;
    printf("Enter Product ID to search: ");
    scanf("%i", &id);

    struct node* toUpdate = findNode(head, id);

    if (toUpdate == NULL){
        printf("Error: Product ID does not exist in the catalog..\n");
        return;
    }

    printf("Product Found! Current Stock Quantity: %i\n", toUpdate->quantity);
    printf("Would you like to update stock? (1-Yes / 0-No): ");
    scanf("%i", &choice);

    if (choice == 1){
        printf("Enter New Stock Quantity: ");
        scanf("%i", &quantity);
        toUpdate->quantity = quantity;
        printf("Stock updated.\n");
    }
}

void deleteProduct(struct node** head){
    int id;
    printf("Enter Product ID to delete: ");
    scanf("%d", &id);

    if ((*head)->id == id){
        free(*head);
        *head = NULL;
    }
    
    else deleteNode(*head, id);

    printf("Product deleted.\n");
}

void displayInventory(struct node* head){
    if (head == NULL){
        printf("Inventory is currently empty.\n");
        return;
    }
    if (head->leftChild != NULL) displayInventory(head->leftChild);
    
    printf("ID: %i | Quantity: %i\n", head->id, head->quantity);

    if (head->rightChild != NULL) displayInventory(head->rightChild);
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
                findUpdate(head);
                break;
            case 3:
                deleteProduct(&head);
                break;
            case 4:
                printf("--- Current Inventory (Inorder) ---\n");
                displayInventory(head);
                printf("***********************************\n");
                break;
        }
        printf("\n");
    }
}
