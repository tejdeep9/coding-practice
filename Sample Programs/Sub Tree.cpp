#include <iostream>
using namespace std;
struct Node
{
	int data;
	Node* left;
	Node* right;
};
Node* getNewNode(int data)
{
	Node* newNode = new Node;
	newNode->data = data;
	newNode->left = nullptr;
	newNode->right = nullptr;
	return newNode;
}
//check whether both trees are identical
bool areMatching(Node* root1, Node* root2){
	//if both are null then return
	if (root1 == nullptr&&root2 == nullptr)
		return true;
	//if anyone of them are null then they wont match
	if (root1 == nullptr || root2 == nullptr)
		return false;
	//check from the root element to left of right element
	if (root1->data == root2->data&&areMatching(root1->left, root2->left) && areMatching(root1->right, root2->right))
		return true;
	return false;
}
bool isSubtree(Node* root1, Node* root2)
{
	if (root1 == nullptr)
		return false;
	if (root2 == nullptr)
		return true;
	//check whether they are matching or not
	if (areMatching(root1, root2))
		return true;
	//if they are not matching check whether the left or right subtrees are matching
	if (isSubtree(root1->left, root2) || isSubtree(root1->right, root2))
		return true;
	return false;
}
void InorderTraversal(Node* root)
{
	if (root == nullptr)
		return;
	InorderTraversal(root->left);
	cout << root->data << "\t";
	InorderTraversal(root->right);
}
int main() 
{
	//declare tree1
	Node* root1 = getNewNode(26);
	root1->left = getNewNode(10);
	root1->right = getNewNode(3);
	root1->right->right = getNewNode(3);
	root1->left->left = getNewNode(4);
	root1->left->left->right = getNewNode(30);
	root1->left->right = getNewNode(6);
	//declare tree2
	Node* root2 = getNewNode(10);
	root2->left = getNewNode(4);
	root2->left->right = getNewNode(30);
	root2->right = getNewNode(6);
	if (isSubtree(root1, root2))
	cout << "tree2 is subtree of tree1" << endl;
	else
	cout << "tree2 is not a subtree" << endl;
	return 0;
}