#include <stdio.h>

void t(int n, char from, char temp, char to);

int main()
{
	int n;
	printf("How many disks?\t");
	scanf("%d",&n);
	printf("\nMoves\a\n");
	t(n, 'L', 'C', 'R');
	return 0;
}

void t(int n, char from, char temp, char to)
{
	if(n == 1)
	{
		printf("%c --> %c\n", from, to);
	}
	else
	{
		t(n-1,  from, to, temp);
		t(1, from, temp, to);
		t(n-1, temp, from, to);
	}
}
