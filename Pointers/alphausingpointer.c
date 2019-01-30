//Arranging the names in alphabetical order using pointer.

#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<malloc.h>
void main()
{
    char *x[50];   //it is a double pointer.
    int i,n=0;
    void reorder(int n,char *x[]);       //prototype to arrange the strings in ascending order.
    printf("\nHow many names:\t");
    scanf("%d",&n);
    printf("\n");
     
    for(i=0;i<n;i++)
     {
      printf("   Enter the Strings %d :",i+1); 
      x[i]=(char *)malloc(sizeof(char));
	  scanf(" %[^\n]s",x[i]);                //note the space used before %[^\n]s if space is not used then the enter key u pressed before execution of this statemente in run time is read as string 1.
     }                                       //%[^\n]s helps to enter the string until we press the enter key so you can enter full name with space. (eg; San Neupane) as a single string.
    reorder(n,x);
    printf("\nIn alphabetical order :  \n\n");
    for(i=0;i<n;i++)
    {
    printf("\t%d. %s\n",i+1,x[i]); // value from first addr. and goes on till the end of the string.
    // printf("\t%d. %c\n",i+1,x[i][3]);   <= will give you the 4th character of the sorted string.
    }
    getch();
}
    void reorder(int n,char *x[])
    {
    int i,j;
    char *t;   
// or use -> char t[20]. We don't use malloc to allocate various location because we only need single pointer address to store a string. 
    for(i=0;i<n-1;i++)
    for(j=i+1;j<n;j++)
    if(strcmp(x[i],x[j])>0)
    {
    strcpy(t,x[j]);
    strcpy(x[j],x[i]);
    strcpy(x[i],t);
    }
    }
    
