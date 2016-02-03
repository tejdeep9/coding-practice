/*
    algorithm: (assumption , the valu1<=value2)
    1.check if the root is null
    2.check whether the current node value >value1 && current node value <value 2, if so return.
    3.check if the current node value is either value1, or value 2, if so return current node.
    4.If the value2 is less than current value call the function recursively with root as root->left.
    5.If the value2 is greater than current value call the function recursively with root as root->right.
    
    Time Complexity O(log(n))
    Space Complexity O(1).
    
*/

#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};
Node* getNewNode(int data){
    Node* newNode= new Node;
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}

bool checkNode(Node* root,int n)
{
    if(root==NULL)
        return false;
    if(root->data==n)
        return true;
    if(root->data>n)
        return checkNode(root->left,n);
    else
        return checkNode(root->right,n);
}
//function to find Lowest common ancestor
Node* findLCA(Node* root, int n1, int n2)
{
    if(root==NULL)
        return NULL;
    if(root->data>n1 && root->data<n2)
        return root;
    if(root->data==n2 || root->data==n1)
        return root;
    if(root->data>n2)
        return findLCA(root->left,n1,n2);
    else
        return findLCA(root->right,n1,n2);
}

//driver program makes sure that n1<=n2 even when supplied in reverse fashion.
Node* driver(Node* root, int n1, int n2)
{
    if(n1>n2)
    {
        int temp=n1;
        n1=n2;
        n2=temp;
    }
    if(checkNode(root,n1)&&checkNode(root,n2))
        return findLCA(root,n1,n2);
    else
        return NULL;
}
int main()
{
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
    
    Node* temp=driver(root1,2,9);
    if(temp)
        cout<<"LCA is "<<temp->data<<endl;
    return 0;
}