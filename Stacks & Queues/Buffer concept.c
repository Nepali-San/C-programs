// to understand something about buffered data....

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void update (int a[]);
void display (int a[]);

int n,i;     // global decalaration. can pass n in funcions instead making it global.

int main()
{
	printf("info: Maximize the screen if you want.\n\n\n\n\n");
	int a[20];
	char op;
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
	printf("\t1 to update.\n\t2 to display/traverse.\n\t3 to exit.\n");
	char opt;
	printf("\noption : ");
	opt = getche();            // getche doesn't store data in buffer.
	//scanf(" %c",&opt);       // instead of getche we may use scanf but with a space before %c to avoid storing \n from buffer above it while asking a[i];
	switch (opt){
		case '1':           // here 1 2 .. are characters not integers.
			update (a);
			break;
			case '2':
				display (a);
				break;
						case '3':
							exit(0);
							break;
							default:
							printf("\nPlease choose a valid input.\n\n");
					}
				/*A*/	printf("Do u want to continue?( Rem.this statement isn't using input from user in first time(uses buffered 'enter')and for second time it asks (enter 'y' or 'enter'to continue). ");
				/*A*/	scanf("%c",&op);    //use <space>%c otherwise it will store buffer in op ..the buffer here is obtained while entering \n on asking the last element of array above it for first time(i.e. runs forward automatically without asking)  ,but for second time it will ecounter getche so wont store \n in buffer(runs by asking \n) .
				/*A*/	}while (op == 'y' || op == '\n'); // use op == \n for first time (you don't have to enter anythhing) but for second time u may enter 'y' or '\n'( i.e. program will ask).
					
//}while(1);    //may use it instead of A's above. Remove A's if using it. here u only have one way to exit (on pressing 6 on option) while on A's you have two ways ( on entering anything except y or enter key(\n) when program asks and by entering 6.) 
		return 0;			
}
void update (int a[])
{
	int l,e;
	printf("\n\nEnter the address to insert the element.\t");
	scanf("%d",&l);
	printf("Enter the element to be inserted.\t");
	scanf("%d",&e);
	a[l] = e;
}

void display(int a[])
{
	printf("\n\n\n");
	for(i=1;i<=n;i++)
	{
		printf("\t a[%d] = %d.\n",i,a[i]);
	}
}

 


/* the do u want to continue may run automatically at sometime (if u entered y before that time) using the buffered 
 data. may use getch(),getche(),getchar() or <space> %c in scanf  that don't store data in buffer. Also buffer data is gone
 after using it.*/

