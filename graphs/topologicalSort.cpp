#include <iostream>
#include <list>
#include <stack>
using namespace std;
/*
space complexity: O(V+E);
time complexity: O(V+E);
*/
class Graph{
	int v;
	list<int>* adj;
	
	public:
	Graph(int v)
	{
		this->v=v;
		adj=new list<int>[v];
	}
	
	void addEdge(int v, int w)
	{
		adj[v].push_back(w);
	}
	
	void topSort()
	{
		bool* visited=new bool[v];
		stack<int> order;
		
		for(int i=0; i<v; i++)
			visited[i]=false;
		
		for(int s=0; s<v; s++)
		{
			if(!visited[s])
				topSortUtil(s,order,visited);
		}
		
		while(!order.empty())
		{	
			cout<<order.top()<<'\t';
			order.pop();
		}
		cout<<endl;
	}
	
	void topSortUtil(int s,stack<int>& order, bool* visited)
	{
		visited[s]=true;
		
		list<int>::iterator it;
		
		for( it=adj[s].begin(); it!=adj[s].end(); ++it)
		{
			if(!visited[*it])
				topSortUtil(*it,order,visited);
		}
		
		order.push(s);
	}
};

int main() {
	Graph g(7);
	g.addEdge(0,2);
	g.addEdge(1,2);
	g.addEdge(2,4);
	g.addEdge(1,3);
	g.addEdge(4,5);
	g.addEdge(3,5);
	g.addEdge(5,6);
	g.topSort();
	return 0;
}