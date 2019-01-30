#include<stdio.h>
#include<conio.h>
int bin_search(int[],int n,int k);
int main()
{
	int a[20],n,item,l,i;
	system("cls");
	printf("Enter how many numbers.\t");
	scanf("%d",&n);
	printf("Enter %d numbers in ascending order.\n",n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("Enter the number to search.\t");
	scanf("%d",&item);
	l=bin_search(a,n,item);
	if(l<0)
	printf("\nItem not in list.");
	else
	printf("%d is found in location %d",item,l);
	getch();
	return 0;
}
int bin_search(int a[],int n,int item)
{
	int low,high,mid;
	low=0;
	high=n-1;
	mid=(low+high)/2;
	while(low<=high && a[mid]!=item)
	{
		if(a[mid]<item)
		low=mid+1;
		if(a[mid]>item)
		high=mid-1;
		mid=(low+high)/2;
	}
	if(a[mid]==item)
	return(mid+1);
	else
	return -1;
}
