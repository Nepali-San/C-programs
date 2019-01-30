// Program that calculates the area of the verticle section of circle.

#include<stdio.h>
#include<conio.h>
#include<math.h>

#define precision 0.01

int main()
{
	float lower,upper,i;
	float height,SemiArea = 0;
	printf("Enter the lower range(-5 to 5)\t");
	scanf("%f",&lower);
	printf("Enter the upper range(%.3f - 5)\t",lower);
	scanf("%f",&upper);
	for(i=lower;i<=upper;i+=precision)
	{
	height = sqrt(25-(i*i));
	SemiArea += height * precision;
	}
    printf("The area of the circle  X^2 + Y^2 = 25 from the section %.3f to %.3f is %.3f\t",lower,upper,2*SemiArea);
//    printf(" area = %f",3.1415*5*5); when lower = upper = 5.
    getch();
    return 0;
}

