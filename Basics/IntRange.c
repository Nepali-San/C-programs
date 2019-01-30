#include<stdio.h>
// illustration of bitwise operator {sizeof()}.
// and consequence range of datatype int (signed int). 
#include<conio.h>
#include<math.h>
int main()
{
	int min,max,i,check;
	i=sizeof(int)*8;         //to convert bytes into bits multiply by 8.
	max=((pow(2,i))/2)-1;
	min=-((pow(2,i))/2);
	printf("\n Range of int in your PC is %d to %d.",min,max);
	
	// range varies according to wordlength of PC.
	
	printf("\n\n\n Enter a number within or not within the range to know");
	printf(" the consequence of range on signed int.\t");
	scanf("%d",&check);
	printf("\n You have entered %d.",check);
	getch();
	return 0;
}
