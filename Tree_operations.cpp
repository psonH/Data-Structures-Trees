/*Inserting an element in the binary tree and traversing in inorder fashion */
#include<iostream>
#define MAX 20
using namespace std;
class Tree;
class node
{
	char data;
	node *left;
	node *right;
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
	    void inorder();
	    void insert(char);
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
		void push(node *p)
		{
			item[++top]=p;
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
	char choice,ch,c;
	do
	{
		cout<<"Enter the node to be attached:";
		cin>>c;
		node *newnode=new node(c);
		if(isempty())
		root=newnode;
		else
		{
			temp=root;
			while(1)
			{
				cout<<"Node is to be attached to the [l/r] of the node "<<temp->data<<":";
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
					else{
						temp=temp->right;
					}
				}
			}
		}
		cout<<"Any more nodes are to be attached ? ";
		cin>>choice;
	}while(choice=='y' || choice=='Y');
}
void Tree::inorder()
{
	node *temp=root;
	stack s;
	cout<<"The inorder traversal is as follows:";
	while(1)
	{
		while(temp != NULL)
		{
			s.push(temp);
			temp=temp->left;
		}
		if(s.empty())
		break;
		else
		{
			temp=s.pop();
			cout<<temp->data;
			temp=temp->right;
		}
	}
}
void Tree::insert(char c)
{
	node *temp;
	char ch;
	node *newnode=new node(c);
	if(isempty())
	root=newnode;
	else
	{
		temp=root;
		while(1)
		{
			cout<<"Node is to be attached to the [l/r] of the node "<<temp->data<<":";
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
				else{
					temp=temp->right;
				}
			}
		}
	}
}
main ()
{
	Tree t;
	t.create();
	t.inorder();
	char c;
	cout<<"\nWhat data do you wish to insert:";
	cin>>c;
	
	t.insert(c);
	t.inorder();
}


/*Enter the node to be attached:A
Any more nodes are to be attached ? y
Enter the node to be attached:B
Node is to be attached to the [l/r] of the node A:l
Any more nodes are to be attached ? y
Enter the node to be attached:C
Node is to be attached to the [l/r] of the node A:r
Any more nodes are to be attached ? y
Enter the node to be attached:D
Node is to be attached to the [l/r] of the node A:l
Node is to be attached to the [l/r] of the node B:l
Any more nodes are to be attached ? n
The inorder traversal is as follows:DBAC
What data do you wish to insert:X
Node is to be attached to the [l/r] of the node A:r
Node is to be attached to the [l/r] of the node C:l
The inorder traversal is as follows:DBAXC
--------------------------------
Process exited with return value 0
Press any key to continue . . .
*/
