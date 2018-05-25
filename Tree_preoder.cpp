/*Binary Tree creation and traversal in pre-order fashion*/
/*Counting Leaf Nodes and Counting total nodes*/
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
		void preorder();
		int count_nodes();
		int count_nodes(node*);
		int count_leaf();
		int count_leaf(node*);
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
void Tree::preorder()
{
	node *temp=root;
	stack s;
	cout<<"The pre-order traversal of the tree is as follows:";
	if(temp != NULL)
	{
		s.push(temp);
	}
	while(s.empty()==0)
	{
		temp=s.pop();
		cout<<temp->data;
		if(temp->right != NULL)
		{
			s.push(temp->right);
		}
		if(temp->left != NULL)
		{
			s.push(temp->left);
			temp=temp->left;
		}
	}
}
int Tree::count_nodes()
{
	count_nodes(root);
}
int Tree::count_nodes(node *root)
{
	static int count=0;
	if(root != NULL)
	{
		count++;
		count_nodes(root->left);
		count_nodes(root->right);
	}
	return count;
}
int Tree::count_leaf()
{
	count_leaf(root);
}
int Tree::count_leaf(node *root)
{
	static int count=0;
	if(root==NULL)
	return count;
		if(root->left==NULL && root->right==NULL)
		{
			count++;
		}
		count_leaf(root->left);
		count_leaf(root->right);
		return count;	
}
main()
{
	Tree t;
	int count;
	t.create();
	t.preorder();
	count=t.count_nodes();
	cout<<"\nThe total number of nodes in tree are:"<<count;
	count=t.count_leaf();
	cout<<"\nThe total number of leaf-nodes are:"<<count;
	
}

/*Enter the node to be attached:A
Any more nodes to be attached ? y
Enter the node to be attached:B
Node to be attached is to the [l/r] of the node A:l
Any more nodes to be attached ? y
Enter the node to be attached:C
Node to be attached is to the [l/r] of the node A:l
Node to be attached is to the [l/r] of the node B:l
Any more nodes to be attached ? y
Enter the node to be attached:D
Node to be attached is to the [l/r] of the node A:l
Node to be attached is to the [l/r] of the node B:l
Node to be attached is to the [l/r] of the node C:r
Any more nodes to be attached ? y
Enter the node to be attached:E
Node to be attached is to the [l/r] of the node A:r
Any more nodes to be attached ? y
Enter the node to be attached:F
Node to be attached is to the [l/r] of the node A:r
Node to be attached is to the [l/r] of the node E:l
Any more nodes to be attached ? y
Enter the node to be attached:G
Node to be attached is to the [l/r] of the node A:r
Node to be attached is to the [l/r] of the node E:l
Node to be attached is to the [l/r] of the node F:r
Any more nodes to be attached ? n
The pre-order traversal of the tree is as follows:ABCDEFG
--------------------------------
Process exited with return value 0
Press any key to continue . . .

*/
