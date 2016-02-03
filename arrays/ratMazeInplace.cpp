#include <iostream>

using namespace std;
int SolveMaze(int (*grid)[4],int x,int y,int m,int n){
  if(x>=0&&x<m&&y>=0&&y<n)
  {
    if(grid[x][y]==9)
      return 1;
    if(grid[x][y]==1)
    {
      grid[x][y]=0;
      if(SolveMaze(grid,x-1,y,m,n)==1)
        return 1;
      if(SolveMaze(grid,x+1,y,m,n)==1)
        return 1;
      if(SolveMaze(grid,x,y-1,m,n)==1)
        return 1;
      if(SolveMaze(grid,x,y+1,m,n)==1)
        return 1;
      return 0;
    }
  }
  return 0;
}
// To execute C++, please define "int main()"
int main() {

  int grid[][4] = {{1,1,1,1}, {1,0,0,0},{1,0,9,0},{1,0,0,0},{1,1,1,0}};
  if(SolveMaze(grid,0,0,5,4))
    cout<<"the maze is solvable"<<endl;
  else
    cout<<"The maze is not solvable"<<endl;
    return 0;
}
