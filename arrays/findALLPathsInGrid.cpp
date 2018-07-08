#include <iostream>
#include <string>
using namespace std;

void printAllPaths(int maze[4][3], int x, int y, int m, int n, string path)
{
	if(x == m-1)
	{
		for(int j=y; j<n; j++)
			path=path+ to_string(maze[x][j]);
		cout<<path<<endl;
		return;
	}
	
	if(y == n-1)
	{
		for(int i=x; i<m; i++)
			path=path+to_string(maze[i][y]);
		cout<<path<<endl;
		return;
	}
	
	path=path+to_string(maze[x][y]);
	printAllPaths(maze, x+1, y, m,n,path);
	printAllPaths(maze, x, y+1, m,n,path);
}

int main() {
	int maze[4][3]= { {1, 2, 3},
					{4, 5, 6},
					{7, 8, 9},
					{1, 2, 3}};
					
	string path="";
	printAllPaths(maze,0,0,4,3, path);
	return 0;
}