#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int knapSack_Problem(int target_weight, vector<int>& values, vector<int>& weights)
{

	int n = values.size(); //number of items

	//declare a  vector to poplulated the values for each item make it default as 0 values
	vector<int> dp;
	for (int w = 0; w <= target_weight; w++)
		dp.push_back(0);

	//iterate through all the items and update the dp table
	for (int item = 0; item < values.size(); item++)
	{
		for (int w = 0; w <= target_weight; w++)
		{
			if (weights[item] <= w)
			{
				dp[w] = max(values[item] + dp[w - weights[item]], dp[w]);
			}
		}
	}

	for (int i = 0; i <= target_weight; i++)
		cout << dp[i] << " ";
	cout << endl;
	return dp[target_weight];
}

int main() {
	vector<int> values = { 1, 4, 5, 7 };
	vector<int> weights = { 1, 3, 4, 5 };
	int target_weight = 7;
	cout << knapSack_Problem(target_weight, values, weights) << endl;
	return 0;
}
