#include <iostream>
#include <stack>
#include <vector>
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

void bstToArray(Node* root)
{
	if(root==NULL)
		return ;

	stack<Node*> s;
	Node* current=root;
	
	vector<int> result;
	
	while( current!=NULL || !s.empty() )
	{
		if(current == NULL)
		{
			current=s.top();
			result.push_back(current->data);
			s.pop();
			current=current->right;
		}
		else
		{
			s.push(current);
				current=current->left;
		}
	}
	
	for(auto & x: result)
		cout<<x<<" ";
	cout<<endl;
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

    bstToArray(root1);
	return 0;
}