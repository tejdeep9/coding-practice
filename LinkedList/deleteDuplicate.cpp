/*
with Buffer:
	1. store each elemnet in the unordered_set, when duplicate occurs delete particular node.
	2.while deleting node make sure to save previous node and change its link to node after delete node.
 
 Time complexity: O(n)
 Space Complexity: O(n)

 Without Bufffer:
	1. store the current node.
	2. for each current node, create runner = current->next;
	3. for each runner check whether current->next==runner->next, if so delete it.
	4. make sure to save previous node while deleting and change its link to node after next.
Time Complexity: O(n2).
Space Complexity: O(1).
*/
#include <iostream>
#include <unordered_set>

using namespace std;
struct Node{
	int data;
	Node* next;
};

Node* getNewNode(int data)
{
	Node* newNode = new Node;
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

Node* InsertAtHead(Node* head, int data)
{
	if (head == NULL)
		head = getNewNode(data);
	else
	{
		Node* temp = getNewNode(data);
		temp->next = head;
		head = temp;
	}
	return head;
}

void Display(Node* head)
{
	while (head)
	{
		cout << head->data << '\t';
		head = head->next;
	}
}
void DeleteDupNoBuffer(Node* head)
{
	Node* current = head;
	while (current)
	{
		Node* runner = current->next;
		Node* prev = current;
		while (runner)
		{
			
			if (current->data == runner->data)
			{
				Node* temp = runner;
				prev->next = runner->next;
				runner = runner->next;
				delete temp;
				continue;
			}
			prev = runner;
			runner = runner->next;
		}
		current = current->next;
	}

}
void DeleteDupWithBuffer(Node* head)
{
	unordered_set<int> bucket;
	Node* prev = NULL;
	while (head)
	{
		if (bucket.find(head->data) == bucket.end())
		{
			bucket.insert(head->data);
			prev = head;
			head = head->next;
		}
		else
		{
			Node* temp = head;
			head = head->next;
			prev->next = head;
			delete temp;
		}

	}

}
int main() {
	Node* head = NULL;
	head = InsertAtHead(head, 1);
	head = InsertAtHead(head, 5);
	head = InsertAtHead(head, 6);
	head = InsertAtHead(head, 2);
	head = InsertAtHead(head, 2);
	head = InsertAtHead(head, 2);
	head = InsertAtHead(head, -1);
	head = InsertAtHead(head, 6);
	head = InsertAtHead(head, 1);
	Display(head);
	cout << endl;
	//DeleteDupWithBuffer(head);
	DeleteDupNoBuffer(head);
	Display(head);

	return 0;
}