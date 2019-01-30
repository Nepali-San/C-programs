//Wap to implement basic operation on singly circular linked list

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct link{
	int item;
	struct link *next;
};

typedef struct link node;

node *start=NULL,*last = NULL;

void InsertAtBeginning(){
	node *p;
	p = (node *)malloc(sizeof(node));
	printf("\nEnter a number:\t");
	scanf("%d",&p->item);
	if(start == NULL){
	start = p;
	last = p;
	last->next = p;
   }
   else{
   	p->next = start;
   	start = p;
   	last->next = p;
   }
}

void InsertAtLast(){
	node *p;
	p = (node *) malloc(sizeof(node));
	printf("\n\nEnter a number:\t");
	scanf("%d",&p->item);
	if(start== NULL){
	start = p;
	last = p;
	last->next = p;
	}
	else{
		last->next = p;
		last = p;
		last->next = start;
	}
	return;
}

void InsertSpecific(){
	node *p,*current;
	int loc,i;
	p = (node *)malloc(sizeof(node));
	printf("\n\nEnter the location to insert value:\t");
	scanf("%d",&loc);
	if(loc == 0){
		InsertAtBeginning();
	}
	else{
		current=start;
		if(current == NULL){
			printf("\n\n*****Location is out of list*****\n\n");
			return;
		}
		for(i=0;i<loc-1;i++){
			current = current->next;
			if(current == start){
				printf("\n\n*****Location is out of list*****\n\n");
				return;
			}
		}
		    printf("Enter the value:\t");
	        scanf("%d",&p->item);
			p->next=current->next;
			current->next = p;
		  if(p->next == start){
			last = p;
		}
	}
	return;
}

void DeleteFromBeginning(){
	node *temp;
	temp = start;
	if(start == NULL){  //if no element 
		printf("\n\n*****List is empty*****\n\n");
	}
	else if(start->next == start){   //if the circular list has only one element
		printf("\n\nDeleted item is %d\n\n",temp->item);
		free(temp);
		start = NULL;
		last = NULL;
	}
	else{  //if above two conditions doesn't hold
	start = start->next;
	last->next = start;
	printf("\n\nDeleted item is %d\n\n",temp->item);
	free(temp);
    }
	return;
}

void DeleteFromLast(){
	node *prev,*current;
	
	if(start == NULL){
		printf("\n\n***Empty List***\n\n");
		return;
	}
	
	prev = start;
	current = start->next;  //You can put prev above <if(start == NULL)> but not for current;
	
	if(prev == current){   //i.e if only one node is present, that is to be deleted
		start = NULL;
		last = NULL;
	}
	else{	
	
	   do{
		prev = current;
		current = current->next;
	    }while(current!=last);
	
		prev->next = start;
		last = prev;
}
	printf("\n\nDeleted element is %d\n\n",current->item);
	free(current);
	return;
}

void DeleteSpecific(){
	node *prev,*current;
	int i,loc;
	if(start == NULL){
		printf("\n\nList is empty.\n\n");
		return ;
	}
	printf("\n\nEnter the desired location:\t");
	scanf("%d",&loc);
	if(loc == 0){
		DeleteFromBeginning();
		return;
	}
	for(i=0,current=start;i<=loc-1;i++){
		prev = current;
		current = prev->next;
		if(current ==  start){
		  printf("\n\nLocation is out of list\n\n");
		  return;
		}
	}
		prev->next = current->next;
		printf("\nSuccessfully deleted %d",current->item);
		if(current == last ){
		last = prev;
	}
	free(current);
	return;
}

void Traverse(){
	node *p;
	p = start;
	int i = 0;
	if(start == NULL){
		printf("\n\n***Empty List***\n\n");
		return;
	}
	printf("\n\nThe list is :\n\n");
	do{
		printf("\n%d) %d",i++,p->item);
		p = p->next;
	}while(p!=start);
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
    	printf("-> 8 Exit\n\n");
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
									      exit(1);
											break;
		}
	}while(1);
	return 0;
}
