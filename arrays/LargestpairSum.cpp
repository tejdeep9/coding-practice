#include <iostream>
#include <limits>
using namespace std;

int LargestPairSum(int* arr, int len)
{
	int max1=arr[0];
	int max2;

	for(int i=1;i<len;i++)
	{
		if(max1<arr[i])
		{	
			max2=max1;
			max1=arr[i];
		}
	}
	
	int sum=max1+max2;
	return sum;
}

int main() {
	int arr[]={12, 34, 10, 6, 40};
	cout<<LargestPairSum(arr, 5);
	return 0;
}