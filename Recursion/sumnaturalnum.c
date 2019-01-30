#include<stdio.h>
#include<conio.h>
int sumnatural(int);
int main()
{
	int n,sum;
	printf("Enter the natural number to find sum of natural number upto that number.\t");
	scanf("%d",&n);
	if(n<=0)
	printf("\n Invalid natural number.\n");
	else
	{
	sum=sumnatural(n);
	printf("\n The sum is %d",sum);
	getch();
	return 0;
    }
}
int sumnatural(int num)
{
	if(num<=1)
	{
		return 1;
	}
	return num+sumnatural(num-1);
}
