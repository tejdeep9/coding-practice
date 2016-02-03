
/*
level order travesal or Breadth First Search
algorithm: 
1.Insert root node into the queue
2.while queue is not empty, put the left and right nodes of the top element 
  in the queue.
3.pop the element, Untill the loop gets executed the elements
  are poped in the inorder traversal fashion.
  
  Time complexity: O(n).
  Space Complexity : O(1).
*/
#include <iostream>
#include <queue>

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

void LevelOrderTraversal(Node* root)
{
	queue<Node*> q;
	//load the root
	if(root)
		q.push(root);
	while(!q.empty())
	{	
		cout<<q.front()->data<<'\t';
		if(q.front()->left)
			q.push(q.front()->left);
		if(q.front()->right)
			q.push(q.front()->right);
		q.pop();
	}
	
	cout<<endl;
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
    LevelOrderTraversal(root1);
	return 0;
}