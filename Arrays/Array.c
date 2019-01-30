
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void insert (int a[]);
void display (int a[]);
void update (int a[]);
void del (int a[]);
void add (int a[]);

int n,i;

int main()
{
	int a[20];
	printf("How many numbers ? \t");
	scanf("%d",&n);
	printf("\nEnter the %d numbers.\n",n);
	for(i=1;i<=n;i++)
	{
		printf("\ta[%d] = ",i);
		scanf("%d",&a[i]);
	}
	do{
	printf("\n\nChoose a option:\n");
	printf("\t1 to insert(by removing the last element).\n\t2 to display/traverse.\n\t3 to update(change).\n\t4 to delete.\n\t5 to add element (without deleting any other elements).\n\t6 to exit.\n");
	int opt;
	printf("\noption : ");
	opt = getche();
	switch (opt){
		case '1':
			insert (a);
			break;
			case '2':
				display (a);
				break;
				case '3':
					update (a);
					break;
					case '4':
						del (a);
						break;
						case '5':
							add (a);
							break;
						case '6':
							exit(0);
							break;
							default:
							printf("\nPlease choose a valid input.\n\n");
					}
}while(1);
		getch();
		return 0;			
}
void insert (int a[])
{
	int l,e;
	printf("\n\nEnter the address to insert the element.\t");
	scanf("%d",&l);
	printf("Enter the element to be inserted.\t");
	scanf("%d",&e);
	for(i=n;i>l;i--)
	{
		a[i] = a[i-1];
	}
	a[i] = e;
}

void display(int a[])
{
	printf("\n\n\n");
	for(i=1;i<=n;i++)
	{
		printf("\t a[%d] = %d.\n",i,a[i]);
	}
}

void update (int a[])
{
	int l,e;
	printf("\n\nEnter a location to update it's element.\t");
	scanf("%d",&l);
	printf("Enter the new element for location %d.\t",l);
	scanf("%d",&e);
	a[l] = e;
}

void del (int a[])
{
	int l;
	printf("\n\nEnter a location to delete.\t");
	scanf("%d",&l);
	for(i=l;i<n;i++)
    a[i] = a[i+1];
    n--;
} 

void add(int a[])
{
	int l,e;
	n++;
	printf("\n\nEnter a location (%d to %d) to add new element.\t",1,n);
	scanf("%d",&l);
	printf("Enter the new element.\t");
	scanf("%d",&e);
	for(i=n;i>l;i--)
	{
   		a[i] = a[i-1]; 
	}
	
	a[l] = e;

}
