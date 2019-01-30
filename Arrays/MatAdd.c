#include<stdio.h>
#include<conio.h>
void main()
{
int i,j,m,n;
int a[10][10],b[10][10];
printf("\t\t\t\t This is a program for matrix addition upto 10x10 dimension.\n\n\n\n");
printf("\t Enter the dimension(no. of rows and columns) of matrix.\n");
scanf("%d%d",&m,&n);
if(m!=0||n!=0)
{
for(i=0;i<m;i++)
{
printf("\t\t Enter the  %d values for %dth row of first matrix.\n",n,i+1);
for (j=0;j<n;j++)
{
scanf("%d",&a[i][j]);
}
}
for (i=0;i<m;i++)
{
printf("\t\t Enter the %d values for %dth row of second matrix.\n",n,i+1);
for (j=0;j<n;j++)
{
scanf("%d",&b[i][j]);
}
}
system("cls");
printf("Your first input matrix is:\n\n");
for (i=0;i<m;i++)
{
for (j=0;j<n;j++)
{
printf("   %d",a[i][j]);
}
printf("\n");
}
printf("\n\nYour second input matrix is:\n");
for (i=0;i<m;i++)
{
for (j=0;j<n;j++)
{
printf("   %d",b[i][j]);
}
printf("\n");
}
printf("\n\nYour result of matrix addition is:\n");
for (i=0;i<m;i++)
{
for(j=0;j<n;j++)
{
 printf("   %d",a[i][j]+b[i][j]);
}
printf("\n");
}
}
else
{
	printf("Dimension is not valid.");
}
getch();
}
