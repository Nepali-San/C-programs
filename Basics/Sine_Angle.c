     // program to ask an angle in degrees and find it's sine value.

#include<stdio.h>
#include<conio.h>
#define PI 3.1415
int main()
{
	float x,xdeg,sum,term;
	int i;
	printf("\n\tEnter the angle in degrees (0 to 360).\t");
	scanf("%f",&x);
	xdeg=x;
	x=x*PI/180;
	term=x;
	sum=x;
	for(i=1;i<=20;i++)
	{
		term = -1*term*x*x/(2*i*((2*i)+1));
		sum+=term;
	}
	printf("\n sin(%.2f) = %.3f",xdeg,sum);
	getch();
	return 0;
}


