#include<stdio.h>
#include<conio.h>

void quick_sort(int[] ,int ,int );
void swap(int[],int,int);

int main(){
	int i,n;
	int a[] = {61,26,77,14,68,45,97,39,99,90};
	
	n = sizeof(a)/sizeof(a[0]);
	printf("Tracing of Quick Sort Algorithm\n\n");
	printf("Original Array:\n\n");
	
	for(i=0;i<n;i++)
	printf("%d\t",a[i]);

	quick_sort(a,0,n-1);
	
	printf("\n\nThe sorted array is:\n");
	for(i=0;i<n;i++)
	printf("%d\t",a[i]);
	getch();
	return 0;
}

void quick_sort(int a[],int low,int high){
	int l = low;
	int h = high;
	int key = a[(low+high)/2];
	do{
		while(a[l]<key)
		l++;
		while(a[h]>key)
		h--;
		if(l <= h){
			swap(a,l,h);
			l++;
			h--;
		}
	}while(l<h);
	
	int i;
	
	printf("\n\nlow = %d(%d) , high = %d(%d) ,key = %d :\n",low,a[low],high,a[high],key);
	for(i=low;i<=high;i++){
		printf("\t%d",a[i]);
	}
//	printf("\n\nOur original array is :\n");
//	for(i=0;i<=9;i++){
//		printf("\t%d",a[i]);
//	}
	printf("\n");
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
