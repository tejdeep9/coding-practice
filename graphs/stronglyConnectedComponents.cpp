#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <list>
#include <string>
using namespace std;

typedef unordered_map<char, list<char>> map;
typedef list<char> neighbours;
typedef unordered_set<char> vertices;
class Graph
{
	vertices nodes;
	map edges;
	map reverseEdges;
	map edgeMap;

	void DFS(char v, vertices& visited, int reverse, stack<char>& topSort, string& str)
	{
		visited.insert(v);

		neighbours::iterator e;

		for (e = edgeMap[v].begin(); e != edgeMap[v].end(); ++e)
		{
			if (visited.find(*e) == visited.end())
				DFS(*e, visited, reverse, topSort, str);

		}

		if (!reverse)
			topSort.push(v);
		else
		{
			str = v + str;
		}
	}

public:

	void addEdge(char v, char w)
	{
		nodes.insert(v);
		nodes.insert(w);
		edges[v].push_back(w);
		reverseEdges[w].push_back(v);
	}

	void strongContedComp()
	{
		vertices visited;
		stack<char> topSort;
		list<string> result;
		vertices::iterator v;

		edgeMap = edges;
		for (v = nodes.begin(); v != nodes.end(); ++v)
		{
			string str = "";
			if (visited.find(*v) == visited.end())
				DFS(*v, visited, 0, topSort, str);
		}

		visited.clear();
		edgeMap = reverseEdges;
		//collect the components
		while (!topSort.empty())
		{
			char vert = topSort.top();
			string str;
			if (visited.find(vert) == visited.end())
				DFS(vert, visited, 1, topSort, str);
	
			topSort.pop();
			if (!str.empty())
				result.push_back(str);
		}

		//print the result
		list<string>::iterator it;
		for (it = result.begin(); it != result.end(); ++it)
			cout << *it << endl;
	}

};


int main() {
	Graph g;
	g.addEdge('b', 'c');
	g.addEdge('c', 'a');
	g.addEdge('a', 'b');
	g.addEdge('b', 'd');
	g.addEdge('d', 'e');
	g.addEdge('e', 'f');
	g.addEdge('f', 'd');
	g.addEdge('g', 'f');
	g.addEdge('g', 'h');
	g.addEdge('h', 'i');
	g.addEdge('i', 'j');
	g.addEdge('j', 'g');
	g.addEdge('j', 'k');

	g.strongContedComp();

	return 0;
}