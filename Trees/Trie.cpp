#include <iostream>
using namespace std;

struct cnode
{
	int data;
	cnode* next;
};

cnode* getNewNode(int data)
{
	cnode* node = new cnode();
	node->data = data;
	node->next = NULL;
	return node;
}

cnode* insertSortedList(cnode* start, int data)
{
	//get the head node
	cnode* head = start;

	if (start == NULL)
	{
		head = start;
	}
	else
	{
		cnode* before = start;
		cnode* after = start->next;
		while (after != start && before->data <= after->data)
		{
			before = after;
			after = after->next;
		}
		head = after;
	}

	cnode* newNode = getNewNode(data);

	if (head == NULL)
	{
		head = newNode;
		newNode->next = newNode;
	}
	else if (data <= head->data)
	{
		cnode* current = head;


		while (current->next != head)
		{
			current = current->next;
		}

		current->next = newNode;
		newNode->next = head;

	}
	else //if the data is greater than the head 
	{
		cnode* prev = head;
		cnode* current = head->next;

		while (current != head && prev->data <= data && current->data <= data)
		{
			prev = current;
			current = current->next;
		}
		prev->next = newNode;
		newNode->next = prev;
	}

	return newNode;
}

void Display(cnode* start)
{
	cnode* temp = start;
	while (1)
	{
		cout << temp->data << "->";
		temp = temp->next;
		if (temp == start)
			break;
	}
	cout << endl;
	cout << endl;
}

int main() {
	cnode* node1 = NULL;
	node1 = insertSortedList(node1, 2);
	Display(node1);
	cnode* node2 = insertSortedList(node1, 9);
	Display(node1);
	cnode* node3 = insertSortedList(node1, 5);
	Display(node1);
	cnode* node4 = insertSortedList(node2, 7);
	Display(node2);
	cnode* node5 = insertSortedList(node1, 15);
	Display(node1);
	cnode* node6 = insertSortedList(node4, 10);
	Display(node4);
	cnode* node7 = insertSortedList(node3, 1);
	Display(node3);
	cnode* node8 = insertSortedList(node4, -1);
	Display(node4);
	cnode* node9 = insertSortedList(node2, 9);
	Display(node2);
	cnode* node10 = insertSortedList(node5, -1);
	Display(node5);
	cnode* node11 = insertSortedList(node9, 15);
	Display(node9);

	return 0;
}
