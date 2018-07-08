#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void EvenLists(vector<int> inputList)
{
	int n = inputList.size();
	if (n % 2 != 0)
		return;

	vector<int> list1;
	vector<int> list2;
	int sum1 = 0;
	int sum2 = 0;

	//sort the input
	sort(inputList.begin(), inputList.end());

	for (int i = n - 1; i >= 0; i--)
	{
		if (sum1 < sum2 && list1.size() < (n / 2))
		{
			list1.push_back(inputList[i]);
			sum1 += inputList[i];
		}
		else
		{
			list2.push_back(inputList[i]);
			sum2 += inputList[i];
		}
	}

	for (auto &x : list1)
		cout << x << " ";
	cout << endl;

	for (auto &x : list2)
		cout << x << " ";
}
int main() {
	vector<int> inputList = { 50, 10, 200, 150, 900, 250, 40, 50, 950, 5, 90, 80, 60, 600 };
	EvenLists(inputList);
	return 0;
}
