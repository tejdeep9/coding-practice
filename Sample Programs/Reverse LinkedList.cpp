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
	newNode->next=NULL;
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

Node* reverseLinkedList_Iter(Node* head)
{
	Node* prev, *current, *next;
	prev=NULL;
	current=head;
	while(current!=NULL)
	{
		next=current->next;
		current->next=prev;
		prev=current;
		current=next;
	}
	head= prev;
	return head;
}

Node* reverseLinkedList_recur(Node* head,Node* node)
{
	if(node->next==NULL)
	{
		head=node;
		return head;
	}
	head= reverseLinkedList_recur(head,node->next);
	Node* temp= node->next;
	temp->next=node;
	node->next=NULL;
	return head;
}
int main() {
	Node* head=NULL;
	head=insert(head,1);
	head=insert(head,2);
	head=insert(head,3);
	head=insert(head,4);
	head=insert(head,5);
	Display(head);
	head=reverseLinkedList_Iter(head);
	Display(head);
	head=reverseLinkedList_recur(head,head);
	Display(head);
	return 0;
}