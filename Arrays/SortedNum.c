#include<stdio.h>
#include<conio.h>
void main()
{
	int a[10],i,j,temp;
	printf("\nEnter any ten numbers.\n");
	for (i=0;i<10;i++)
	{
	scanf("%d",&a[i]);
    }
    printf("\n In ascending order.\n");
    for (i=0;i<9;i++)
    {
    	for(j=i+1;j<10;j++)
    	{
    		if(a[i]>a[j])
    		{
    			temp=a[i];
    			a[i]=a[j];
    			a[j]=temp;
			}
		}
	}
	for(i=0;i<10;i++)
	{
	printf("\t%d",a[i]);
    }
}
