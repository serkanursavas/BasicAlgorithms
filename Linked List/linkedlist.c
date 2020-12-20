#include <stdio.h>
#include <stdlib.h>
//Doubly Linked List
struct node
{
	struct node *prev;
	int data;
	struct node *next;
};

struct node *head = NULL;
struct node *tail = NULL;

void display();
void insert_beg();
void insert_end();
void delete_beg();
void delete_end();
void insert_after();
void insert_before();
void delete_key();
void sort(struct node* head);

void main() {
	int option;
	do
	{
		printf("\n\n 1: Display the list");
		printf("\n 2: Insert at the beginning");
		printf("\n 3: Insert at the end");
		printf("\n 4: Delete from the beginning");
		printf("\n 5: Delete from the end");
		printf("\n 6: Insert after");
		printf("\n 7: Insert before");
		printf("\n 8: Delete key");
		printf("\n 9: Sort List");

		printf("\n 0: EXIT");
		printf("\n\n Enter your option : ");
		scanf_s("%d", &option);
		switch (option)
		{
			case 1: display();	  break;
			case 2: insert_beg(); break;
			case 3: insert_end(); break;
			case 4: delete_beg(); break;
			case 5: delete_end(); break;
			case 6: insert_after(); break;
			case 7: insert_before(); break;
			case 8: delete_key(); break;
			case 9: sort(head); break;
		}
	} while (option != 0);
	return;
}

void display(){
	struct node *ptr = tail;
	if (ptr == NULL)
	{
		printf("\nList is empty!");
	}
	else{
		while(ptr != NULL)
		{
			printf("\t%d", ptr->data);
			ptr = ptr->prev;
		}
	}
	printf("\n");
}

void insert_beg(){
	struct node *ptr;
	ptr = (struct node *)malloc(sizeof(struct node));

	if (ptr == NULL)
	{
		printf("\nThere is an error in Malloc!");
	}
	else{
		printf("\nEnter the node data value: ");
		scanf_s("%d",&ptr->data);

		if (head == NULL)
		{
			ptr->next = NULL;
			head = ptr;
			tail = head;
		}
		else{
			ptr->prev = NULL;
			ptr->next = head;
			head->prev = ptr;

			head = ptr;
		}
	}
}

void insert_end(){
	struct node *ptr;
	ptr = (struct node *)malloc(sizeof(struct node));

	if (ptr == NULL)
	{
		printf("\nThere is an error in Malloc!");
	}
	else{
		printf("\nEnter the node data value: ");
		scanf_s("%d",&ptr->data);

		if (head == NULL)
		{
			ptr->prev = NULL;
			ptr->next = NULL;
			head = ptr;
			tail = head;
		}
		else{
			struct node *temp = head;
			while(temp->next != NULL){
				temp = temp->next;
			}
			temp->next = ptr;
			ptr->prev = temp;
			ptr->next = NULL;
			tail = ptr;
		}
	}
}

void delete_beg(){
	struct node *ptr=head;
	if (head == NULL)
	{
		printf("\nThere isn't any element in the list!");
	}
	else{
		head = head->next;
		ptr->next = NULL;
		head->prev = NULL;
		free(ptr);
		printf("\nFirst node is deleted!");
	}
}

void delete_end(){
	struct node *ptr, *temp;
	if (head == NULL)
	{
		printf("\nThere isn't any element in the list!");
	}
	else if(head->next == NULL){
		free(head);
		head = NULL;
		tail = NULL;
	}
	else{
		temp = head;
		ptr = temp->next;

		while(ptr->next !=NULL){
			temp = temp->next;
			ptr = ptr->next;
		}
		temp->next = NULL;
		ptr->prev = NULL;
		free(ptr);
		tail = temp;
	}
}

