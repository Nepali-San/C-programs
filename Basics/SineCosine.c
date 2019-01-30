//Program to calculate the sine and cosine of given angle in degress.

#include<stdio.h>
#include<conio.h>
#define PI 3.1415
float sine(float);
float cosine(float);
int main()
{
	float x,xdeg;
	printf("Enter the angle (0 to 360) to find it's sine and cosine values:\t");
	scanf("%f",&x);
	xdeg=x;
	x=x*PI/180;
	printf("\n\t sin(%.2f) = %.3f\n",xdeg,sine(x));
	printf("\t cos(%.2f) = %.3f\n",xdeg,cosine(x));
	getch();
	return 5;
}
float sine(float s)
{
	int i;
	float sum,term;
	sum=s;
	term=s;
	for(i=1;i<30;i++)
	{
		term=-1*term*s*s/(2*i*((2*i)+1));
		sum+=term;
	}
	return sum;
}
float cosine(float c)
{
	int i;
	float term=1,sum=1;
	for(i=1;i<20;i++)
	{
		term=-1*term*c*c/(2*i*((2*i)-1));
		sum+=term;
	}
	return sum;
}
