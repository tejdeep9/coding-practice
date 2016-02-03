#include <iostream>
#include <algorithm>
using namespace std;
/*
algorithm:
1. The array is divided into two parts sorted part and unsorted part.
2. Initially the whole array is considered as unsorted and sorted part has the size=0.
3. In each iteration find the minimum element and place it at the end of the sorted part.

TimeComplexity: O(n2)
Space Complexity: O(1).

Properties: not stable, not adaptive, only number of swaps is minimized, average case complexity O(n2).
not suitable for large data volumes. O(n) swaps at max. 
*/
void SelectionSort(int* arr,int len)
{
	for(int i=0 ;i<len-1; i++)
	{
		int minIndex=i;
		for(int j=i+1; j<len; j++)
			if(arr[minIndex]>arr[j])
				minIndex=j;
		swap(arr[minIndex],arr[i]);
	}
}

int main() {
	int arr[]={2,4,8,9,6,3,2,1,0,7,8,5};
	int len=extent<decltype(arr)>::value;
	SelectionSort(arr,len);
	for(int i=0;i<len;i++)
		cout<<arr[i]<<'\t';
	cout<<endl;
	return 0;
}