/*Binary Search Tree*/
/*Create And BFS traversal*/
#include<iostream>
#include<conio.h>
#define MAX 20
using namespace std;
class Tree;
class Node{
	int data;
	Node *left;
	Node *right;
	public:
		Node(int node_value){
			data=node_value;
			left=right=NULL;
		}
		friend class Tree;
};
class Tree{
	Node *root;
	public:
		Tree(){
			root=NULL;
		}
		void create();
		void BFS();
};
class Queue{
	int front,rear;
	Node *item[MAX];
	public:
		Queue(){
			front=rear=-1;
		}
		int isempty(){
			if((front == -1 && rear==-1) || front > rear){
				return 1;
			}
			return 0;
		}
		void enqueue(Node *p){
			if(isempty()){
				front++;
				rear++;
				item[rear] = p;
			}else{
				item[++rear] = p; 
			}
		}
		Node* dequeue(){
			return item[front++];
		}	
};
void Tree::create()
{
	Node *temp;
	int value;
	char ch;
	do{
		cout<<"\nEnter the data:";
		cin>>value;
		Node *newnode = new Node(value);
		if(root == NULL){
			root=temp=newnode;
	    }else{
	    	temp=root;
	    	while(true){
	    		if(value < temp->data){
	    			if(temp->left==NULL){
	    				temp->left = newnode;
	    		     	break;
	    			}else{
	    				temp=temp->left;
	    			}	
	    		}else if(value > temp->data){
	    			if(temp->right == NULL){
	    				temp->right=newnode;
	    				break;
	    			}else{
	    				temp=temp->right;
	    			}
	    		}
	    		
	    	}
	    }
	    cout<<"Any more nodes ? [y/n] ";
	    ch=getch();
	}while(ch == 'y' || ch == 'Y');
}
void Tree::BFS()
{
	Node *temp = root;
	Node *dummy = NULL;
	Queue q;
	q.enqueue(temp);
	q.enqueue(dummy);
	
	int level = 0;
	cout<<"\nLevel "<<level<<":  ";
	
	do{
		temp = q.dequeue();
		if(temp != NULL){
			cout<<temp->data<<" ";
			if(temp->left != NULL){
				q.enqueue(temp->left);
			}
			if(temp->right != NULL){
				q.enqueue(temp->right);
			}
		}
		else{
			if(!q.isempty()){
				level++;
				cout<<"\nLevel "<<level<<":  ";
				q.enqueue(dummy);
			}
		}
	}while(!q.isempty());
}
main()
{
	Tree t;
	cout<<"Create the binary search tree !!\n";
	t.create();
	cout<<"\nThe levelwise BFS traversal:";
	t.BFS();
}
