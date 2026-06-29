#include <stdio.h>
#include <stdlib.h>

void initArray(int* queueArray, int currentSize){
    for (int i = 0; i < currentSize; i++) queueArray[i] = -1;
}

int* doubleArray(int* oldArray, int* currentSize, int* rear, int* front){
    int* newArray = (int *) malloc(sizeof(int) * *currentSize * 2);
    initArray(newArray, *currentSize * 2);
    int currentIndex = 0;

    for (int i = *front; i < *currentSize - 1; i++){
        newArray[currentIndex] = oldArray[i];
        currentIndex++;
    }

    for (int i = 0; i < *front - 1; i++){
        newArray[currentIndex] = oldArray[i];
        currentIndex++;
    }

    *front = 0;
    *rear = currentIndex;
    *currentSize *= 2;
    free(oldArray);
    return newArray;
}

void enqueue(int** queueArray, int* currentSize, int* rear, int* front){
    int packetID;

    printf("Enter Packet ID: ");
    scanf("%d", &packetID);

    if (*rear == *front && *queueArray[*rear] != -1){
        *queueArray = doubleArray(*queueArray, currentSize, rear, front);
    }

    (*queueArray)[*rear] = packetID;
    (*rear)++;

    if (*rear > (*currentSize - 1)) *rear = 0;
}

void dequeue(int *queueArray, int currentSize, int rear, int* front){
    if (queueArray[*front] == -1){
        printf("No items in queue yet.\n");
        return;
    }

    printf("Playing Packet: %i\n", queueArray[*front]);

    queueArray[*front] = -1;
    (*front)++;

    if (*front > currentSize) front = 0;
}

void display(int *queueArray, int currentSize, int rear, int front){
    if (rear > front){
        for (int i = front; i < rear; i++){
            if (queueArray[i] == -1) continue;
            printf("%i ", queueArray[i]);
        }
    }
    else {
        for (int i = front; i < currentSize - 1; i++){
            if (queueArray[i] == -1) continue;
            printf("%i ", queueArray[i]);
        }
        for (int i = 0; i < rear - 1; i++){
            if (queueArray[i] == -1) continue;
            printf("%i ", queueArray[i]);
        }
    }
    printf("\n");
}

int main(){
    int choice, front = 0, rear = 0, currentSize = 4;
    int *queueArray = (int *)malloc(sizeof(int) * 4);
   
    initArray(queueArray, currentSize);

    while (1){
        printf("*********************************\n");
        printf("Welcome to the MazeSteam Audio Buffer!\n");
        printf("*********************************\n");
        printf("[1] Enqueue Packet\n");
        printf("[2] Dequeue Packet (Play)\n");
        printf("[3] Display Buffer Status\n");
        printf("[4] End Simulation\n");

        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice){
            case 1:
                enqueue(&queueArray, &currentSize, &rear, &front);
                break;
            case 2:
                dequeue(queueArray, currentSize, rear, &front);
                break;
            case 3:
                display(queueArray, currentSize, rear, front);
                break;
            case 4:
                break;
        }
        printf("\n");
    }
}
