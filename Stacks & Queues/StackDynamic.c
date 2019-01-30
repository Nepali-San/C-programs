
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void push();
void display();
void pop();

struct stack{
	int item;
	struct stack *next;
}*top = NULL;

typedef struct stack st;

int main(){
	
	do{
	printf("\n\nEnter a option:\n______1. push______\n______2. pop______\n______3. display______\n______4. exit______");
	printf("\n\nOption = \t");
	char opt = getche();
	switch(opt){
		case '1':
			push();
			break;
			case '2':
				pop();
				break;
				case '3':
					display();
					break;
					case '4':
						exit(1);
						break;
						default:
							printf("\nEnter valid option\n");
			            }
   }while(1);
					getch();
					return 0;
}
				
void push(){
	int a;
	st * temp;
	temp = (st*) malloc (sizeof(temp));
	printf("\nEnter a number:\t");
	scanf("%d",&a);
 	temp->item = a;
 	temp->next = top;
 	top = temp;
 }
 
 void display(){
 	st *p;
 	p = top;
 	printf("\n\n*****TRAVERSE*****\n");
 	while(p!=NULL){
 		printf("\n NO. = %d ",p->item);
 		p = p->next;
 	}
 	if(top == NULL){
 		printf("\nStack empty\n");
 	}
 }
	
 void pop(){
	st * p;
	p = top;
	if(top == NULL){
	printf("\n\nstack is empty");
   }
   else{
	top = top->next;
	printf("\n\nThe poped element is %d",p->item);
	free(p);
  }
}
