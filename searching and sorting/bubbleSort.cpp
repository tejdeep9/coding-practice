#include <iostream>
#include <algorithm>
using namespace std;

/* algorithm:
1. iterate through array and find whether adjacent elements are in reverse order, 
	if not in order swap them. 
2. if atleast one swap occurs iterate again  by decreasing length of the array by 1 step.
3. during every iteration the element with highest value will be bubbled to the end of the array,
	if the array is sorted in ascending order.

Time Complexity: O(n2)
Space Complexity: O(1).
properties:
1. bubble sort is adaptive( if the array is sorted, time complexity will be O(n)),
2. bubble sort is stable (order of elements is preserved).
3. it is unsuitable for the large data volumes.
4. it has average and worst case complexity O(n2).
*/
void BubbleSort(int* arr,int len)
{
	bool swapped=true;
	int i=0;
	while(swapped)
	{	
		swapped=false;
		for(int j=0;j<len-1-i;j++)
		{
			if(arr[j]>arr[j+1])
			{
				swap(arr[j],arr[j+1]);
				swapped=true;
			}
		}
		i++;
	}
}

int main() {
	int arr[]={2,4,8,9,6,3,2,1,0,7,8,5};
	int len=extent<decltype(arr)>::value;
	BubbleSort(arr,len);
	for(int i=0;i<len;i++)
		cout<<arr[i]<<'\t';
	cout<<endl;
	return 0;
}