/*
Spiral order traversal
algorithm:
1.create two stacks, even and odd.
2.Even stack pushes the node from left to right
3.Odd stack pushes nodes from right to left
3.push the  root to the even stack.

Time Complexity:O(n).
Space Complexity: O(n).
*/

#include <iostream>
#include <stack>
using namespace std;

struct Node{
	int data;
	Node* left;
	Node* right;
};

Node* getNewNode(int data){
	Node* newNode = new Node;
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

void SpiralOrderTraversal(Node* root)
{
	stack<Node*> even_stack; //stack to store even level nodes
	stack<Node*> odd_stack; //stack to store odd level nodes

	if (root)
		even_stack.push(root);//root comes under even level stack. level 0
	bool evenLevel = true;

	while (!even_stack.empty() || !odd_stack.empty())
	{
		if (evenLevel)
		{
			while (!even_stack.empty())
			{
				//Node* temp = even_stack.top();
				//store the nodes from right to left
				if (even_stack.top()->right)
					odd_stack.push(even_stack.top()->right);
				if (even_stack.top()->left)
					odd_stack.push(even_stack.top()->left);
				cout << even_stack.top()->data << '\t';
				even_stack.pop();
			}
		}
		else
		{
			while (!odd_stack.empty())
			{
				//store the nodes from left to right
				if (odd_stack.top()->left)
					even_stack.push(odd_stack.top()->left);
				if (odd_stack.top()->right)
					even_stack.push(odd_stack.top()->right);
				cout << odd_stack.top()->data << '\t';
				odd_stack.pop();
			}
		}
		evenLevel = !evenLevel;

	}

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
	SpiralOrderTraversal(root1);
	return 0;
}