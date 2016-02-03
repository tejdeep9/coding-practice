#include <iostream>
#include <list>
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
/*
1.this algorithm runs in recursive fashion
2.create list of list of Node* in the main and pass it by reference, with level 0.
3.check the size of the list of list of Node* with level. 
4.if it equals then then this level is not covered.
    create a list and add node to it and add list to result.
5. else the level is also covered using iterator get the list created at particular level in the list.
	add the node to the existing list at that level.
6.now call the function recursively with root->left, root->right in that order.

Time Complexity:  O(n).
Space Complexity: O(logn) or O(H).

*/
void create_D_Lists_with_DFS(Node* root, list<list<Node*>>& result, int level)
{
	if (root == NULL)
		return;
	
	if (result.size() == level) //level is not present in the result
	{
		// but the levels 0 to level-1 are present in the result
		list<Node*> levelList;
		levelList.push_back(root);
		result.push_back(levelList);
		
	}
	else
	{
		list<list<Node*>>::iterator it = result.begin();
		advance(it, level);
		(*it).push_back(root);
		
	}
	
	create_D_Lists_with_DFS(root->left, result, level + 1);
	create_D_Lists_with_DFS(root->right, result, level + 1);
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

	list<list<Node*>> res;
	create_D_Lists_with_DFS(root1, res, 0);

	for (list<list<Node*>>::iterator it = res.begin(); it != res.end(); ++it)
	{
		for (list<Node*>::iterator it1 = (*it).begin(); it1 != (*it).end(); ++it1)
			cout << (*it1)->data << '\t';
		cout << endl;
	}

	return 0;
}