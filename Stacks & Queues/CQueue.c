
#include<stdio.h>
#include<conio.h>
#include<process.h>

#define MAXSIZE 5

int front = -1,rear = -1;
int Q[MAXSIZE];

void enqueue(){
	int num;
    if(isfull())
    {
    printf("\n***Queue is full***\n");
    }
    else
	{
		printf("\n\nEnter a element\n");
		scanf("%d",&num);
		if(front==-1)
		front = rear = 0;
		else
		rear = (rear+1) % MAXSIZE;
		Q[rear] = num;
	}
}

void dequeue(){
	int num;
	if(isempty())
	printf("\n\n***NO elements to delete***\n");
	else
	{
		num = Q[front];
		printf("\n\nDeleted element is %d\n",num);
		if(front==rear)
			front = rear = -1;
		else
		    front = (front + 1)%MAXSIZE;
		}
	}
	
void display(){
	int i;
	if(front != -1)
	{
		printf("\n\nThe elements of queue are:\n");
    	for(i = front; i != (rear); i = (i+1)%MAXSIZE)
	     {
	     printf(" %d\n",Q[i]);
         }
         printf(" %d\n",Q[rear]);
     }
    else
	   printf("\n\n***Queue is empty***\n");
}


int isfull(){
	int num;
    if(front == (rear+1) % MAXSIZE)
    return 1;
    return 0;
}


int isempty(){
	if(front == -1)
	return 1;
	return 0;
}


int main(){
   char opt;
	    while(1)
		{
		  printf("\n\nEnter your option :\n");
		  printf("_____1. Insert _____\n_____2. Delete_____\n_____3. Display_____\n_____4. Exit_____\n");
		  printf("\noption = \t");
		  opt = getche();
		  switch(opt)
	      {
			case '1':
				enqueue();
				break;
				case '2':
					dequeue();
					break;
					case '3':
						display();
						break;
						case '4':
							exit(5);
							break;
							default:
								printf("\n***Enter a valid option***\n");
	      }
    	}
  return 0;
}
