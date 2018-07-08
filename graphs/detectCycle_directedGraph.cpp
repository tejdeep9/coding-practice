#include <iostream>
#include <unordered_set>
#include <list>
 

using namespace std;
typedef unordered_set<int> set;

/*
Time and Space: O(V+E)
*/ 
class Graph{
	int v;
	list<int>* adj;
	void moveVertex(int vertex, set& source, set& dest)
	{
		if(source.find(vertex)!=source.end())
			source.erase(vertex);
		if(dest.find(vertex)==dest.end())
			dest.insert(vertex);
	}
 
	bool DFS(int v,set& unvisited, set& recursionSet, set& visited)
	{
		//move the vertex from unvisited to the recursion set
		moveVertex(v,unvisited,recursionSet);
		list<int>::iterator s;
 
		//for each edge do the dfs
		for(s=adj[v].begin(); s!=adj[v].end(); s++)
		{
			//if visited skip it
			if(visited.find(*s)!=visited.end())
				continue;
 
			//if neighbour is in recursion set there is a cycle	
			if(recursionSet.find(*s)!=recursionSet.end())
				return true;
 
			//if unvisited do the dfs 
			if(unvisited.find(*s)!=unvisited.end())
			{
				if(DFS(*s,unvisited,recursionSet,visited))
				{
 
					cout<<" <- "<<*s;
					return true;
				}
			}
 
		}
 
		//after exploring the vertex move it to visited vertex;
		moveVertex(v,recursionSet,visited);
 
		return false;
	}
 
	public:
 
	Graph(int v)
	{
		this->v=v;
		adj= new list<int>[v];
	}
 
	void addEdge(int v, int w)
	{
		adj[v].push_back(w);
	}
 
	bool detectCycle()
	{
		set unvisited;
		set recursionSet;
		set visited;
 
		for(int i=0; i<v; i++)
			unvisited.insert(i);
 
		set::iterator it;
		while(unvisited.size()>0)
		{
			it=unvisited.begin();
			if(DFS(*it,unvisited,recursionSet,visited))
			{
				cout<<" <- "<<*it;
				cout<<endl;
				return true;
			}
 
		}
 
		return false;
 
	}
 
 
};
int main() {
	Graph g(5);
 
	g.addEdge(0, 1);
	g.addEdge(2, 0);
	g.addEdge(2, 3);
	g.addEdge(3, 4);
	g.addEdge(4, 2);
 
	if(g.detectCycle())
		cout<<"not DAG"<<endl;
	else
		cout<<"DAG"<<endl;
	return 0;
}