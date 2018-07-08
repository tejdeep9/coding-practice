/*Question: Imagine you have a 2D array that represents a ski slope (see figure below).
An index with a value of 1 represents a tree. The skier can only travel right and down along the array.
Write an algorithm to determine whether a clear path exists for the skier to cross the finish line.
https://docs.google.com/file/d/0B7kEUUtxfkFKZ0oyRFdRY3lEMzQ/edit*/
#include <iostream>
using namespace std;

int SolveMaze(int (* mountain)[8], int i, int j, int m, int n)
{
	if(i >= 0 && i < m && j >= 0 && j < n)
	{
		if(i == m-1 && j == n-1)
			return 1;
		if(mountain[i][j]==0)
		{
			mountain[i][j]=1;

			if(SolveMaze(mountain,i+1,j,m,n)==1)
				return 1;
			if(SolveMaze(mountain,i,j+1,m,n)==1)
				return 1;
		}
	}
	return 0;
}

int main() {
	int n=8;
	int mountain[8][8]={  {0,0,0,0,0,1,0,1},
						  {0,0,0,1,0,1,0,0},
						  {1,0,1,0,0,0,1,0},
						  {1,0,0,0,0,1,0,0},
						  {0,1,1,1,0,0,0,1},
						  {0,0,0,0,0,1,0,1},
						  {0,0,0,1,0,1,0,0},
						  {0,1,1,0,1,0,0,0}};
	cout<<SolveMaze(mountain,0,0,n,n)<<endl;
	return 0;
}