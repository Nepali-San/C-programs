//Wap to implement doubly linked list

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct link{
	int item;
	struct link *prev;
	struct link *next;
};

typedef struct link node;

node *start = NULL, *last = NULL;

void Traverse(){
	node *p;
	p = start;
	if(start == NULL){
		printf("\n\n***Empty list***\n\n");
		return;
	}
	printf("\n\nThe list is:\n\n");
	while(p != NULL){
		printf("%d\n",p->item);
		p = p->next;
	}
}

void Reverse(){
	node *p;
	p = start;
	if(start == NULL){
		printf("\n\n***Empty list***\n\n");
		return;
	}
	printf("\n\nThe reverse list is:\n\n");
	while(p->next != NULL){   //To access the address of last node
		p = p->next;
	}
	
	while(p != NULL){      //traversing from last node to it's previous node until NULL
		printf("%d\n",p->item);
		p = p->prev;
	}
}

void InsertAtBeginning(){
	node *p;
	p = (node *) malloc (sizeof(node));
	printf("\n\nEnter a item:\t");
	scanf("%d",&p->item);
	if(start == NULL){
		p->next = NULL;
		p->prev = NULL;
		start = p;
	}
	else{
		p->next = start;
		p->prev = NULL;
		start->prev = p;
		start = p;
	}
} 

void InsertAtLast(){
	node *p,*q;
	p = (node *) malloc (sizeof(node));
	printf("\n\nEnter the item:\t");
	scanf("%d",&p->item);
	if(start == NULL){
		p->next = NULL;
		p->prev = NULL;
		start = p;		
	}
	else{
		q = start;
		while(q->next != NULL){
			q = q->next;
		}
		q->next = p;
		p->prev = q;
		p->next = NULL;
	}
}

void DeleteFromBeginning(){
	node *p;
	p = start;
	if(start == NULL){
		printf("\n\n***Empty list***\n\n");
	}
	else if(start->next == NULL){
		printf("\n\nDeleted item is %d\n\n",p->item);
		start = NULL;
	}
	else{
		start = start->next;
		start->prev = NULL;
		printf("\n\nDeleted item is %d\n\n",p->item);
	}
	free(p);
}

void InsertSpecific(){
	int loc,i;
	node *p,*q;
	p = (node *) malloc (sizeof(node));
	printf("\n\nEnter the location :\t");
	scanf("%d",&loc);
	printf("\nEnter the item:\t");
	scanf("%d",&p->item);
	if(loc == 0){
		//InsertAtBeginning();
		if(start == NULL){
			start = p;
			p->next = NULL;
			p->prev = NULL;
		}
		else{
			p->next = start;
			p->prev = NULL;
			start->prev = p;
			start = p;
		}
		return;
	}
	for(i=0,q=start;i<loc-1;i++){
		q = q->next;
		if(q == NULL){
			printf("\n\nLocation is out list\n\n");
			return;
		}
	}
	p->next = q->next;
	q->next = p;
	p->prev = q;
	return;
}

void DeleteSpecific(){
	int loc,i;
	node *previous,*current;
	if(start == NULL){
		printf("\n\n*****Empty list*****\n\n");
		return;
	}
	previous = start;
	current = start->next;
	printf("\n\nEnter the location to delete:\t");
	scanf("%d",&loc);
	if(loc == 0){
		printf("\nDeleted item is %d\n",start->item);
		if(current == NULL){
			start = NULL;  //free(start); freeing  null pointer, no action of free() occurs for NULL
		}
		else{
			start = current;
			start->prev = NULL;
		}
		free(previous);
		return;
	}
	else{
		for(i=0;i<loc-1;i++){
			previous = current;
			current = current->next;
			if(current == NULL){
				printf("\nLocation is not in range.\n");
				return;
			}
		}
		printf("\nDeleted item is %d\n",current->item);
			previous->next = current->next;
			if(current->next != NULL)   //imagine if you are deleting the last node
			current->next->prev = previous;
			free(current);	
	}
	return;
}

//this function can use the property of being doubly so that code becomes easier 
//See c++ version of DLL
void DeleteFromLast(){
	node *previous,*current;  //we can easily go to previous node without having extra pointer
	previous = start;
	if(start == NULL){
		printf("\n\n***Empty list***\n\n");
		return;
	}
	current = start->next;
	if(current == NULL){  //for only one item in list
		printf("\n\nDeleted item is %d\n\n",previous->item);
		free(previous);
		start = NULL;
		return;
	}
	while(current->next != NULL){
		previous = current;
		current = current->next;
	}
	printf("\n\nDeleted item is %d\n\n",current->item);
	previous->next = NULL;
	free(current);
	return;
}

int main(){
	char opt;
	do{
		printf("\n\nEnter your option:\n\n");
	    printf("-> 1 Insert at beginning\n");
	    printf("-> 2 Insert at end\n");
	    printf("-> 3 Insert at specific position\n");
     	printf("-> 4 Traverse\n");
     	printf("-> 5 Delete from beginning\n");
    	printf("-> 6 Delete from end\n");
    	printf("-> 7 Delete from specific position\n");
    	printf("-> 8 Reverse traverse the list\n");
    	printf("-> 9 Exit\n\n");
		printf("\noption  = ");
		opt = getche();
		switch(opt){
			case '1':
				InsertAtBeginning();
				break;
				case '2':
					InsertAtLast();
					break;
					case '3':
						InsertSpecific();
						break;
						case '4':
							Traverse();
							break;
							case '5':
								DeleteFromBeginning();
								break;
								case '6':
									DeleteFromLast();
									break;
									case '7':
										DeleteSpecific();
										break;
									    case '8':
									      Reverse();
									      break;
										    case '9':
									            exit(1);
										    	break;
									          		default:
												    printf("\n\nPlease enter a valid option\n\n");
		}
	}while(1);
	return 0;
}
