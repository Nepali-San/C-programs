
// Multiplies the two matrices with DMA process.

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>   // to include system("cls"); and exit(0); we use stdlib.h  instead of malloc.h

int main()
{
	int i,j,k;
	int r1,c1,r2,c2;
	int opt;           // to store the option exit or continue if dimension is error.
      cont:          // if you choose continue the program stops and begins from here.
      	system("cls");
	printf("Enter the dimension of matrix A.\n");
	scanf("%d%d",&r1,&c1);
	
	printf("Enter the dimension of matrix B.\n");
	scanf("%d%d",&r2,&c2);
	
	if ( c1 != r2)
	{
	printf("\n Dimension is not valid for matrix multiplication.\n");
	printf("\n Enter 'E' to exit.\t");
	printf("\n Enter 'C' to autocorrect the dimension of matrix B.\t");
	printf("\n Enter anyother keys to restart the program.\t");
	opt = getche();
	if(opt=='e' || opt == 'E')
	exit(0);
	else if (opt == 'C' || opt == 'c')
	r2 = c1;
	else 
	goto cont;      // can use do while loop instead of goto.
   }
	int **a = (int **) malloc (r1*sizeof(int *)); //Allocates the space for r1 single pointers i.e. a[0] to a[r1-1]
	 
	for(i=0;i<r1;i++)
	*(a+i) = (int *) malloc (c1*sizeof(int)); //Each single pointer allocates c1 memory space
	
    printf("\n\nEnter the %d * %d matrix A.\n",r1,c1);
	for(i=0;i<r1;i++)
	{
		printf("\nEnter the %d row of matrix A.\n",i+1);
	  for(j=0;j<c1;j++)
	  {
	  	printf("\tA[%d][%d] = ",i+1,j+1);
		scanf("%d",&a[i][j]);
	  }
    }
    
    int **b = (int **) malloc (r2*sizeof(int *));
	 
	for(i=0;i<r2;i++)
	b[i] = (int *) malloc (c2*sizeof(int));
	
    printf("\nEnter the %d * %d matrix B.\n",r2,c2);
	for(i=0;i<r2;i++)
	{
		printf("\nEnter the %d row of matrix B.\n",i+1);
	  for(j=0;j<c2;j++)
	  {
	  	printf("\tB[%d][%d] = ",i+1,j+1);
		scanf("%d",&b[i][j]);
	  }
    }
    
    system("cls"); //To clear the input screen and display only output screen.
    
	printf("\nThe elements of matrix A are:\n");
	for(i=0;i<r1;i++)
	{
		for(j=0;j<c1;j++)
		{
			printf("\t%d",a[i][j]);  /* to display the elements of matrix A ,
			                             you can skip this part.*/
		}
		printf("\n");
	}
	
	printf("\nThe elements of matrix B are:\n");
	for(i=0;i<r2;i++)
	{
		for(j=0;j<c2;j++)
		{
			printf("\t%d",b[i][j]); // to display the elements of matrix B ,
			                        // you can skip this part.
		}
		printf("\n");
	}
	
	int **c= (int **) malloc (r1*sizeof(int *));
	for(i=0;i<r1;i++)
	c[i] = (int *) malloc (c2* sizeof(int));
	
	printf("\n");
	printf("After the multiplication of both matrix. The resultant matrix is:\n");
	for(i=0;i<r1;i++)
	{
		for(j=0;j<c2;j++)
		{
			c[i][j]=0;
			for(k=0;k<c1;k++)
			{
				c[i][j] += a[i][k] * b[k][j];  // multiplication processing...
            }
		}
    }

	
	for(i=0;i<r1;i++)
	{
		for(j=0;j<c2;j++)
		{
			printf("\t%d",c[i][j]);   //output of multiplied result.
		}
		printf("\n");
	}
	
	printf("\n\n\nDo want to continue , if yes enter Y or y else anyother key to exit.\t");
	opt = getche();
	if(opt == 'Y' || opt == 'y')
	goto cont;
	

         // Let's free the memory...
         
for(i=0;i<r1;i++)
{
free(a[i]);    //freeing the inner allocation i.e. the single pointers
free(c[i]); 
}

free(a);    //freeing the allocated dual pointers.
free(c);

for(i=0;i<r2;i++)
free(b[i]);

free(b);

	return 0;
}

//coder : San
