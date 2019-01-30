//Arranging the names in alphabetical order

#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<malloc.h>
void main()
{
    char x[50][20];  
    int i,n=0;
    void reorder(int n,char x[50][20]);       //prototype to arrange the strings in ascending order.
    printf("\nHow many names:\t");
    scanf("%d",&n);
    printf("\n");
    for(i=0;i<n;i++)
     {
      printf("   Enter the Strings %d :",i+1); 
   	  scanf(" %[^\n]s",x[i]);                //note the space used before %[^\n]s if space is not used then the enter key u pressed before execution of this statemente in run time is read as string 1.
     }                                       //%[^\n]s helps to enter the string until we press the enter key so you can enter full name with space. (eg; San Neupane) as a single string.
    reorder(n,x);
    printf("\nIn alphabetical order :  \n\n");
    for(i=0;i<n;i++)
    {
    printf("\t%d. %s\n",i+1,x[i]); 
    // printf("\t%d. %c\n",i+1,x[i][3]);   <= will give you the 4th character of the sorted string.
    }
    getch();
}
    void reorder(int n,char x[50][20])
    {
    int i,j;
    char t[20];   

    for(i=0;i<n-1;i++)
    for(j=i+1;j<n;j++)
    if(strcmp(x[i],x[j])>0)
    {
    strcpy(t,x[j]);
    strcpy(x[j],x[i]);
    strcpy(x[i],t);
    }
    }
    