void insert_after(){
	//read two value from the user. Find the first value and insert the second value after first value's location.

	int key;
	printf("\n ------------------------------------------\n\n Enter the value you want to add next to it: ");
	scanf_s("%d", &key);

	struct node* newPtr;
	newPtr = (struct node*)malloc(sizeof(struct node));
	printf("\n -------------------------\n\n Enter the new data value: ");
	scanf_s("%d", &newPtr->data);

	struct node* ptr = tail;
	if (ptr == NULL)
	{
		printf("\n -------------\n\n List is empty!");
	}
	else {
		while (ptr != NULL)
		{
			if (ptr->data == key) {

				struct node* temp = ptr->next;
				if (ptr->next != NULL)
				{
					newPtr->next = temp;
					newPtr->prev = ptr;
					ptr->next = newPtr;
					temp->prev = newPtr;
					printf("\n -------------------------------------\n\n The new value added between two nodes.");
					break;
				}
				else
				{
					newPtr->next = NULL;
					newPtr->prev = ptr;
					ptr->next = newPtr;
					tail = newPtr;
					printf("\n ---------------------------\n\n The new value added to tail.");
					break;
				}

			}
			if (ptr->prev == NULL) {
				printf("\n ---------------------------------------------------------------------\n\n The value that you want to add next to it is not found in the list...");
				break;
			}
			ptr = ptr->prev;
		}
	}
	printf("\n");

}
void insert_before(){
	//read two value from the user. Find the first value and insert the second value before first value's location.

	int key;
	printf("\n -------------------------------------------\n\n Enter the value you want to add next to it: ");
	scanf_s("%d", &key);

	struct node* newPtr;
	newPtr = (struct node*)malloc(sizeof(struct node));
	printf("\n --------------------------\n\n Enter the new data value: ");
	scanf_s("%d", &newPtr->data);

	struct node* ptr = tail;
	if (ptr == NULL)
	{
		printf("\n --------------\n\n List is empty!");
	}
	else {
		while (ptr != NULL)
		{
			if (ptr->data == key) {
				struct node* temp = ptr->prev;
				if (ptr->prev != NULL)
				{
					newPtr->prev = temp;
					newPtr->next = ptr;
					ptr->prev = newPtr;
					temp->next = newPtr;
					printf("\n --------------------------------------\n\n The new value added between two nodes.");
					break;
				}
				else
				{
					newPtr->prev = NULL;
					newPtr->next = ptr;
					ptr->prev = newPtr;
					head = newPtr;
					printf("\n ----------------------------\n\n The new value added to head.");
					break;
				}
			}
			if (ptr->prev == NULL) {
				printf("\n ---------------------------------------------------------------------\n\n The value that you want to add next to it is not found in the list...");
				break;
			}
			ptr = ptr->prev;
		}
	}
	printf("\n");
}
void delete_key(){
	//read a key from the user and delete that key from the list if it is in the list.

	int key;
	printf("\n -----------------------------------\n\n Enter the value you want to delete: ");
	scanf_s("%d", &key);

	struct node* ptr = tail;
	if (ptr == NULL)
	{
		printf("\n --------------\n\n List is empty!");
	}
	else {
		while (ptr != NULL)
		{
			if (ptr->data == key) {
				if (ptr == head)
				{
					ptr->next->prev = NULL;
					head = ptr->next;
					free(ptr);
					printf("\n ---------------------------\n\n The first node is deleted..");
					break;
				}
				else if (ptr == tail) {
					ptr->prev->next = NULL;
					tail = ptr->prev;
					free(ptr);
					printf("\n --------------------------\n\n The last node is deleted..");
					break;
				}
				else
				{
					ptr->prev->next = ptr->next;
					ptr->next->prev = ptr->prev;
					free(ptr);
					printf("\n ---------------------\n\n The node is deleted..");
					break;
				}
			}
			if (ptr->prev == NULL) {
				printf("\n -------------------------------------------------------------\n\n The value that you want to delete is not found in the list...");
				break;
			}
			ptr = ptr->prev;
		}
	}
	printf("\n");
}
void sort(struct node* head){
	//any kind of sort is acceptable BUBBLE QUICK MERGE etc.

	// Selection Sort Algorithm
	struct node* currentVal = head;

	while (currentVal != NULL){
		struct node* min = currentVal;
		struct node* nextVal = currentVal->next;

		while (nextVal != NULL){
			if (min->data > nextVal->data) {
				min = nextVal;
			}
			nextVal = nextVal->next;
		}
		int temp = currentVal->data;
		currentVal->data = min->data;
		min->data = temp;
		currentVal = currentVal->next;
	}
	printf("\n ----------------------------------------------------\n\n Linked list sorted with --SELECTION SORT ALGORITHM--");
}
