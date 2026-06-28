#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct List{
	char url;
	struct List *next;
}HistoryList;

struct List* initializeTest(){
	struct List *head = (struct List*) malloc(sizeof(struct List));
	head->url = 'A';
	head->next = (struct List*)  malloc(sizeof(struct List));
	
	head->next->url = 'B';
	head->next->next = (struct List*)  malloc(sizeof(struct List));

	head->next->next->url = 'A';
	head->next->next->next = (struct List*)  malloc(sizeof(struct List));

	head->next->next->next->url = 'C';
	head->next->next->next->next = (struct List*)  malloc(sizeof(struct List));

	head->next->next->next->next->url = 'B';
	head->next->next->next->next->next = NULL;
	return head;
}

void printList(struct List* head){
	struct List* temp = head;
	while(temp != NULL){
		printf("%c\n", temp->url);
		temp = temp->next;
	}

}

int checkDuplicate(struct List* trackingHead, struct List* toCheck){
	struct List* temp = trackingHead;

	while (temp != NULL){
		printf("Temp: %c, Check: %c\n", temp->url, toCheck->url);
		if (temp->url == toCheck->url) return 1;	
		temp = temp->next;
	}

	return 0;
}

struct List* deduplicateKeepLast(struct List* head){
	struct List* temp = head;
	struct List* trackingHead = (struct List*)  malloc(sizeof(struct List)); 
	trackingHead->url = head->url;
	trackingHead->next = (struct List*) malloc(sizeof(struct List));

	struct List* trackingTemp = trackingHead->next;

	while(temp->next != NULL){
		int result = checkDuplicate(trackingHead, temp->next);
		if (result == 0){
			trackingTemp->url = temp->next->url;
			trackingTemp->next = (struct List*) malloc(sizeof(struct List));
			trackingTemp = trackingTemp->next;
		
			temp = temp->next;
		}
		if (result == 1){
			struct List* toDelete = temp->next;
			temp->next = temp->next->next;
			free(toDelete);
		}

		printf("%i\n", result);
	}
			

	return head;
}

int main(){
	struct List *head = initializeTest();	
	printList(head);
	deduplicateKeepLast(head);
	printList(head);

}


