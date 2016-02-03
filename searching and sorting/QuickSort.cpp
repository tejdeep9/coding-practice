#include <iostream>
#include <algorithm>
using namespace std;
/*
algorithm: 
1. Choose a pivot value randomly
2. The values that are less than the pivot value should be in left of pivot..
3. The values that are greater than pivot value should be in right of pivot.
4. put two iterators at start and end. and increase the start and decrease the end 
	when values at left and right iterators are not in correct order, so swap them 
	until left<=right.
5. call the quick sort recursively from start, right, if start<right. and  from 
	left to end, when left<end.
	
Time Complexity: O(nlogn) average case, worst case O(n2)(when the last element is taken
	as pivot in sorted array).
Space Complexity: O(logn) size of recursion stack,O(n) in worst case.
properties: not adaptive, not stable.
suitable for sorting big data volumes.	
*/
void QuickSort(int* arr,int start, int end)
{	
		int i=start, j=end;
		int pivot=(i+j)/2;
		
		while(i<j)
		{
			while(arr[pivot]<arr[j]) j--;
			while(arr[pivot]>arr[i]) i++;
			
			if(i<=j)
			{
				swap(arr[i],arr[j]);
				i++;
				j--;
			}
		}
		if(start<j)
			QuickSort(arr,start,j);
		if(end>i)
			QuickSort(arr,i,end);
}

int main() {
	int arr[]={2,4,8,9,6,3,2,1,0,7,8,5};
	int len=extent<decltype(arr)>::value;
	QuickSort(arr,0,len-1);
	for(int i=0;i<len;i++)
		cout<<arr[i]<<'\t';
	cout<<endl;
	return 0;
}