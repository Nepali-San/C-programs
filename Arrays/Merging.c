// program merges the sorted array.
#include<stdio.h>
#include<conio.h>

int main()
{
	int a[50],b[50],c[100];
	int a1,b1,m,n,c1;
	printf("  How many elements for first array.\t");
	scanf("%d",&a1);
	
	printf("\n  Enter the %d sorted elements for first array.\n",a1);
	for(m=0;m<a1;m++){
		printf("\t");
	scanf("%d",&a[m]);}
	
	printf("\n\n  How many elements for second array.\t");
	scanf("%d",&b1);
	
	printf("\n  Enter the %d sorted elements of second array.\n",b1);
	
	for(n=0;n<b1;n++){
		printf("\t");
	scanf("%d",&b[n]);}
	
	c1=0;
	m=0;
	n=0;
	
	while((m<a1) && (n<b1))
	{
		if(a[m] <= b[n])
		{
		c[c1] = a[m++];
	}
		else{
		c[c1] = b[n++];
		}
		c1++;
	}
	
	while(m<a1)
	{
		c[c1] = a[m];
		c1++;
		m++;
	}
	
	while(n<b1)
	{
		c[c1] = b[n];
		c1++;
		n++;
	}
	
	printf("\n  The merged array is \n");
	for(m=0;m<c1;m++)
	{
		printf("\t%d\n",c[m]);
	}
	
	getch();
	return 0;
}
