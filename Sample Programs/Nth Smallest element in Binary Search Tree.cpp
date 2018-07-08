#include <iostream>
#include <stack>
using namespace std;
struct Node
{
	int data;
	Node* right;
	Node* left;
};

Node* getNewNode(int data)
{
	Node* newNode= new Node;
	newNode->data=data;
	newNode->left=NULL;
	newNode->right=NULL;
	return newNode;
}

int kthSmallest(Node* root, int k)
{
	if(root==NULL)
		return -1;
	int result = 0;
	stack<Node*> s;
	Node* current=root;
	
	while( current!=NULL || !s.empty() )
	{
		if(current == NULL)
		{
			current=s.top();
			cout<<current->data<<" ";
			s.pop();
			k--;
			if(k==0)
				result=current->data;
			current=current->right;
			
			
		}
		else
		{
			s.push(current);
			current=current->left;
		}
	}
	return result;
}

int main() {

    //declare tree1
	Node* root1 = getNewNode(8);
	root1->left = getNewNode(3);
    root1->left->left = getNewNode(1);
    root1->left->right = getNewNode(6);

    
	root1->right = getNewNode(10);
    root1->right->right = getNewNode(14);
	root1->right->right->left = getNewNode(13);

    cout<<kthSmallest(root1,6);
	return 0;
}