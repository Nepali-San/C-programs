
#include<stdio.h>
#include<conio.h>
#include<string.h>
#define SIZE 50

char stack[SIZE];
int top = -1;
void in_to_post(char infix[]);
void push(char);
char pop();

void main()
{
	char infix[25];
	printf("Enter the infix \n");
	gets(infix);
	in_to_post(infix);
	getch();
}

void push(char symb)
{
	if(top>=SIZE-1)
	{
		printf("stack overflow");
		getch();
		return ;
	}
	else {
		top++;
		stack[top] = symb;
	}
}

char pop()
{
	char item;
	if(top <= -1)
	{
		printf("Stack empty");
		getch();
		return (0);
	}
	else {
		item = stack[top];
		top --;
	}
	return item;
}

int preced(char ch)
{
	
	if (ch==36 || ch == 94) 
	    return 5;
	else if(ch==47  || ch == 42) 
		return 4;
	else if(ch ==43 || ch==45)
	    return 3;
	else                
	    return 2;
}

void in_to_post(char infix[])
{
int length;
static int index = 0,pos = 0;
char symbol,temp;
char postfix[40];
length = strlen(infix);
push('#');              
   while(index < length) //index starts from 0 so it must  be less                    
   {                        // than length  to access all the elements
 symbol = infix[index];
 switch(symbol)
     {
 case '(':
 push(symbol);
 break;
 case ')':
 temp = pop();
 while(temp != '('){
 postfix[pos++] = temp;
 temp = pop();
   }
break;
case '+':
	case '-':
		case '*':
			case '/':
				case '^':
					case '$':   // here '$' means '^'
					while (preced(stack[top])>= preced(symbol)){
						postfix[pos++] = pop(); 
					}
					push(symbol);
					break;
					default: 
					postfix[pos++] = symbol;
					break;
				}
				index++;
			}
			while(top>0){
				postfix[pos++] = pop();
			}
			postfix[pos++] = '\0';
			printf("\nThe postfix for the given infix ( %s )  is  %s\n",infix,postfix);
		}
