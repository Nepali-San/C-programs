/* Define a structure of employee having data members name,address,age,salary.
Take data for n employees dynamically and find the average salary.*/
 
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int main()
{
	struct employee
	{
	char name[20];
	char add[20];
	int age;
	int salary;
	}*emp;
	int i,n,sum=0,avg;
	printf("Enter the total no. of employees.\t");
	scanf("%d",&n);
	emp = (struct employee*) calloc (n,sizeof(struct employee));
	for(i=0;i<n;i++)
	{
		fflush(stdin);
		printf("\nName of employee %d\t",i+1);
		gets((emp+i)->name);
		printf("Address of employee %d\t",i+1);
		gets((emp+i)->add);
		printf("Age of employee %d\t",i+1);
		scanf("%d",&(emp+i)->age);
		printf("Salary of employee %d\t",i+1);
		scanf("%d",&(emp+i)->salary);
	}
	for(i=0;i<n;i++)
	{
		sum= sum + (emp+i)->salary;
	}
	avg = sum/n;
	printf("\nThe average salary is %d.",avg);
	getch();
	return 0;
}
