#include <iostream>
using namespace std;
struct Node{
	int data;
	Node* next;
};

Node* getNewNode(int data)
{
	Node* newNode=new Node;
	newNode->data=data;
	newNode->next=NULL;
	return newNode;
}
/*
1.create two pointers k nodes apart(k-1 steps apart).
2.then iterate both the pointes untill secondPtr->next==NULL
3. The node start pointer is pointing to is the kth node from the last.

Time Complexity: O(n).
Space Complexity: O(1).
*/
Node* findKthElemFromLast_Iterative(Node* head,int k)
{
	if (head==NULL)
		return NULL;
	Node* start=head;
	Node* k_start=head;
	
	//make the k_start to point to the kth element.
	int i=0;
	while(i<k-1&&k_start->next!=NULL)
	{
		k_start=k_start->next;
		i++;
	}
	
	if(i!=k-1)
		return NULL;

	while(k_start->next!=NULL)
	{
		start=start->next;
		k_start=k_start->next;
	}
	
	return start;
}
/*
1.create a recursive function which takes k as reference variable.
2. when recursion hits the base case, return NULL.
3. when function starts returning decrement k,and check when k equals 0,
4. when k is 0 then return corresponding node.

Time Complexity: O(n).
Space Complexity: O(n).
*/
Node* findKthElemFromLast_Recursive(Node* head,int& k)
{
	if(head==NULL)
		return NULL;

	Node* res=findKthElemFromLast_Recursive(head->next,k);
	k--;
	if(k==0&&res==NULL)
	{
		return head;
	}
	else
		return res;
}
int main() {
	Node* node1=getNewNode(1);
	Node* node2=getNewNode(2);
	node1->next=node2;
	Node* node3=getNewNode(3);
	node2->next=node3;
	Node* node4=getNewNode(4);
	node3->next=node4;
	Node* node5=getNewNode(5);
	node4->next=node5;
	Node* node6=getNewNode(6);
	node5->next=node6;
	Node* node7=getNewNode(7);
	node6->next=node7;
	Node* node8=getNewNode(8);
	node7->next=node8;
	Node* node9=getNewNode(9);
	node8->next=node9;
	
	Node* res=findKthElemFromLast_Iterative(node1,3);
	if(res)
	cout<<res->data<<endl;

	return 0;
}