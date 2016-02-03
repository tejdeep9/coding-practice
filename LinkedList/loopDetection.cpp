/*
algorithm:
1. initialize slow and fast pointer to head. slow moves one step at a time, fast moves two steps at a time.
2. suppose we need to return the node at the beginning of the loop. by the time slow reaches the loop in k steps
   // the fast is already k steps ahead of slow, as it is in the loop fast is LOOP_SIZE-K times behind the slow.
3. Hence they will meet in LOOP_SIZE-K steps, when they do so the collision point will be K steps behind loop start.
4. make slow to point to the beginning of the loop, and fast to the collision point, move them one step a time.
5. slow needs K steps for start of the loop, fast runner will take K steps, the point they meet is start of the loop.

Time Complexity: O(n).
Space Complexity: O(1).
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

Node* loopDetection(Node* head)
{
	if(head==NULL)
		return NULL;
		
	Node* slow=head;
	Node* fast=head;
	while(fast!=NULL&&fast->next!=NULL)
	{
		slow=slow->next;
		fast=fast->next->next;
		if(slow==fast) //collision
			break;
	}
	
	//if the list doesnt contain the loop
	if(fast==NULL || fast->next==NULL)
		return NULL; 
	
	slow=head;
	while(slow!=fast) //breaks when it encounters star of the loop
	{
		slow=slow->next;
		fast=fast->next;
	}
	
	return slow;
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
	Node* node10=getNewNode(10);
	node9->next=node10;
	Node* node11=getNewNode(11);
	node10->next=node11;
	node11->next=node4;
	
	Node* res=loopDetection(node1);
	cout<<res->data<<endl;
	return 0;
}