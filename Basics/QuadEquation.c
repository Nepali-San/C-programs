#include "myheader.h"  //this header contain stdio.h , conio.h , math.h
void main()
{
	int a,b,c,z,r1,r2;
	printf("\t Enter the values a,b and c of quadratic equation ax^2+bx+c=0.\n");
	scanf("%d%d%d",&a,&b,&c);
	z=(b*b)-(4*a*c);
	system("cls");
	printf("Your equation is %dx^2 + %dx + %d = 0.\n",a,b,c);
	if(a==0)
	{
		printf("Invalid input for coefficient of x^2 (a).\n");
	}
	else if(z<0)
	{
		r1=(-b/(2*a));
		r2=(sqrt(-z)/(2*a));
		printf("Roots are imaginary.\nRoots are %d + %d i and %d - %d i\n",r1,r2,r1,r2);
	}
	else
	{
		r1=(-b/(2*a))+(sqrt(z)/(2*a));
		r2=(-b/(2*a))-(sqrt(z)/(2*a));
		if(z==0)
			printf("Both roots are %d.\n",r1);
			else
		printf("Roots are %d and %d.",r1,r2);
	}
	getch();
}
