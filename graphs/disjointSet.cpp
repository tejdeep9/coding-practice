#include <iostream>
#include <unordered_map>

using namespace std;
/*
Time Complexity: O(n) n: number of vertices 
Space Complexity: O(m* alpha(n)) m: number of operations, alpha(n)<=4 => O(m)
*/

struct Node
{
	int data;
	Node* parent;
	int rank;
};

class DisjointSet{
	unordered_map<int,Node*> map;
	
	Node* getNode(int data)
	{
		Node* newNode= new Node;
		newNode->data=data;
		newNode->parent=newNode;
		newNode->rank=0;
		return newNode;
	}
	public:
	
	//create an individual node
	void makeSet(int data)
	{
		Node* newNode= getNode(data);
		map[data]=newNode;
	}
	
	//union two individual sets
	void unionSet(int data1, int data2)
	{
		//get the correspoding nodes
		if(map.find(data1)==map.end() || map.find(data2)==map.end())
			return;
		Node* node1=map[data1];
		Node* node2=map[data2];
		
		Node* parent1=findSet(node1);
		Node* parent2=findSet(node2);
		
		//if they both belong to the same set
		if(parent1==parent2)
			return;
			
		//check the rank to assign them to the sets
		if(parent1->rank >= parent2->rank)
		{
			parent2->parent=parent1;
			//if they are equal increase rank of 1 and zero the  other
			if(parent1->rank==parent2->rank) 
			{
				parent1->rank++;
				parent2->rank=0;
			}
		}
		else
		{
			parent1->parent=parent2;
		}
		
	}
	
	//returns the value of parent node of corresponding set where the data is present
	int findSet(int data)
	{
		return findSet(map[data])->data;
	}
	
	//returns the representative node of the set and
	//does the path compression
	Node* findSet(Node* node)
	{
		if(node->parent==node)
			return node;
		node->parent= findSet(node->parent);
		return node->parent;
	}
	
};

int main() {
	DisjointSet ds;
	ds.makeSet(1);
	ds.makeSet(2);
	ds.makeSet(3);
	ds.makeSet(4);
	ds.makeSet(5);
	ds.makeSet(6);
	ds.makeSet(7);
	
	ds.unionSet(1,2);
	ds.unionSet(2,3);
	ds.unionSet(4,5);
	ds.unionSet(6,7);
	ds.unionSet(5,6);
	ds.unionSet(3,7);
	
	for(int i=1; i<=7; i++)
		cout<<ds.findSet(i)<<endl;
	return 0;
}