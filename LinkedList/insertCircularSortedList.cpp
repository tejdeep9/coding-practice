#include <iostream>
using namespace std;

struct cnode{
	int value;
	cnode* next;
};

cnode* getNewNode(int data)
{
	cnode* newNode = new cnode;
	newNode->value = data;
	newNode->next = NULL;
	return newNode;
}

cnode* insertSortedList(cnode* start, int n)
{
	cnode* newNode = getNewNode(n);
	if (start == NULL)
	{
		start = newNode;
		start->next = start;
	}
	else
	{
		cnode* current = start;
		cnode* prev = NULL;
		//if 'n' is less than start value


		while (current->value > n )
		{
			prev = current;
			current = current->next;
			if (current == start || (prev->value > current->value))
				break;

		}
	
		while (current->value <= n )
		{
			prev = current;
			current = current->next;
			if (current == start || (prev->value > current->value))
				break;

		}

		prev->next = newNode;
		newNode->next = current;

	}

	return newNode;
}

void Display(cnode* start)
{
	cnode* temp = start;
	while (1)
	{
		cout << temp->value << "->";
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