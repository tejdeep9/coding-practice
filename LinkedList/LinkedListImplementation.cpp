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

Node* InsertAtHead(Node* head, int data)
{
	if(head==NULL)
	{
		head=getNewNode(data);
	}
	else
	{
		Node* temp= getNewNode(data);
		temp->next=head;
		head=temp;
	}
	return head;
}

Node* InsertAtNthPosition(Node* head, int data,int n)
{
	if(n<1)
	{	
		cout<<"unable to insert the node"<<endl;
		return head;
	}
	if(n==1) //insert at head
	{
		Node* temp=getNewNode(data);
		temp->next=head;
		head=temp;
	}
	else
	{
		Node* temp=head;
		//iterate n-2 times to get (n-1)th node
		int i;
		for(i=0;i<n-2&&temp->next!=NULL;i++)
			temp=temp->next;
		if(i<n-2)
		{
			cout<<"unable to insert the node"<<endl;
			return head;
		}
		
		Node* newNode=getNewNode(data);
		newNode->next=temp->next;
		temp->next=newNode;
	}
	return head;
}

Node* DeleteAtNthPosition(Node* head, int n)
{
	if(n<1)
	{
		cout<<"unable to delete the node"<<endl;
		return head;
	}
	if(n==1)
	{
		if(head==NULL)
			return head;
		Node* temp=head;
		head=head->next;
		delete temp;
	}
	else
	{
		//iterate n-2 times to get n-1th node and delete nth node;
		Node* temp=head;
		int i;
		for(i=0;i<n-2&&temp->next!=NULL;i++)
			temp=temp->next;
		if(i<n-2 ||temp->next==NULL)
		{
			cout<<"unable to delete the node"<<endl;
			return head;
		}

		Node* temp2=temp->next;
		temp->next=temp2->next;
		delete temp2;
	}
	return head;
}

void Display(Node* head)
{
	Node* temp=head;
	while(temp!=NULL)
	{
		cout<<temp->data<<'\t';
		temp=temp->next;
	}
	cout<<endl;
}
int main() {
	Node* head=NULL;
	head=InsertAtNthPosition(head,1,1);
	head=InsertAtNthPosition(head,-1,1);
	head=InsertAtNthPosition(head,2,2);
	head=InsertAtNthPosition(head,3,1);
	head=InsertAtNthPosition(head,4,3);
	head=InsertAtNthPosition(head,5,2);
	head=InsertAtNthPosition(head,6,4);
	head=InsertAtNthPosition(head,7,8);
	Display(head);
	head=DeleteAtNthPosition(head,4);
	Display(head);
	head=DeleteAtNthPosition(head,1);
	Display(head);
	head=DeleteAtNthPosition(head,6);
	Display(head);
	head=DeleteAtNthPosition(head,4);
	Display(head);
	head=DeleteAtNthPosition(head,5);
	Display(head);
	return 0;
}