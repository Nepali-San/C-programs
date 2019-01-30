#include<stdio.h>
#include<stdlib.h>

struct btree{
	struct btree *left;
	int data;
	struct btree *right;
};

typedef struct btree bt;

void insert(bt **sr, int data);
void inorder(bt *ir);
void preorder(bt *ir);
void postorder(bt *ir);

int main(){
	int data,i;
	bt *root;
	int n;
	root = NULL;
	printf("Specify the number of data items to be inserted in binary tree :\n");
	scanf("%d",&n);
	for(i = 0; i < n; i++){
		printf("Enter the data :   ");
		scanf("%d",&data);
		insert(&root,data);
	}
	printf("\n\nThe inorder traversal of tree is :\n\n");
	inorder(root);
	printf("\n\nThe preorder traversal of tree is :\n\n");
	preorder(root);
	printf("\n\nThe postorder traversal of tree is :\n\n");
	postorder(root);
	return 0;
}

void insert(bt **sr, int data){
	if(*sr == NULL){
		*sr = malloc(sizeof(bt));
		(*sr)->left = NULL;
		(*sr)->right = NULL;
		(*sr)->data = data;
	}
	else if (data < (*sr)->data){
		insert(&((*sr)->left),data);
	}
	else{
		insert(&((*sr)->right),data);
	}
	return;
}

void inorder(bt *ir){
	if(ir != NULL){
		inorder(ir->left);
		printf("%d ",ir->data);
		inorder(ir->right);
	}
	else{
		return;
	}
}

void preorder(bt *ir){
	if(ir != NULL){
		printf("%d ",ir->data);
		preorder(ir->left);
		preorder(ir->right);
	}
	else{
		return;
	}
}

void postorder(bt *ir){
	if(ir != NULL){
		postorder(ir->left);
		postorder(ir->right);
		printf("%d ",ir->data);
	}
	else{
		return;
	}
}
