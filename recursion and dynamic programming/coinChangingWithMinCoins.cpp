#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
using namespace std;

void minCoins(vector<int> coins, int total)
{
	vector<int> T;
	vector<int> pos;
	
	for(int i=0; i<=total; i++)
	{
		T.push_back(INT_MAX);
		pos.push_back(-1);
	}
	T[0]=0;
	
	for(int j=0; j<coins.size(); j++)
	{
		for(int i=0; i<T.size(); i++)
		{
			if(i >= coins[j])
			{
				if(T[i-coins[j]] != INT_MAX)
				{
					T[i]=min(T[i], 1+T[i-coins[j]]);
					if(T[i] == 1+T[i-coins[j]])
					pos[i]=j;
				}
			}
		}
	}
	
	cout<<"the number of coins needed is"<<T[total]<<endl;
	
	cout<<"the number of coins are"<<endl;

	int sum= total;
	
	while(total>0)
	{
		cout<<coins[pos[total]]<<',';
		total=total-coins[pos[total]];
	}
	cout<<endl;
}
int main() {
	
	//vector<int> coins {1,5,6,8};
	vector<int> coins {7,2,3,6};
	minCoins(coins,13);
	return 0;
}