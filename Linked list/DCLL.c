//Wap to implement basic operation of circular doubly linked list

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct link{
	int item;
	struct link *next;
	struct link *prev;
};

typedef struct link node;

node *start = NULL,*last = NULL;

void InsertAtBeginning(){
	node *p;
	p = (node *) malloc(sizeof(node));
	printf("\n\nEnter the number:\t");
	scanf("%d",&p->item);
	if(start == NULL){
		start = p;
		last = p;
		p->next = p;
		p->prev = p;
	}
	else{
		p->next = start;
		start->prev = p; 
		start = p;
		p->prev = last;
		last->next = p;
	}
}

void Traverse(){
	node *p;
	p = start;
	int i = 0;
	if(start == NULL){
		printf("\n\n*****Empty list*****\n\n");
		return;
	}
	else{
		printf("\n\nThe list is:\n");
		do{
			printf("\n%d) %d",i,p->item);
			p = p->next;
			i++;
		}while(p!=start);
	}
}

int Counter(){
	node *p;
	int count = 0;
	p = start;
	if(start == NULL){
		count = 0;		
	}
	else{
		printf("\n\nThe list is:\n");
		do{
			p = p->next;
			count++;
		}while(p!=start);
	}
	return count;
}


void DeleteFromEnd(){
	if(start == NULL){
		printf("\n\n*****List is empty*****\n\n");
		return;
	}
	else if(last == start){      //if only one node is present
		printf("\n\nThe deleted item is %d\n\n",start->item);
		start = last = NULL;
		free(start);
	}
	else{
		node *temp;
		temp = last;
		last = last->prev;
		last->next = start;
		start->prev = last;
		printf("\n\nDelted item is %d\n\n",temp->item);
		free(temp);
	}
	return;
}

void InsertSpecific(){   
	node *p,*q;
	int loc,i;
	q = start;
	p = (node *)malloc(sizeof(node));
	printf("\n\nEnter the number:\t");
	scanf("%d",&p->item);
	printf("\nEnter the location:\t");
	scanf("%d",&loc);
	if(loc == 0){
	  if(start == NULL){
		start = p;
		p->next = p;
		p->prev = p;
		last = p;
	  }	
	  else{
	  	p->next = start;
	  	p->prev = last;
	  	start->prev = p;
	  	last->next = p;
	  	start = p;
	  }
	}
	else{
		if(q == NULL){
			printf("\nLocation overflow\n");
			return;
		}
		for(i=0;i<loc-1;i++){
			q = q->next;
			if(q == start){
				printf("\nLocation overflow\n");
				return;
			}
		}
		p->next = q->next;
		(q->next)->prev = p;
		q->next = p;
		p->prev = q;
	}
}

void DeleteSpecific(){  
	node *p,*q;
	p = start;
	int i,loc;
	if(start==NULL){
		printf("\n\n*****Empty list*****\n\n");
		return;
	}
	printf("\n\nEnter the location:\t");
	scanf("%d",&loc);
	if(loc == 0){
		printf("\n\nSuccessfully Deleted %d\n\n",start->item);
		if(start == last){
			start = NULL;
			last = NULL;
			free(p);
			return;
		}
		start = start->next;
		last->next = start;
		start->prev = last;
		free(p);
		return;
	}
	else{
		for(i = 0;i<loc;i++){
			q = p;
			p = p->next;
			if(p == start){
				printf("\nOverflow\n");
				return;
			}
		}
		q->next = p->next;
		(p->next)->prev = q;
		if(p->next == start)
		last = q;
		printf("\nSuccessfully Deleted %d\n",p->item);
		free(p);
	}
}

void DeleteFromBeginning(){
	node *temp;
	if(start == NULL){
		printf("\n\n*****List is empty*****\n\n");
	}
	else if(last == start){      //if only one node is present
		printf("\n\nThe deleted item is %d\n\n",start->item);
		start = last = NULL;
		free(start);
	}
	else{
		temp = start;
		start = start->next;
		start->prev = last;
		last->next = start;
		printf("\n\nThe deleted item is %d\n\n",temp->item);
		free(temp);
	}	
}

void ReverseList(){  //This function is helpful to know if previous link is correctly setup
	node *p;
	if(start == NULL){
		printf("\n\n*****List is empty*****\n\n");
		return;
	}	
	p = last;
	int i = 0;
	printf("\n\nTraversing the list in reverse order:\n");
	do{
		printf("\n %d",p->item);
		p = p->prev;
	}while(p != last);
}

void InsertAtEnd(){
	node *p;
	p = (node *)malloc(sizeof(node));
	printf("\n\nEnter the number:\t");
	scanf("%d",&p->item);
	if(start == NULL){
		start = p;
		p->next = p;
		p->prev = p;
		last = p;
	}
	else{
		last->next = p;
		p->next = start;
		p->prev = last;
		last = p;
		start->prev = last;
	}
}

int main(){
	int Count;
	char opt;
	do{
	printf("\n\nEnter your option:\n\n");
	printf("-> 0 Insert at beginning\n");
	printf("-> 1 Insert at end\n");
	printf("-> 2 Insert at specific position\n");
	printf("-> 3 Traverse\n");
	printf("-> 4 Count nodes\n");
	printf("-> 5 Delete from beginning\n");
	printf("-> 6 Delete from end\n");
	printf("-> 7 Delete from specific position\n");
	printf("-> 8 Reversely display the list\n");
	printf("-> 9 Exit\n\n");
	printf("Option = \t");
	opt = getche();
	switch(opt){
		case '0':
			InsertAtBeginning();
			break;
			case '1':
				InsertAtEnd();
				break;
				case '2':
					InsertSpecific();
					break;
				  case '3':
				     Traverse(); 
					break;
				     case '5':
					  DeleteFromBeginning();
					  break;
					   case '6':
						DeleteFromEnd();
						break;
						  case '7':
						  	DeleteSpecific();
						  	break;
							case '9':
								exit(0);
								break;
								case '8':
									ReverseList();
									break;
									case '4':
										Count = Counter();
										printf("\n\nNo. of nodes is %d\n",Count);
										break;
								default:
									printf("\n\nPlease enter a valid option\n\n");
							}
						}while(1);
						getch();
						return 1;
				}				
