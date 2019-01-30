#include<stdio.h>
#include<conio.h>
void main()
{
	int a[10][10],b[10][10],c[10][10];
	int i,j,k,m1,m2,n1,n2;
	printf("\nEnter the dimension for first matrix.\n");
	scanf("%d%d",&m1,&n1);
	printf("\nEnter the dimension for second matrix.\n");
	scanf("%d%d",&m2,&n2);
	if (n1 != m2)
	{
		printf("\nDimension is not valid for matrix multiplication.\n");
	}
	else
	{
	for (i=0;i<m1;i++)
	{
		printf("\nEnter the %d values for %dth row of first matrix.\n",n1,i+1);
		for (j=0;j<n1;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	for (i=0;i<m2;i++)
	{
		printf("\nEnter %d values for %dth row of second matrix.\n",n2,i+1);
		for (j=0;j<n2;j++)
		{
		scanf("%d",&b[i][j]);
	    }
	}
	for(i=0;i<m1;i++)
	{
		for (j=0;j<n2;j++)
		{
			c[i][j]=0;
			for (k=0;k<n1;k++)
			{
				c[i][j]+=a[i][k]*b[k][j];
			}
		}
	}
	printf("\nResult is\n");
	for(i=0;i<m1;i++)
	{
		for(j=0;j<n2;j++)
		{
			printf("\t%d",c[i][j]);
		}
		printf("\n");
	}
}
getch();
}

