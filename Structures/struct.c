
#include<stdio.h>
#include<conio.h>

int main()
{
	struct structjob {
		char name[32];
		float salary;
		int age;
	}sj;
	union unionjob {
		char name[32];
		float salary ;
		int age;
	}uj;
	printf("size of structure is %d\n",sizeof(sj));
	printf("size of union is %d\n ",sizeof(uj));
	printf("Enter name,salary and age to store in structure.\n");
	scanf("%s%f%d",sj.name,&sj.salary,&sj.age);
     printf("Enter name,salary and age to store in union\n");
	scanf("%s%f%d",uj.name,&uj.salary,&uj.age);
	printf("\n In structure:\n");
	printf("\n name : %s \n salary : %f \n age : %d\n",sj.name,sj.salary,sj.age);
	printf("\n In union :\n");
    printf("\n name : %s \n salary : %f \n age : %d\n",uj.name,uj.salary,uj.age);
	getch();
	return 0;
}
