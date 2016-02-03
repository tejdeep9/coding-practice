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
  newNode->left=nullptr;
  newNode->right=nullptr;
  return newNode;
}

Node* buildBalancedBST(int* arr, int start, int end)
{
  if(start>end)
    return nullptr;
  int mid=(start+end)/2;
  Node* root=getNewNode(arr[mid]);
  root->left=buildBalancedBST(arr,start,mid-1);
  root->right=buildBalancedBST(arr,mid+1,end);
  
  return root;
}

void InorderTraversal(Node* root)
{
  if(root==nullptr)
    return; 
  InorderTraversal(root->left);
  cout<<root->data<<'\t';
  InorderTraversal(root->right);
}
int main() {
  int arr[]={1,2,3,4,5,6,7,8,9};
  Node* root=buildBalancedBST(arr,0,8);
  InorderTraversal(root);
  return 0;
}
