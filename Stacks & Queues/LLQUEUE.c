#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<process.h>
struct node
{
    int info;
    struct node *next;
};
typedef struct node NodeType;
NodeType *rear, *front;
void insert(int);
void delet();
void display();
int main()
{
    rear = front = 0;
    int choice, item;
    do
    {
        printf("\n1.Insert \n2.Delete \n3.Display\n4:Exit\n");
        printf("enter ur choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("\nEnter the data:\n");
                scanf("%d",&item);
                insert(item);
                break;
            case 2:
                delet();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(1);
                break;
            default:
                printf("invalid choice\n");
                break;
        }
    }while(choice<5);
    getch();
}
/**************insert function*******************/
void insert(int item)
{
    NodeType *nnode;
    nnode=( NodeType *)malloc(sizeof(NodeType));
    if(rear==0)
    {
        nnode->info=item;
        nnode->next=NULL;
        rear=front=nnode;
    }
    else
    {
        nnode->info=item;
        nnode->next=NULL;
        rear->next=nnode;
        rear=nnode;
    }
}
  /******************delet function********************/
  void delet()
{
    NodeType *temp;
    if(front==0)
    {
        printf("Queue contain no elements:\n");
        return;
    }
    else if(front->next==NULL)
    {
        temp=front;
        rear=front=NULL;
        printf("\nDeleted item is %d\n",temp->info);
        free(temp);
    }
    else
    {
        temp=front;
        front=front->next;
        printf("\nDeleted item is %d\n",temp->info);
        free(temp);
    }
}

/**************display function***********************/
void display()
{
    NodeType *temp;
    if(front==0)
    {
        printf("Queue contain no elements:\n");
        return;
    }
    temp=front;
    printf("\nqueue items are:\t");
    while(temp!=NULL)
    {
        printf("%d\t",temp->info);
        temp=temp->next;
    }
}
