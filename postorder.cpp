/*Binary Tree creation and traversal in post-order fashion*/
#include<iostream>
using namespace std;
#define MAX 50
class Tree;
class node
{
	char data;
	node *left,*right;
	public:
		node(char c)
		{
			data=c;
			left=right=NULL;
		}
		friend class Tree;
};
class Tree
{
	node *root;
	public:
		Tree()
		{
			root=NULL;
		}
		int isempty();
		void create();
		void postorder();
};
class stack
{
	node *item[MAX];
	int top;
	public:
	   stack()
	   {
	   	top=-1;
	   }
	   int empty()
	   {
	   	if(top==-1)
	   	return 1;
	   	return 0;
	   }
	   int full()
	   {
	   	if(top==MAX)
	   	return 1;
	   	return 0;
	   }
	   node *pop()
	   {
	   	return item[top--];
	   }
	   void push(node *temp)
	   {
	   	item[++top]=temp;
	   }
	   node *top_item()
	   {
	   	 return item[top];
	   }
};
int Tree::isempty()
{
	if(root==NULL)
	return 1;
	return 0;
}
void Tree::create()
{
	node *temp;
	char choice,c,ch;
	do
	{
		cout<<"Enter the node to be attached:";
		cin>>c;
		node *newnode=new node(c);
		if(isempty())
		{
			root=newnode;
		}
		else
		{
			temp=root;
			while(1)
			{
				cout<<"Node to be attached is to the [l/r] of the node "<<temp->data<<":";
				cin>>ch;
				if(ch=='l')
				{
					if(temp->left==NULL)
					{
						temp->left=newnode;
						break;
					}
					else
					{
						temp=temp->left;
					}
				}
				else
				{
					if(temp->right==NULL)
					{
						temp->right=newnode;
						break;
					}
					else
					{
						temp=temp->right;
					}
				}
			}
		}
		cout<<"Any more nodes to be attached ? ";
		cin>>choice;
	}while(choice=='y' || choice=='Y');
}
void Tree::postorder()
{ 
   cout<<"\nThe post-order traversal of the tree is as follows:";
   stack s1,s2; //stack s1 is initial(parent) stack and stack s2 is final(child) stack
   node *temp=root;
   s1.push(temp);
   
   while(s1.empty()==0)
   {
   	   if(temp->right != NULL && temp->left != NULL)
   	   {
   	   	  temp=s1.pop();
   	   	  s2.push(temp);
   	   	  s1.push(temp->left); 
		  s1.push(temp->right);
   	   	   
   	   }
   	   if(temp->left != NULL && temp->right == NULL)
   	   {
   	   	  temp=s1.pop();
   	   	  s2.push(temp);
   	   	  s1.push(temp->left);  
	   }
   	   if(temp->right != NULL && temp->left == NULL)
   	   {
   	   	   temp=s1.pop();
   	   	   s2.push(temp);
   	   	   s1.push(temp->right);
   	   }
   	   if(temp->right==NULL && temp->left==NULL)
   	   {
   	   	   temp=s1.pop();
   	   	   s2.push(temp);
   	   }
   	   temp=s1.top_item();
   }
   while(s2.empty()==0)
   {
   	  temp=s2.pop();
   	  cout<<temp->data;
   }
}
main()
{
	Tree t;
	t.create();
	t.postorder();
}
