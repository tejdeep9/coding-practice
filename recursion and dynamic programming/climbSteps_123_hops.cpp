/*
statement: there are n steps, person can climb in 1,2,3 hops find the number of possible ways to climb steps.
algorithm:
1. at each step a person can climb 1 ,2, 3 hops. hence we need call function recursively 3 steps by passing
	n-1, n-2, n-3 as inputs, as there is chance of visiting func(n) many times due to exponential increase in 
	recursion, we should use unordered_map to track the visited areas.
2. for each function call check whether it is visited else sum up all the 3 function call results n-1, n-2,n-3
	and sum all of them up and store it in a map.

Time Complexity: without Dynamic Programming, O(3^n), With Dynamic Programming O(n).
Space Complexity:O(n).
*/


#include <iostream>
#include <unordered_map>
using namespace std;
int countWays(int n, unordered_map<int, int>& map)
{
	if (n<0)
		return 0;
	if (n == 0)
		return 1;
	else if (map.find(n) != map.end())
		return map[n];
	else
	{
		map[n] = countWays(n - 1, map) + countWays(n - 2, map) + countWays(n - 3, map);
		return map[n];
	}
}
int main() {
	int n = 6;
	unordered_map<int, int> map;
	cout << countWays(n, map) << endl;
	return 0;
}