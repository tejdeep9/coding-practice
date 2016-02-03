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
1. create list of list of nodes as the number of levels is unKnown.
2. create a list of nodes called 'current' and add the root to the list.
3. iterate till the current is empty, in the loop add the current to result.
	4. create a list of nodes called parent and add the current to the parent.
	5. iterate through each parent and add the children into the current and 
	   pop each parent until the parent is empty.
4. return the result.

Time Complexity:	O(n).
Space Complexity: O(logn) or O(H).   

*/
list<list<Node*>> create_D_Lists_with_BFS(Node* root)
{
	//create list of lists
	list<list<Node*>> result;
	list<Node*> current;
	
	if(root)
		current.push_back(root);

	while(!current.empty())
	{
		result.push_back(current);
		list<Node*> parent;
		parent.assign(current.begin(),current.end());
		current.clear();
		while(!parent.empty())
		{
			if(parent.front()->left)
				current.push_back(parent.front()->left);
			if(parent.front()->right)
				current.push_back(parent.front()->right);
			parent.pop_front();
		}
		
	}
	return result;

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
	list<list<Node*>> res=create_D_Lists_with_BFS(root1);

	for(list<list<Node*>>::iterator it=res.begin();it!=res.end();++it)
	{ 
		for(list<Node*>::iterator it1= (*it).begin();it1!=(*it).end();++it1)
			cout<<(*it1)->data<<'\t';
		cout<<endl;
	}

	return 0;
}