/*
1. create a getHeight function, and pass root->left and root->right seperately to these functions.
2. if the height left subtree or right subtree is greater than 1 compared to each other the tree is not balanced.
3. for the BST to be balanced the height differenc between left subtree and right subtree should be atmost one.

Time Complexity: O(n). as algorithm visits all the nodes
Space Complexity: O(H). H is the  height of the tree.
*/

#include <iostream>
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
	newNode->left=NULL;
	newNode->right=NULL;
	return newNode;
}

int getHeight(Node* root)
{
	if(root==NULL)
		return -1;
	return max(getHeight(root->left),getHeight(root->right))+1;
}

bool checkBalance(Node* root)
{
	if(root==NULL)
		return true;
	int leftHeight=getHeight(root->left);
	int rightHeight=getHeight(root->right);
	if(abs(leftHeight-rightHeight)>1)
		return false;
	else
		return true;
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
	if(checkBalance(root1))
		cout<<"balanced"<<endl;
	else
		cout<<"not balanced"<<endl;
	return 0;
}