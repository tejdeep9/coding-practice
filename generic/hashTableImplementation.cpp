#include <iostream>
#include <cstring>
#define SIZE 20
using namespace std;

struct Node{
	char* key;
	char* value;
	Node* next;
};

Node* hashTable[SIZE]={NULL};

int hashValue(char* key)
{
	int val=0;
	int count=0;
	int n=strlen(key);
	for(int i=0; i<n; i++)
	{
		val=val*key[i]+key[i]+count;
		count++;
	}
	val=abs(val);
	val=val%SIZE;
	return val;
}

Node* getNewNode(char* key, char* value)
{
	Node* newNode= new Node;
	newNode->key=key;
	newNode->value=value;
	newNode->next=NULL;
	return newNode;
}

void put(char* key, char* value)
{
	int index=hashValue(key);
	Node* head=hashTable[index];
	if(head==NULL)
	{
		Node* newNode=getNewNode(key,value);
		hashTable[index]=newNode;
	}
	else
	{
		while(head!=NULL)
		{
			if(strcmp(key, head->key)==0)
			{
				head->value=value;
				return;
			}
			head=head->next;
			
		}
		Node* newNode=getNewNode(key,value);
		newNode->next=hashTable[index];
		hashTable[index]=newNode;
		
	}
}

char* get(char* key)
{
	int index=hashValue(key);
	Node* head=hashTable[index];
	while(head!=NULL)
	{
		if(strcmp(head->key,key)==0)
		{
			return head->value;
		}
	}
	return NULL;
}
int main() {
	put("alpha","bravo");
    put("zero", "0");
    put("alpha", "charlie");
    cout<< get("alpha")<<endl;
    cout<<get("zero")<<endl;
	return 0;
}