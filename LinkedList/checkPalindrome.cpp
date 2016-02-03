#include <iostream>
#include <stack>
using namespace std;

struct Node{
	int data;
	Node* next;
};

Node* getNewNode(int data)
{
	Node* newNode = new Node;
	newNode->data=data;
	newNode->next=NULL;
	return newNode;
}
bool checkPalindrome(Node* head)
{
	if(head==NULL)
		return NULL;
		
	stack<int> s;
	Node* slow= head;
	Node* fast=head;
	while(fast!=NULL&& fast->next!=NULL)
	{
		s.push(slow->data);
		slow=slow->next;
		fast=fast->next->next;
	}
	
	//for the odd length palindrome.
	if(fast!=NULL&&fast->next==NULL)
	slow=slow->next;
	
	while(slow!=NULL)
	{
		if(slow->data!=s.top())
		 	return false;
		slow=slow->next;
		s.pop();
	}
	
	return true;
}
int main() {
	Node* node1 = getNewNode(0);
	Node* node2 = getNewNode(1);
	node1->next = node2;
	Node* node3 = getNewNode(2);
	node2->next = node3;
	Node* node4 = getNewNode(2);
	node3->next = node4;
	Node* node5 = getNewNode(1);
	node4->next = node5;
	Node* node6 = getNewNode(0);
	node5->next = node6;
	
	if(checkPalindrome(node1))
	cout<<"is palindrome"<<endl;
	return 0;
}
