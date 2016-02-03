#include <iostream>
#include <list>
using namespace std;

class Graph{
	private:
		int V;
		list<int> *adj; //array of lists to store the edges
	public:
		Graph(int V);
		void addEdge(int v, int w);
		void BFS(int s);
};

Graph::Graph(int V)
{
	this->V=V;
	this->adj= new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w);
}
/*
1. create a boolean array of the visited nodes initialized to false.
2. declare list of visited nodes, add the supplied node to the queue.
3. until the queue is empty iterate through the visited nodes list.
4. while iterating the output the front element and add the unvisited nodes present in the adjacency list of front element.

note: all vertices may not be reachable

Time Complexity: O(V+E).
*/
void Graph::BFS(int s)
{
	bool* visited=new bool[V];
	for(int i=0;i<V;i++)
		visited[i]=false;
	
	list<int> q; //visited nodes queue.
	
	visited[s]=true;
	q.push_back(s);
	
	while(!q.empty())
	{	int node=q.front();
		q.pop_front();
		cout<<node<<'\t';
		for(list<int>::iterator it=adj[node].begin();it!=adj[node].end();it++)
		{
			if(!visited[*it])
			{
				q.push_back(*it);
				visited[*it]=true;
			}
		}
	}
	
	cout<<endl;
	
}
int main() {
	Graph g(4);
	g.addEdge(0,2);
	g.addEdge(0,1);
	g.addEdge(1,2);
	g.addEdge(2,0);
	g.addEdge(2,3);
	g.addEdge(3,3);
	g.BFS(2);
	
	return 0;
}