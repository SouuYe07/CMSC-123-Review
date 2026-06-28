#include <stdio.h>
#define LIMIT 9

void printArray(int arrayStack[LIMIT]){
    for (int i = 0; i < LIMIT; i++){
        printf("%i ", arrayStack[i]);
    }
    printf("\n");
}

int chooseArray(){
    int choice;
    while (1){
        printf("Choose array to do your operation: ");
        scanf("%i", &choice);
        printf("\n");

        if (choice <= 3 && choice >= 1) return choice;
    }
}

void append(int arrayStack[LIMIT], int tracker[3]){
    int toAppend = 0, arrayNumber;
    arrayNumber = chooseArray();

    while (toAppend == 0){
        printf("Enter non-zero number to append to array %i: ", arrayNumber);
        scanf("%i", &toAppend);
    }

    switch (arrayNumber){
        case 1:
            arrayStack[tracker[0]] = toAppend;
            tracker[0]++;
            break;
        case 2:
            if (tracker[2] >= LIMIT) 
        case 3:
            arrayStack[tracker[2]] = toAppend;
            tracker[2]--;
            break;
    }
    printArray(arrayStack);
}

void initArray(int arrayStack[LIMIT]){
    for (int i = 0; i < LIMIT; i++){
        arrayStack[i] = 0;
    }
}

int main(){    
    int choice, middle;
    int arrayStack[LIMIT]; 

    initArray(arrayStack);

    middle = LIMIT / 2;
    if (LIMIT % 2 != 0){
        middle += 1;
    }
    int tracker[3] = {0, middle, LIMIT - 1};

    while(1){
        printf("=== Menu ===\n");
        printf("[1] Append\n");
        printf("[2] Pop\n");
        printf("[3] Print Stacks\n\n");
        printf("Enter choice: ");
        
        scanf("%i", &choice);
        switch (choice){
            case 1:
                append(arrayStack, tracker);
                break;
            case 2:
                printf("pop\n");
                break;
            case 3:
                printf("print\n");
                break;
        }
    }
}
