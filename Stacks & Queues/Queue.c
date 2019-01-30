
#include<stdio.h>
#include<conio.h>

int isfull();
int isempty();
#define SIZE 10

int queue[SIZE];
int front = 0,rear = -1;

void adder();
void display();
void remover();
void reset();

int main(){
	
char op;
int flag = 1;

do{
   
   printf("\n\nEnter a option :\n 1 to add \n 2 to delete\n");
   printf(" 3 to display\n 4 to reset queue\n Else other keys to exit\n");
   printf("\noption = \t"); 
   op = getche(); 
   
   switch(op)
   {
   	case '1':
   		adder();
   		break;
   		case '2':
   			remover();
   			break;
   			  case '3':
   			  	display();
   			  	break;
   			  	  case '4':
   			  	  	reset();
   			  	  	 break;
   			     default:
   				  flag = 0;
   				   break;
}
}while(flag);
	return 0;
}

void adder()
{
	if(isfull()){
		printf("\nQueue OVERflow\n");
		}
		else{
	printf("\n\nEnter the element for queue\n");
	scanf("%d",&queue[++rear]);
    }
}

void remover()
{
	if(isempty()){
		printf("\nQueue underflow");
		}
		else{
	printf("\n\nRemove element is %d\n\n",queue[front]);
	front++;
      }
}
    
    void display(){
    	int i;
    	if(isempty()){
		printf("\nEmpty Queue");
		}
		else{
    	printf("\n\nThe elements of queue are:\n\n");
    	for(i=front;i<=rear;i++)
    	{
    		printf("%d\n",queue[i]);
    	}
    }
   }
   
   void reset(){
   	front= 0;
   	rear = -1;
   }
   
   int isfull(){
   	if(rear > SIZE - 1)
	   return 1;
	   else
	   return 0;
}
	   
	   int isempty(){
	   	if(rear<front)
	   	return 1;
	   	else 
	   	return 0;
	   }
