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
Node* seggregateOddEven(Node* head)
{
	if(head==NULL)
		return head;
	Node* odd=head->next,*oddHead=head->next,*even=head,*evenHead=head,*prevOdd=NULL;
	while(odd!=NULL&&even!=NULL&&even->next!=NULL&&odd->next!=NULL)
	{
		even->next=odd->next;
		even=even->next;
		if(even!=NULL)
		{
			prevOdd=odd;
			odd->next=even->next;
			odd=odd->next;
		}
	}
	if(even)
		even->next=NULL;
		
	if(odd==NULL)
		prevOdd->next=evenHead;
	else
		odd->next=evenHead;
	//Display(oddHead);
	//Display(evenHead);
	return oddHead;
}

int main() {
	Node* head=NULL;
	head=insert(head,10);
	head=insert(head,9);
	head=insert(head,8);
	head=insert(head,7);
	head=insert(head,6);
	head=insert(head,5);
	head=insert(head,4);
	head=insert(head,3);
	head=insert(head,2);
	head=insert(head,1);
	head=insert(head,0);
	Display(head);
	head=seggregateOddEven(head);
	Display(head);
	return 0;
}