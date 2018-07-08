#include <iostream>
using namespace std;
struct Node
{
	int data;
	Node* next;
};

Node* getNewNode(int data)
{
	Node* newNode=new Node;
	newNode->data=data;
	newNode->data=data;
	return newNode;
}

Node* insert(Node* head, int data)
{
	Node* newNode= getNewNode(data);
	newNode->next=head;
	head=newNode;
	return head;
}

void Display(Node* head)
{
	while(head!=NULL)
	{
		cout<<head->data<<',';
		head=head->next;
	}
	cout<<endl;
}
Node* reverseLinkedList(Node* head)
{
	Node* prev,* current,* next;
	current=head;
	prev=NULL;
	while(current!=NULL)
	{
		next=current->next;
		current->next=prev;
		prev=current;
		current=next;
	}
	head=prev;
	return head;
}

Node* reverseHalfLinkedList(Node* head)
{
	if(head==NULL)
		return head;
		
	Node* oneHop=head, *twoHops=head,*prev;
	while(twoHops!=NULL && twoHops->next!=NULL)
	{
		prev=oneHop;
		oneHop=oneHop->next;
		twoHops=twoHops->next->next;
	}
	
	if(twoHops==NULL) //even length
	{
		prev->next=reverseLinkedList(oneHop);
	}
	else
	{
		oneHop->next=reverseLinkedList(oneHop->next);
	}
	
	return head;
}
int main() {
	Node* head=NULL;
	//head=insert(head,7);
	head=insert(head,1);
	head=insert(head,2);
	head=insert(head,4);
	head=insert(head,6);
	head=insert(head,-1);
	head=insert(head,5);
	head=insert(head,3);
	Display(head);
	head=reverseHalfLinkedList(head);
	Display(head);
	return 0;
}