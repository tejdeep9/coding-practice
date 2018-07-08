#include <iostream>
#include <queue>
#include <algorithm>
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

int getHeight(Node* root)
{
	if(root==NULL)
		return 0;
	else
		return max(getHeight(root->left), getHeight(root->right))+1;
}

void printAtGivenLevel(Node* root, int level)
{
	if(root==NULL)
		return;
	if(level==0)
		cout<<root->data<<'\t';
	else if(level>0)
	{
		printAtGivenLevel(root->left,level-1);
		printAtGivenLevel(root->right,level-1);
	}
}

void recurReverseLevelOrder(Node* root)
{
	int h=getHeight(root);
	for(int i=h ;i>=0; i--)
		printAtGivenLevel(root,i);
	cout<<endl;
}
void reverseLevelOrderTraversal(Node* root)
{
	queue<Node*> q;
	stack<Node*> s;
	
	if(root)
		q.push(root);
	while(!q.empty())
	{
		Node* temp=q.front();
		q.pop();
		s.push(temp);
		if(temp->right!=NULL)
			q.push(temp->right);
		if(temp->left!=NULL)
			q.push(temp->left);
	}
	while(!s.empty())
	{
		cout<<s.top()->data<<'\t';
		s.pop();
	}
	cout<<endl;
}
int main() {
	Node* root1 = getNewNode(5);
	root1->left = getNewNode(2);
    root1->left->left = getNewNode(0);
    root1->left->right = getNewNode(3);
    root1->left->left->right = getNewNode(1);
    
	root1->right = getNewNode(6);
	root1->right->right = getNewNode(9);
    root1->right->right->left = getNewNode(7);
    root1->right->right->left->right = getNewNode(8);
    
    reverseLevelOrderTraversal(root1);
    recurReverseLevelOrder(root1);
  
	return 0;
}