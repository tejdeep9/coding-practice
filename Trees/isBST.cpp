#include <iostream>
#include <limits>
using namespace std;

struct Node{
	int data;
	Node* left;
	Node* right;
};

Node* getNewNode(int data)
{
	Node* newNode= new Node;
	newNode->data=data;
	newNode->left=NULL;
	newNode->right=NULL;
	return newNode;
}


bool isBST(Node* root,int maxValue, int minValue)
{
	if(root==NULL)
		return true;
	if(root->data<maxValue && root->data>=minValue && isBST(root->left,root->data,minValue)
	&& isBST(root->right,maxValue,root->data))
		return true;
	else
		return false;
}
int main() {
	//declare tree1
	Node* root1 = getNewNode(5);
	root1->left = getNewNode(2);
	root1->left->left = getNewNode(0);
	root1->left->right = getNewNode(3);
	root1->left->left->right = getNewNode(1);

	root1->right = getNewNode(6);
	root1->right->right = getNewNode(9);
	root1->right->right->left = getNewNode(7);
	root1->right->right->left->right = getNewNode(8);
	
	int maxValue=numeric_limits<int>::max();
	int minValue=numeric_limits<int>::min();
	
	if(isBST(root1,maxValue,minValue))
		cout<<"given tree is BST"<<endl;
	else
		cout<<"not BST"<<endl;
	
	return 0;
}