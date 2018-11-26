#include<stdio.h>
#include<stdlib.h>
struct node
{
	int val;
	struct node *left,*right;
};
typedef struct node NODE;

NODE *newnode(int item)
{
	NODE *temp=(NODE *)malloc(sizeof(NODE));
	temp->val=item;
	temp->left=temp->right=NULL;
	return temp;
}
void inorder(NODE *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("%d  ",root->val);
		inorder(root->right);
	}
}

NODE *insert(NODE *node,int item)
{
	if(node == NULL) return newnode(item);
	if(item < node->val)
		node->left=insert(node->left,item);
	else
		node->right=insert(node->right,item);
	return node;
}

void search(NODE *root,int key)
{
	if(root == NULL) { printf("Not Found\n"); return; }
	if(root->val == key) { printf("Value Found\n"); return; }
	else if(key < root->val) search(root->left,key);
	else search(root->right,key);
}

void main()
{
int choice,data;
NODE *root;
root=NULL;
printf("\nEnter \n1.Insert value\n2.Search value\n3.Print values\n");
scanf("%d",&choice);
do
{
switch(choice)
{
case 1:printf("Enter the value: ");
	scanf("%d",&data);
	root=insert(root,data);
	break;
case 2:printf("Enter the value: ");
	scanf("%d",&data);
	search(root,data);
	break;
case 3:inorder(root);
	break;
case 4:exit(0);
}
printf("\nEnter \n1.Insert value\n2.Search value\n3.Print values\n");
scanf("%d",&choice);
}while(choice!=4);
}


