
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#define SIZE 6

int stack[SIZE], top= -1, i;

void push();
void pop ();
void traverse();


int main()
{
	int flag = 1;
	char opt;
	do    //for infinte looping of for loop
	{
	printf("\n\nChoose an option:\n 1) PUSH \n 2) PULL \n 3) TRAVERSE\n 4) EXIT.\n\n");
	printf("\noption = \t");
	opt = getche();
	switch(opt){
	case '1':
	push();
	break;
	case '2':
	pop ();
	break;
	case '3':
	traverse();
	break;
	case '4':
	flag = 0;
	break;
	default :
	printf("\n\n Invalid option,Please try again.\n\n");
	}
	
}while(flag);
		getch();
		return 0;
}

void push()
{
//	int check = isfull();
//	if(check == 1){
    if(isfull()){
		printf("\nStack is full\n");
	}
	else{
	top ++;
	printf("\n\nEnter a number:\t");
	int num;
	scanf("%d",&num);
	stack[top] = num;
     }
}
void pop ()
{
   // int check = isempty();
   //    if (check == 1){
if(isempty()){
    printf("\nStack is empty\n");
	}
	
	else{
		int num = stack[top];
		printf("\nDeleted element is %d\n\n",num); 
		top--;
	}
}
void traverse()
{
//	int check = isempty();
//	if(check == 1){
    if(isempty()){
	printf("\n\n Stack is empty.\n\n");
    }
	else{
	printf("\n\nThe stacks are:\n\n");
	for(i= top ;i>= 0;i--)
	printf("   %d\n",stack[i]);
	}
}
int isfull()
{
	if(top == SIZE-1)
    return 1;
	else
    return 0;
}
int  isempty()
{
	if(top == -1)
	return 1;
    else 
    return 0;
}
