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

struct node* deleteNode(struct node* head, int id){
    struct node *temp;
    struct node *child;

    if (head == NULL){
        printf("Head not found");
    }
    if (id < head->id){
        head->leftChild = deleteNode(head->leftChild, id);
    }
    else if (id > head->id){
        head->rightChild = deleteNode(head->rightChild, id);
    }
    else if (head->leftChild && head->rightChild){
        temp = findMin(head->rightChild);
        head->id = temp->id;
        head->rightChild = deleteNode(head->rightChild, head->id);
    }
    else {
        temp = head;
        if (head->leftChild == NULL){
            child = head->rightChild;
        }
        if (head->rightChild == NULL){
            child = head->leftChild;
        }
        free(temp);
        return child;
    }
    return head;
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

    *head = deleteNode(*head, id);

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
