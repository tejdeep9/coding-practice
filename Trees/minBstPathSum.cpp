#include <iostream>
#include <limits>
#include <algorithm>
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


int minBstPathSum(Node* root)
{
	if(root==NULL)
		return 0;

	int value=root->data,leftSum,rightSum;
	
	if (root->left==NULL && root->right==NULL)
		return value;
	else if(root->left==NULL)
	{
		rightSum=minBstPathSum(root->right);
		leftSum=numeric_limits<int>::max();
	}
	else
	{
		leftSum=minBstPathSum(root->left);
		rightSum=numeric_limits<int>::max();
	}
	
	int sum=min(leftSum,rightSum);
	sum+=value;
	
	return sum;

}

//alternate solution
int minBstPathSum(Node* root)
{
    if(root==NULL)
        return INT_MAX;
    
    //dangling node
    if(root->left ==NULL && root->right==NULL)
        return root->data;
        
    int leftSum= minBstPathSum(root->left);
    int rightSum= minBstPathSum(root->right);
    
    return min(leftSum,rightSum)+root->data;
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
	
	
	cout<<"the minimum sum of the path in a given BST is "<<minBstPathSum(root1)<<endl;
	
	return 0;
}