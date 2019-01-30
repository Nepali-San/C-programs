// program to delete the word "that" from a string.

#include<stdio.h>
#include<conio.h>
#include<string.h>
int main()
{
	char line[80];
	int i,j,l;
	printf("Enter line of text:\t");
	printf("\nPlease hit space before any punction marks and befor hitting enter key.\n");
	gets(line);
	l=strlen(line);
	for(i=0;line[i+4]!='\0';i++)
	{
		if(line[i]=='t' && line[i+1]=='h' && line[i+2]=='a' && line[i+3]=='t' &&line[i+4]==' ')
		{
			for(j=i;line[j+4]!='\0';j++)
			{
			line[j]=line[j+5];
		    }
			i--;
		}
		
	}
	printf("after deleting that:\n%s",line);
	getch();
	return 0;
}
