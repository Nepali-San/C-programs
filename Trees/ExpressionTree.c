/*
 * C-Program to create Expression Tree from postfix and prefix  notation
 * and display all three notaion from Expression Tree. Also evaluate the
 * result of Tree.
 */

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>   
#include<string.h>  //To reverse the string in CreateExpTreePrefix();
#include<math.h>    //To use pow() in evaluate(); 

#define MAX 50

struct node{
	struct node * left_child;
	struct node * right_child;
	char x;
}*stack[50];

int top = -1;

//Prototypes of utility functions
struct node * CreateExpTreePostfix(char *); 
struct node * CreateExpTreePrefix(char *); 
void preorder(struct node *sr);
void inorder(struct node *sr);
void postorder(struct node *sr);
void push(struct node **,struct node *);
struct node *pop(struct node**);
void DeleteTree(struct node*);

main(){
	struct node *root;
	char str[50];
	int z;
	char ch;
	printf("Input Expression is:\n1)Prefix\n2)Postfix\n\nOption = ");
	ch = getche();
	if(ch == '1'){
		printf("\n\nEnter the prefix expression\n");
		gets(str);
		root = CreateExpTreePrefix(str);
	}
	else{
		printf("\n\nEnter the postfix expression\n");
		gets(str);
		root = CreateExpTreePostfix(str);
	}
	printf("\n Prefix Expression is:\n");
	preorder(root);
	printf("\n Postfix Expression is:\n");
	postorder(root);
	printf("\n Infix Expression is:\n");
	inorder(root);
	z = evaluate(root);
	printf("\n\n Expression evaluate to : %d",z);
	DeleteTree(root);
	getch();
	return 1;
}

struct node * CreateExpTreePostfix(char *str){
	struct node *nleft,*nright,*nodeptr;
	while(*str){
		nodeptr = (struct node *) malloc (sizeof(struct node));
		nodeptr->x = *str;
		if(*str == '+' || *str == '-'  || *str == '*' || *str == '/' || *str == '^' ){
			nright = pop(stack);
			nleft = pop(stack);
			nodeptr->left_child = nleft;
			nodeptr->right_child = nright;
		}
		else{
			nodeptr->left_child = NULL;
			nodeptr->right_child = NULL;
		}
		push(stack,nodeptr);
		str++;
	}
	return pop(stack);
}

struct node * CreateExpTreePrefix(char *str){
	struct node *nleft,*nright,*nodeptr;
	strrev(str);
	while(*str){
		nodeptr = (struct node *) malloc (sizeof(struct node));
		nodeptr->x = *str;
		if(*str == '+' || *str == '-'  || *str == '*' || *str == '/' || *str == '^' ){
			nleft = pop(stack);
			nright = pop(stack);
			nodeptr->left_child = nleft;
			nodeptr->right_child = nright;
		}
		else{
			nodeptr->left_child = NULL;
			nodeptr->right_child = NULL;
		}
		push(stack,nodeptr);
		str++;
	}
	return pop(stack);
}

void preorder(struct node *sr){
	if(sr != NULL){
		printf("%c",sr->x);
		preorder(sr->left_child);
		preorder(sr->right_child);
	}
}

void inorder(struct node *sr){
	if(sr != NULL){
		inorder(sr->left_child);
		printf("%c",sr->x);
		inorder(sr->right_child);
	}
}


void postorder(struct node *sr){
	if(sr != NULL){
		postorder(sr->left_child);
		postorder(sr->right_child);
		printf("%c",sr->x);
	}
}

void push(struct node **stack,struct node *ptr){
	if(top == MAX-1){
		printf("\nStack Overflow");
	}
	else{
		top++;
		stack[top] = ptr;
		
	}
}

struct node *pop(struct node**stack){
	if(top == -1){
		printf("\nStack is empty");
	}
	else{
		struct node *ptr = stack[top];
		top--;
		return ptr;
	}
}

int evaluate(struct node *sr){
	int x,y,z;
	if(sr != NULL){
		if(sr->x == '+' || sr->x == '-' || sr->x == '*' || sr->x == '/' || sr->x == '^' ){
			x = evaluate(sr->left_child);
			y = evaluate(sr->right_child);
			switch(sr->x){
				case '+': z = x+y; break;
				case '-': z = x-y; break;
				case '*': z = x*y; break;
				case '/': z = x/y; break;
				case '^': z = pow(x,y); break;
			}
			return z;
		}
		return (sr->x - 48);
	}
}

void DeleteTree(struct node * root){
	if(root  != NULL){
		DeleteTree(root->left_child);
		DeleteTree(root->right_child );
		free(root);
	}
}
