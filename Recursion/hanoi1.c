#include<stdio.h>
#include<conio.h>
void tran(int n,char from,char to , char temp)
{
	if(n>0)
	{
		tran(n-1,from ,temp,to);
		printf("%d from %c to %c\n\n",n,from,to);
		tran(n-1,temp,to,from);
	}
}
int main()
{
	
	int n;
	printf("\nHow many disks ? \t");
	scanf("%d",&n);
	tran(n,'l','r','c');
	return 0;
}
