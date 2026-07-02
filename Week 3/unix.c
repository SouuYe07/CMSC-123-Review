#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define DIRECTORY 1
#define FILE 2

typedef struct Directory{
    char filename[20];
    struct Directory* firstChild;
    struct Directory* nextSibling;
    int fileType;
} Node;

struct Directory* initializeNode(){
    struct Directory* newNode = (struct Directory*)malloc(sizeof(struct Directory));
    newNode->firstChild = NULL;
    newNode->nextSibling = NULL;

    return newNode;
}

void addLastSibling(struct Directory** head, struct Directory* newNode){
    struct Directory* temp = (*head);

    while(temp->nextSibling != NULL) temp = temp->nextSibling;
    temp->nextSibling = newNode;
}

void createItem(struct Directory* currentDirectory){
    char choice;
    char filename[20];
    struct Directory *newNode = initializeNode();

    while(1){
        printf("Create [D]irectory or [F]ile? ");
        scanf(" %c", &choice);

        if (toupper(choice) == 'F'){
            newNode->fileType = FILE;
            break;
        }
        else if (toupper(choice) == 'D'){
            newNode->fileType = DIRECTORY;
            break;
        }
    }
    
    printf("Enter name: ");
    scanf(" %19[^\n]", newNode->filename);

    if (currentDirectory->firstChild == NULL) currentDirectory->firstChild = newNode;
    else addLastSibling(&(currentDirectory)->firstChild, newNode);
    printf("%s\n\n\n", currentDirectory->firstChild->nextSibling->filename);
}

void listContent(struct Directory* head){
    if (head == NULL) return;

    while (head != NULL){
        if (head->fileType == DIRECTORY) printf("/");
        printf("%s\n", head->filename);
        head = head->nextSibling;
    }
}

int main(){
    struct Directory* root = (struct Directory*)malloc(sizeof(struct Directory));
    struct Directory* currentDirectory = initializeNode();
    strcpy(root->filename, "root");
    root->fileType = DIRECTORY;

    int choice;

    while(1){
        printf("*********************************\n");
        printf("Welcome to the MazeOS File System Simulator!\n");
        printf("*********************************\n");
        printf("Current Directory: /%s\n", currentDirectory->filename);
        printf("[1] Create Item (mkdir/touch) \n");
        printf("[2] List Contents (ls) \n");
        printf("[3] Change Directory (cd) \n");
        printf("[4] Print Path (pwd) \n");
        printf("[5] End Simulation \n");
        printf("Enter Choice: ");
        scanf(" %d", &choice);
        
        switch (choice){
            case 1:
                createItem(currentDirectory);
                break;
            case 2:
                listContent(currentDirectory->firstChild);
                break;
        }
        printf("\n");
    }
}
