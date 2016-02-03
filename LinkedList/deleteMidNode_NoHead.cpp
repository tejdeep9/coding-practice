/*
algorithm:
1. delete the node given (no head is provided).
2. if node->next is not null, copy the data from next node and delete the given node.
3.if(node->next is NULL , copy the node and make it point to the NULL, delete the copy)
	
Time Complexity: O(1).
Space Complexity O(1).

*/

#include <iostream>
using namespace std;

struct Node{
	int data;
	Node* next;
};

Node* getNewNode(int data)
{
	Node* newNode= new Node;
	newNode->data=data;
	newNode->next=NULL;
	return newNode;
}

void deleteNode(Node* node)
{
	if(node==NULL)
		return;
	if(node->next!=NULL)
	{
		Node* temp=node->next;
		node->data=node->next->data;
		node->next=node->next->next;
		delete temp;
	}
	else
	{
		Node* temp=node;
		node=NULL;
		delete temp;
	}
	
}

void display(Node* head)
{
	if(head==NULL)
		return;
		
	while(head)
	{
		cout<<head->data<<'\t';
		head=head->next;
	}
	cout<<endl;
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
	display(node1);
	deleteNode(node3);
	display(node1);
	return 0;
}