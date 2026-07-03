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
    struct Directory* parent;
    int fileType;
} Node;

struct pwdList{
    char filename[20];
    struct pwdList *next;
};

struct Directory* initializeNode(){
    struct Directory* newNode = (struct Directory*)malloc(sizeof(struct Directory));
    newNode->firstChild = NULL;
    newNode->nextSibling = NULL;
    newNode->parent = NULL;

    return newNode;
}

void addLastSibling(struct Directory** head, struct Directory* newNode){
    struct Directory* temp = (*head);

    while(temp->nextSibling != NULL) temp = temp->nextSibling;
    temp->nextSibling = newNode;
}

void printer(struct Directory* currentDirectory){
    if (currentDirectory->parent != NULL){
        printer(currentDirectory->parent);
    }
    printf("/%s", currentDirectory->filename);
}

void createItem(struct Directory* currentDirectory){
    char choice;
    char filename[20];
    struct Directory *newNode = initializeNode();
    newNode->parent = currentDirectory;

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
}

void listContent(struct Directory* head){
    while (head != NULL){
        if (head->fileType == DIRECTORY) printf("/");
        printf("%s\n", head->filename);
        head = head->nextSibling;
    }
}

struct Directory* changeDirectory(struct Directory* currentDirectory){
    printf("Enter destination directory: ");
    char filename[20];
    scanf(" %19[^\n]", filename);

    if (strcmp(filename, "..") == 0){
        if (strcmp(currentDirectory->filename, "root") == 0){
            printf("No parent from root directory\n");
        }
        printf("Successfully changed directory to %s/\n", currentDirectory->parent->filename);
        return currentDirectory->parent;
    }

    struct Directory* temp = currentDirectory->firstChild;

    while(temp != NULL){
        if (strcmp(filename, temp->filename) == 0){ 
            if (temp->fileType == DIRECTORY){
                printf("Successfully changed directory to %s/\n", temp->filename);
                return temp;
            }
            else{
                printf("Error: '%s' is a file, cannot change directory!\n", temp->filename);
                return currentDirectory;
            }
        }
        temp = temp->nextSibling;
    }
    printf("No valid directory found\n");
    return currentDirectory;
}

void printPath(struct Directory* currentDirectory){
    printer(currentDirectory);
    printf("/\n");
    return;
}

int main(){
    struct Directory* root = initializeNode();
    strcpy(root->filename, "root");
    root->fileType = DIRECTORY;
    struct Directory* currentDirectory = root;

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
        printf("[5] End Simulation (sudo shutdown)\n");
        printf("Enter Choice: ");
        scanf(" %d", &choice);
        
        switch (choice){
            case 1:
                createItem(currentDirectory);
                break;
            case 2:
                listContent(currentDirectory->firstChild);
                break;
            case 3:
                currentDirectory = changeDirectory(currentDirectory);
                break;
            case 4:
                printPath(currentDirectory);
                break;
            case 5:
                printf("Terminating. ");
        }
        printf("\n");
    }
}
