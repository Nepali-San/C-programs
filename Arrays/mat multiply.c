#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int main()
{
	int a[10][10],b[10][10],i,j,k,c[10][10];
	int m,n,o,p;
	printf("Enter the dimension for first matrix:\n");
	scanf("%d%d",&m,&n);
	printf("\nEnter the dimension for second  matrix:\n");
	scanf("%d%d",&o,&p);
	if(n!=o)
	{
	printf("\nDimension is not valid for multiplication.\n");
	exit(0);
    }
    printf("\n Enter the first matrix:\n");
    for(i=0;i<m;i++)
    {
    	for(j=0;j<n;j++)
    	{
    		printf("a[%d][%d]=\t",i+1,j+1);
    		scanf("%d",&a[i][j]);
		}
	}
	printf("\n Enter the second matrix:\n");
	 for(i=0;i<o;i++)
    {
    	for(j=0;j<p;j++)
    	{
    		printf("b[%d][%d]=\t",i+1,j+1);
    		scanf("%d",&b[i][j]);
		}
	}
	for(i=0;i<m;i++)
	{
		for(j=0;j<p;j++)
		{
			c[i][j]=0;
			for(k=0;k<n;k++)
			{
				c[i][j]+=a[i][k]*b[k][j];
			}
		}
	}
	printf("\nThe result is:\n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<p;j++)
		{
			printf("%d\t",c[i][j]);
		}
		printf("\n");
	}
	getch();
	return 0;
}
