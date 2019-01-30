// Using double pointer and one malloc for all rows.
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int r=3, c=4;
	int **arr;
	int count = 0,i,j;

	arr = (int **)malloc(sizeof(int *) * r);
	arr[0] = (int *)malloc(sizeof(int) * c * r);

	for(i = 0; i < r; i++)
		arr[i] = (*arr + c * i);

	for (i = 0; i < r; i++)
		for (j = 0; j < c; j++)
			arr[i][j] = ++count; // OR *(*(arr+i)+j) = ++count

	for (i = 0; i < r; i++)
		for (j = 0; j < c; j++)
			printf("%d ", arr[i][j]);
		
	return 0;
}
/*first they are allocating (r*c)12 address to arr[0]
 which pointer to first row( address of first row) and
  in loop a[0]=0th address means first row starts at index
   0th which is base addess and arr[1]=4 which means for second
    row starts at 4th index which is row second base address and
	 arr[2]=8th till 12th as arr[0] has been allocated only 12 unit
	  addresses and i hope you are clear with double point here. Tell
	   me if still doubt thanks.*/
