#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int knapSack_Problem(int target_weight, vector<int>& values, vector<int>& weights)
{

	int n = values.size(); //number of items

	//declare a dp array;
	int** dp = new int*[n];

	for (int i = 0; i < n; i++)
		dp[i] = new int[target_weight + 1];

	//we need to take care for the first item
	for (int w = 0; w <= target_weight; w++)
	{
		if (weights[0] <= w)
		{
			dp[0][w] = values[0];
		}
		else
			dp[0][w] = 0;
	}
		


	//iterate through all the items and update the dp table
	for (int item = 1; item < n; item++)
	{
		for (int w = 0; w <= target_weight; w++)
		{
			if (weights[item] <= w)
			{
				dp[item][w] = max(values[item] + dp[item-1][w - weights[item]], dp[item-1][w]);
			}
			else
			{
				dp[item][w] =dp[item - 1][w];
			}
		}

	}
	
	//just for the debugging purpose
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= target_weight; j++)
		{
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	return dp[n-1][target_weight];
}

int main() {
	vector<int> values = { 1, 4, 5, 7 };
	vector<int> weights = { 1, 3, 4, 5 };
	int target_weight = 7;
	cout << knapSack_Problem(target_weight, values, weights) << endl;
	return 0;
}
