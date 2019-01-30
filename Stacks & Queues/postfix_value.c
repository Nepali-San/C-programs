
#include<stdio.h>
#include<conio.h>
#include<math.h>

int eval(char postfix[],int value[]);
int stack[30];
void push(int num);
int top = -1;

int main()
{
	int i=0;
  char postfix[30];
  int value[30];
  printf("Enter the postfix expression\n");
  gets(postfix);
  while(postfix[i] != '\0')
  {
  if(isalpha(postfix[i]))
  {
  	fflush(stdin);
  	printf("Enter the value of %c \t ",postfix[i]);
  	scanf("%d",&value[i]);
  }
  	i++;
  }
  int result = eval(postfix,value);
  printf("The result of %s is %d",postfix,result);
  getch();
  return 0;
}

int eval (char postfix[],int data[])
{
	int op1,op2;
	int i = 0;
	char ch;
	while(postfix[i] != '\0')
	{
		ch = postfix[i];
		if(isalpha(postfix[i]))
		{
		push(data[i]);
        }
    else{
    	op2 = pop();
    	op1 = pop();
    switch(ch){
    	case '+':
    		push(op1+op2);
    		break;
    		case '-':
    			push(op1-op2);
    			break;
    			case '*':
    				push(op1*op2);
    				break;
    				case '/':
    					push(op1/op2);
    					break;
    					case '^':
    					case '$':
    						push(pow(op1,op2));
    						break;
    					}
    				}
    				i++;
    			}
    			int res = pop();
    			return res;
    		}
    		
    			 void push(int num)
					{
						top=top+1;
						stack[top]=num;
					}
					
					int pop()
					{
						float num;
						num=stack[top];
						top=top-1;
						return(num);
					}	
