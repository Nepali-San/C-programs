//In this program we inspect some basic uses of singly linked list 

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>


struct link{  
	int item;
	struct link *next;
};

typedef struct link node;

node *start = NULL;

void Erase(){    //to free every allocated memory before exiting the program
	node *p;     //this function is not needed you can skip it & directly exit the program
	p = start;   //go to switch case of main function if you didn't get it
	while(p != NULL){
		start = start->next;
		free(p);
		p = start;
}
}

void InsertAtBeginning(){
	node *temp;
	temp = (node *) malloc(sizeof(node));
	printf("\n\nEnter a number\t");
	scanf("%d",&temp->item);
	if(start == NULL){   //Don't worry  (if) condition is not needed , you can simply use code of else part without any conditions
		temp->next = NULL;
		start = temp;
	}
	else{
		temp->next = start;
		start = temp;
	}
}

void Traverse(){  
	node *p;       
	int i;
	p = start;
	if(start == NULL){
		printf("\n\n*****List is empty*****\n\n");
		return;
	}
	else{
		printf("\n\nList is :\n\n");
		while(p!=NULL){
			printf("%d. %d\n",i++,p->item);
			p = p->next;
		}
	}
}
	
void DeleteFromEnd(){
node *loc,*p;
if(start == NULL){
	printf("\n\n*****Empty List*****\n\n");
}
else if(start->next == NULL){
	 p = start;
	 start = start->next;
	 printf("\n\nDeleted item is %d\n\n",p->item);
	 free(p);
}
else{
	loc = start;
	p = start->next;
	while(p->next != NULL){
		loc = p;
		p = p->next;
	}
	loc->next = NULL;
	printf("\n\nDeleted item is %d\n\n",p->item);
	free(p);
}
}

void InsertAtEnd(){
node *temp,*p;
temp = (node*) malloc (sizeof(node));
printf("\n\nEnter a number:\t");
scanf("%d",&temp->item);
temp->next = NULL;
if(start == NULL){	
	start = temp;
}
else{
	p = start;
	while(p->next != NULL){
		p=p->next;
	}	
	p->next = temp;
}
}
	
void DeleteFromBeginning(){   
	node *temp;
	temp = start;
	if(start == NULL){
		printf("\n\n*****Empty list*****\n\n");
	}
	else{
		start = start->next;
		printf("\n\nDeleted item is %d\n\n",temp->item);
		free(temp);
	}
}

//little bit messy are specific ones
void DeleteSpecific(){  //Hurray ! this can do the work of deleting from beginning as well as end also
	node *prev,*current;
	int loc,i;
	if(start == NULL){
		printf("\n\n*****Empty list*****\n\n");
		return;
	}
	printf("\n\nEnter the location \t");
	scanf("%d",&loc);
	if(loc == 0){
		DeleteFromBeginning(); //use if your program contains the function to delete from beginning[i.e. DeleteFromBeginning()] else write the code of this fuction instead
		return;
	}
	current = start;
	for(i=0;i<loc;i++){
		if(current == NULL){
			printf("\n\n***Location is out of list***\n\n");
			return;
		}
		prev = current;
		current = current->next;
	}
    	prev->next = current->next;
		printf("\nDeleted item is %d\n",current->item);
		free(current);
}

void InsertSpecific(){
	node *p,*q;
	int loc,i;
	q = (node *)malloc(sizeof(node));
	printf("\n\nEnter the position to insert\n\n");
	scanf("%d",&loc);	
		if(loc == 0){                //here either  A or (1,2,3,4) both will work but use one at a time
			//InsertAtBeginning();  //(A
			q->next = start;           //(1
			start = q;                 //(2
			printf("\nEnter the item \t");  //(3
         	scanf("%d",&q->item);       //(4
			return;
	    }
	for(i=0,p=start;i<loc-1;i++){
	if(p == NULL){
		printf("\nCan't access outside the list.......\n");
		return;
	}
	p = p->next;
}
	printf("\nEnter the item \t");
	scanf("%d",&q->item);
q->next = p->next;
p->next = q;
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
	printf("Option = \t");
	opt = getche();
	switch(opt){
		case '1':
			InsertAtBeginning();
			break;
			case '2':
				InsertAtEnd();
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
						DeleteFromEnd();
						break;
						  case '7':
						  	DeleteSpecific();
						  	break;
							case '8':
								Erase();  //I already told Erase() is not needed just because it is good to free memory space before exiting the program.
								exit(0);
								break;
							}
						}while(1);
						getch();
						return 1;
				}
				
//By SAN
