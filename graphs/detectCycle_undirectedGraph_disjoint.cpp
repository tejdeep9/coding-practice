#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <list>
using namespace std;

typedef unordered_map<char,list<char>> edgeMap;

struct Node
{
	char data;
	Node* parent;
	int rank;
};


class DisjointSet{
	unordered_map<char,Node*> map;
	
	Node* getNode(char data)
	{
		Node* newNode= new Node();
		newNode->parent=newNode;
		newNode->data=data;
		newNode->rank=0;
		return newNode;
	}
	
	public:
	
	void makeSet(char data)
	{
		Node* newNode=getNode(data);
		map[data]=newNode;
	}
	
	void unionSet(char data1, char data2)
	{
		//get the correspinding representative node
		Node* parent1=findSet(map[data1]);
		Node* parent2=findSet(map[data2]);
		
		if(parent1==parent2)
			return;
			
		if(parent1->rank >= parent2->rank)
		{
			parent2->parent=parent1;
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
	
	Node* findSet(Node* node)
	{
		if(node->parent == node)
		{
			return node;
		}
		node->parent=findSet(node->parent);
		return node->parent;
	}
	
	char findSet(char data)
	{
		return findSet(map[data])->data;
	}

};

struct edge
{
	char v1;
	char v2;
};

typedef unordered_set<char> vertices;

class Graph{
	
	edgeMap   eMap;
	vertices  nodes;
	
	public:
	
	void addEdge(char v, char w)
	{
		list<char> e=eMap[w];
		if(e.end() == find(e.begin(),e.end(),v))
			eMap[v].push_back(w);
		nodes.insert(v);
		nodes.insert(w);
	}
	
	list<edge> getEdges()
	{
		edgeMap::iterator it;
		list<edge> res;
		for(it=eMap.begin(); it!=eMap.end(); ++it)
		{
			for(list<char>::iterator j=it->second.begin(); j!=it->second.end(); j++)
			{
				edge ed={it->first, *j};
				res.push_back(ed);
			}
		}
		return res;
	}
	
	vertices getVertex()
	{
		return nodes;
	}
	
	bool detectCycle()
	{
		DisjointSet ds;
		for(vertices::iterator it=nodes.begin(); it!=nodes.end(); ++it)
		{
			ds.makeSet(*it);	
		}
		
		list<edge> edges=getEdges();
	
		for(list<edge>::iterator it=edges.begin(); it!=edges.end(); ++it)
		{
			//if the both parents are equal
			if(ds.findSet(it->v1)==ds.findSet(it->v2))
				return true;
			ds.unionSet(it->v1, it->v2);
		}
		return false;
	}
	
};




int main() {
	
	Graph g; 
	
	//g.addEdge('a','f');
	//g.addEdge('f','a');
	//g.addEdge('a','b');
	//g.addEdge('b','a');
	g.addEdge('b','c');
	g.addEdge('c','b');
	g.addEdge('b','e');
	g.addEdge('e','b');
	g.addEdge('e','d');
	g.addEdge('d','e');
	g.addEdge('d','c');
	g.addEdge('c','d');
	
	if(g.detectCycle())
		cout<<"has cycle"<<endl;
	else
		cout<<"DAG"<<endl;
	return 0;
}