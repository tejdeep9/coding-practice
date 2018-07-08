#include <iostream>
#include <cstring>

using namespace std;

class Node{
public:
	char* key;
	char* value;
	Node* next;
	Node(char* key, char* value)
	{
		this->key = key;
		this->value = value;
		this->next = nullptr;
	}
};

class HashTable
{
private:
	int SIZE;
	Node** table;
	int hash(char* item)
	{
		int n = strlen(item);
		int value = 0;
		for (int i = 0; i<n; i++)
			value += item[i];

		return (value * n) % SIZE;
	}

public:

	HashTable(int SIZE)
	{
		this->SIZE = SIZE;
		table = new Node*[SIZE];
		for (int i = 0; i < SIZE; i++)
			table[i] = nullptr;
	}

	void insert(char* key, char* value)
	{
		int index = hash(key);
		Node* head = table[index];

		if (head == nullptr)
		{
			head = new Node(key, value);
			table[index] = head;
			return;
		}
		else
		{
			while (head != nullptr)
			{
				if (strcmp(head->key, key) == 0)
				{
					head->value = value;
					return;
				}
				head = head->next;
			}

			Node* newNode = new Node(key, value);
			newNode->next = table[index];
			table[index] = newNode;
		}

	}

	char* get(char* key)
	{
		int index = hash(key);
		Node* head = table[index];

		if (head == nullptr)
			return "";

		while (head != nullptr)
		{
			if (strcmp(head->key, key) == 0)
				return head->value;
		}
		return "";
	}

	void removeNode(char* key)
	{
		int index = hash(key);
		Node* head = table[index];

		if (head == nullptr)
			return;

		if (strcmp(head->key, key) == 0)
		{
			Node* temp = head;
			head = head->next;
			delete temp;
			table[index] = head;
		}

		if (head == nullptr)
			return;
		Node* current = head->next;
		Node* prev = head;
		while (current != NULL)
		{
			if (strcmp(current->key, key) == 0)
			{
				Node* temp = current;
				current = current->next;
				prev->next = current;
				delete temp;
			}
			prev = current;
			current = current->next;
		}

	}

};



int main() {

	HashTable h(20);
	h.insert("alpha", "bravo");
	h.insert("alpha", "charlie");
	cout << h.get("alpha") << endl;
	h.removeNode("alpha");
	cout << h.get("alpha") << endl;
	cout << h.get("zero") << endl;
	return 0;
}
