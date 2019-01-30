//program to show the usage of whitespace character in scanf().

#include<stdio.h>
#include<conio.h>
int main()
{
	int n1;
	char ch;
	printf("Enter a number: ");
	scanf("%d",&n1);
	printf("Enter a character: ");
	scanf(" %c",&ch);  //remove the space after %c to see the consequence of space.
	printf("\nNumber: %d\t Character: %c",n1,ch);
	getch();
	return 0;
}
