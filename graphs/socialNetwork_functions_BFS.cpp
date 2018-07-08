#include <iostream>
#include <list>
#include <iterator>
#include <unordered_map>
#include <unordered_set>
using namespace std;
class Graph
{
	unordered_map<char, list<char>> edgesOf;
	unordered_set<char> vertices;
	
	unordered_map<char, char> parent;
	unordered_map<char, int> level;

public:

	//for the undirected graph
	void addEdge(char v, char w)
	{
		vertices.insert(v);
		vertices.insert(w);
		edgesOf[v].push_back(w);
		edgesOf[w].push_back(v);
	}
	
	void BFS(char s)
	{
		//declare hashmap to store friends at each level
		list<list<char>> friendsAtLevel;
		//clear the parents and level at the beginning
		parent.clear();
		level.clear();

		//initialize the level and parent of the root node
		level[s] = 0;
		parent[s] = '\0';

		list<char> frontier;
		frontier.push_back(s); //intialize frontier to root vertex

		int distance = 1; //ditance of each level from the root node

		while (!frontier.empty())
		{
			//next frontier;
			list<char> nextFrontier;

			list<char>::iterator i;
			for (i = frontier.begin(); i != frontier.end(); i++)
			{
				char u = *i; //vertex in the frontier
				
				//iterate through all the neighbours
				list<char>::iterator v;
				for (v = edgesOf[u].begin(); v!= edgesOf[u].end(); ++v)
				{
					if (level.find(*v) == level.end())
					{
						level[*v] = distance; //update the level
						parent[*v] = u;       //update the parent 
						nextFrontier.push_back(*v); //push the vertex into the next frontier
					}
				}
			}
			//push the frontier into the result
			friendsAtLevel.push_back(frontier);
			frontier.clear();
			frontier.assign(nextFrontier.begin(), nextFrontier.end());
			distance++;;
		}
	
		list<list<char>>::iterator x;
		list<char>::iterator y;

		for(x=friendsAtLevel.begin(); x!=friendsAtLevel.end(); ++x)
		{
			for(y=x->begin(); y!=x->end(); ++y)
			{
				cout<<*y<<" ";
			}
			cout<<endl;
		}
	}


	void BFS(char s, int l)
	{
		if(l<0)
			return;
		//declare hashmap to store friends at each level
		unordered_map<int,list<char>> friendsAtLevel;
		//clear the parents and level at the beginning
		parent.clear();
		level.clear();

		//initialize the level and parent of the root node
		level[s] = 0;
		parent[s] = '\0';

		list<char> frontier;
		frontier.push_back(s); //intialize frontier to root vertex

		int distance = 1; //ditance of each level from the root node

		while (!frontier.empty())
		{
			//next frontier;
			list<char> nextFrontier;

			list<char>::iterator i;
			for (i = frontier.begin(); i != frontier.end(); i++)
			{
				char u = *i; //vertex in the frontier

				//iterate through all the neighbours
				list<char>::iterator v;
				for (v = edgesOf[u].begin(); v!= edgesOf[u].end(); ++v)
				{
					if (level.find(*v) == level.end())
					{
						level[*v] = distance; //update the level
						parent[*v] = u;       //update the parent 
						nextFrontier.push_back(*v); //push the vertex into the next frontier
					}
				}
			}
			//push the frontier into the result
			friendsAtLevel[distance-1]=frontier;
			if((distance-1)==l)
				break;
			frontier.clear();
			frontier.assign(nextFrontier.begin(), nextFrontier.end());
			distance++;;
		}
	
		if(l > friendsAtLevel.size()-1)
				return;
		list<char>::iterator it;
		for(it=friendsAtLevel[l].begin(); it!=friendsAtLevel[l].end(); ++it)
			cout<<*it<<" ";
		cout<<endl;
	}
	
	void findMutualFriends(char v, char w)
	{
		unordered_set<char> mutualFriends;
		mutualFriends.insert(edgesOf[v].begin(),edgesOf[v].end());
		
		list<char>::iterator it;
		for(it=edgesOf[w].begin(); it!=edgesOf[w].end(); ++it)
		{
			if(mutualFriends.find(*it)!=mutualFriends.end())
				cout<<*it<<" ";
		}
		cout<<endl;
	}
	


};
int main() {
	Graph g;
	g.addEdge('s', 'a');
	g.addEdge('a', 'z');
	g.addEdge('s', 'x');
	g.addEdge('x', 'c');
	g.addEdge('c', 'v');
	g.addEdge('v', 'f');
	g.addEdge('x', 'd');
	g.addEdge('f', 'd');
	g.addEdge('c', 'd');
	g.addEdge('c', 'f');

	g.BFS('s');
	//g.BFS('s',0);
	//g.findMutualFriends('s','c');

	return 0;
}