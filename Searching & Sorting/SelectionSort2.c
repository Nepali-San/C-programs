
#include<stdio.h>
#include<conio.h>

int main(){
	int n,a[10],i;
	int loc,j,temp,min;
	printf("\nHow many numbers ? \n");
	printf("Answer = \t");
	scanf("%d",&n);
	printf("\nEnter %d number randomly:\n",n);
	i = 0;
	while(i<n){
		scanf("%d",&a[i]);
		i++;
	}
	for(i=0;i<n-1;i++){
		min = a[i];
		loc = i;
		for(j=i+1;j<n;j++){
			if(a[j]<min){
				min = a[j];
				loc = j;
			}
		}
			if(loc != i){
				temp = a[i];
				a[i] = a[loc];
				a[loc] = temp;
			}
	}
	printf("\nSorted order is:\n\n");
	for(i=0;i<n;i++){
		printf("\n%d",a[i]);
	}
	getch();
	return 0;
}
