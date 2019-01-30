#include<stdio.h>
#include<conio.h>

void quick_sort(int[] ,int ,int );
void swap(int[],int,int);

int main(){
	int i,size;
	int a[10];
	printf("\nEnter the size of array to be sorted:\t");
	scanf("%d",&size);
	printf("\nEnter the array :\n");
	
	for(i=0;i<size;i++)
	scanf("%d",&a[i]);
	
	quick_sort(a,0,size-1);
	
	printf("\nThe sorted array is:\n");
	for(i=0;i<size;i++)
	printf("%d\n",a[i]);
	getch();
	return 0;
}

void quick_sort(int a[],int low,int high){
	int l = low;
	int h = high;
	int pivot = a[(low+high)/2];
	do{
		while(a[l] < pivot)
		l++;
		while(a[h] > pivot)
		h--;
		if(l <= h){
			swap(a,l,h);
			l++;
			h--;
		}
	}while(l<h);
	
	if(low<h)
	quick_sort(a,low,h);
	
	if(l<high)
	quick_sort(a,l,high);
}

void swap(int a[],int l,int h){
	int temp;
	temp = a[l];
	a[l] = a[h];
	a[h] = temp;
}
