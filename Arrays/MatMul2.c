#include<stdio.h>
//#include<conio.h>
int main()
{
	int a[10][10],b[10][10],c[10][10];
	int i,j,k,m1,m2,n1,n2,q,Q;
	printf("\n\t1:1*1\t2:1*2\t3:1*3\t4:1*4\n\t5:2*1\t6:2*2\t7:2*3\t8:2*4\n\t9:3*1\t10:3*2\t11:3*3\t12:3*4\n\t13:4*1\t14:4*2\t15:4*3\t16:4*4\n\n\t\tPress any other number for custom dimension.\n");
	printf("\n\tChoose the dimension for first matrix.\n");
	scanf("%d",&q);
    switch (q)
	{
		case 1:
			m1=1;
			n1=1;
			break;
		case 2:
			m1=1;
			n1=2;
			break;
		case 3:
			m1=1;
			n1=3;
			break;
		case 4:
		    m1=1;
		    n1=4;
		    break;
		case 5:
			m1=2;
			n1=1;
			break;
		case 6:
			m1=2;
			n1=2;
			break;
		case 7:
			m1=2;
			n1=3;
			break;
		case 8:
		    m1=2;
		    n1=4;
		    break;
		    case 9:
			m1=3;
			n1=1;
			break;
		case 10:
			m1=3;
			n1=2;
			break;
		case 11:
			m1=3;
			n1=3;
			break;
		case 12:
		    m1=3;
		    n1=4;
		    break;
		case 13:
		    m1=4;
		    n1=1;
		    break;
		    case 14:
			m1=4;
			n1=2;
			break;
		case 15:
			m1=4;
			n1=3;
			break;
		case 16:
			m1=4;
			n1=4;
			break;
		default:
			printf("\nEnter the number of rows and columns for first matrix.\n");
			scanf("%d%d",&m1,&n1);
			break;
}
printf("\nChoose the dimension for second matrix.\n");
scanf("%d",&Q);
	    switch (Q)
	{
		case 1:
			m2=1;
			n2=1;
			break;
		case 2:
			m2=1;
			n2=2;
			break;
		case 3:
			m2=1;
			n2=3;
			break;
		case 4:
		    m2=1;
		    n2=4;
		    break;
		case 5:
			m2=2;
			n2=1;
			break;
		case 6:
			m2=2;
			n2=2;
			break;
		case 7:
			m2=2;
			n2=3;
			break;
		case 8:
		    m2=2;
		    n2=4;
		    break;
		    case 9:
			m2=3;
			n2=1;
			break;
		case 10:
			m2=3;
			n2=2;
			break;
		case 11:
			m2=3;
			n2=3;
			break;
		case 12:
		    m2=3;
		    n2=4;
		    break;
		case 13:
		    m2=4;
		    n2=1;
		    break;
		    case 14:
			m2=4;
			n2=2;
			break;
		case 15:
			m2=4;
			n2=3;
			break;
		case 16:
			m2=4;
			n2=4;
			break;
		default:
			printf("\nEnter the number of rows and colums for first matrix.\n");
			scanf("%d%d",&m2,&n2);
			break;
	}
//	system("cls");
	printf("\n Dimension for first matrix is %dx%d and dimension for second matrix is %dx%d.\n",m1,n1,m2,n2);
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
	//system("cls");
	printf("\nFirst matix is:\n");
	for (i=0;i<m1;i++)
	{
		for (j=0;j<n1;j++)
		{
			printf("\t%d",a[i][j]);
		}
		printf("\n");
	}
	printf("\nSecond matrix is:\n");
	for (i=0;i<m2;i++)
	{
		for (j=0;j<n2;j++)
		{
			printf("\t%d",b[i][j]);
		}
		printf("\n");
	}
	printf("\nResult of matrix multiplication is:\n");
	for(i=0;i<m1;i++)
	{
		for(j=0;j<n2;j++)
		{
			printf("\t%d",c[i][j]);
		}
		printf("\n");
	}
}
//getch();
return 0;
}

