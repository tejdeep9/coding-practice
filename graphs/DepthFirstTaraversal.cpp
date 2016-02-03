#include <iostream>
#include <list>
using namespace std;

class Graph{
	private:
		int V;
		list<int> *adj; //array of lists to store the edges
		void DFSUtil(int v, bool* visited);
	public:
		Graph(int V);
		void addEdge(int v, int w);
		void DFS(int s);
		void DFS();
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

void Graph::DFSUtil(int v, bool* visited)
{
	visited[v]=true;
	cout<<v<<'\t';
	for(list<int>::iterator it=adj[v].begin();it!=adj[v].end();it++)
	{
		if(!visited[*it])
			DFSUtil(*it,visited);
	}
}

//DFS that visits all the nodes
void Graph::DFS()
{
	bool* visited=new bool[V];
	for(int i=0;i<V;i++)
		visited[i]=false;
	for(int i=0;i<V;i++)
	if(!visited[i])
		DFSUtil(i,visited);
	cout<<endl;
	
}
//DFS with reachable nodes
void Graph::DFS(int s)
{
	bool* visited=new bool[V];
	for(int i=0;i<V;i++)
		visited[i]=false;
	DFSUtil(s,visited);
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
	g.DFS(2);
	g.DFS();
	
	return 0;
}