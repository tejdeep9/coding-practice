#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <list>
using namespace std;

typedef unordered_map<char, list<char>> map;
typedef list<char> edges;


class Graph{
	unordered_map<char,list<char>> edgeMap;
	unordered_set<char> vertices;
	
	bool DFS(char v,unordered_set<char>& visited, char parent)
	{
		visited.insert(v);
		
		edges::iterator e;
		
		for(e=edgeMap[v].begin(); e!=edgeMap[v].end(); ++e)
		{
			//if not visited do the dfs again
			if(visited.find(*e)==visited.end())
			{
				if(DFS(*e,visited,v))
					return true;
				
			}
			
			//if the neighbour is visited and not the parent, cycle is present
			else if(*e!=parent)
				return true;
		}
		
		return false;
	}
	public:
	
	void addEdge(char v, char w)
	{
		vertices.insert(v);
		vertices.insert(w);
		edgeMap[v].push_back(w);
		edgeMap[w].push_back(v);
	}
	
	bool isCyclic()
	{
		unordered_set<char> visited;
		
		map::iterator it;
		visited.insert('\0');
		for(it=edgeMap.begin(); it!=edgeMap.end(); ++it)
		{
			char v=it->first;
			if(visited.find(v)==visited.end())
			{	if(DFS(v,visited,'\0'))
					return true;
			}
		}
		
		return false;
		
	}
	
	
};

int main() {
	Graph g;
	g.addEdge('a','f');
	g.addEdge('a','b');
	g.addEdge('b','c');
	g.addEdge('c','d');
	g.addEdge('d','e');
	//g.addEdge('e','b');
	
	
	if(g.isCyclic())
		cout<<"contains cycle"<<endl;
	else
		cout<<"it doesnt contain cycle"<<endl;
	return 0;
}