#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int main()
{
	float *marks,sum=0;
	int n,i;
	printf("Enter the marks of n students:\n\a\a n=?");
	scanf("%d",&n);
	marks=(float *)malloc(n*sizeof(float));
	for(i=0;i<n;i++)
	{
		printf("\nEnter the marks of student %d:\t",i+1);
		scanf("%f",marks+i);
		sum+=*(marks+i);
	}
	printf("\nThe average marks is %.2f.",sum/n);
	getch();
	return 0;
}
