#include <iostream>
#include <algorithm>
using namespace std;
/* algorithm:
1. In pass P the elements from 0 to P-1 are sorted.
2. Just insert Pth element in sorted part that is 0 to P-1.

Time Complexity: O(n2).
Space Complexity: O(1).

properties: 
1. stable, adaptive, online(new elements can be added while sorting), used as base case in quick sort and merge sort.
*/
void InsertionSort(int* arr,int len)
{
	for(int i=1;i<len;i++)
	{
		for(int j=i; j>0&&arr[j-1]>arr[j]; j--)
			swap(arr[j-1],arr[j]);
	}
}

int main() {
	int arr[]={2,4,8,9,6,3,2,1,0,7,8,5};
	int len=extent<decltype(arr)>::value;
	InsertionSort(arr,len);
	for(int i=0;i<len;i++)
		cout<<arr[i]<<'\t';
	cout<<endl;
	return 0;
}