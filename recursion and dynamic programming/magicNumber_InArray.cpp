#include <iostream>
using namespace std;

/*
if the given array is sorted and elements are distinct.
algorithm: 
1. using binary search find the middle index. if it is equal to the given element return it.
2. if the arr[mid]>mid as the array has distinct elements in the sorted form increasing the index 
   arr[mid+k]>mid+k for every value of k. hence we need to search only on the left side of the array.
3. if the arr[mid]<mid as the array has distinct elements in the sorted form decreasing the index 
   arr[mid-k]<mid-k for every value of k. hence we need to search only on the right side of the array.
   
TimeComplexity: O(logn)
Space Complexity: O(logn)
*/
int findMagicElem_In_UniqSortedArray(int* arr, int start, int end)
{
	if(start>end)
		return -1;
	int mid=(start+end)/2;
	if(arr[mid]==mid)
		return mid;
	else if(arr[mid]>mid)
		return findMagicElem_In_UniqSortedArray(arr,start,mid-1);
	else
		return findMagicElem_In_UniqSortedArray(arr,mid+1,end);
	
}
/*
if the given array has duplicate elements in the sorted form 
algorithm:
	1. using binary search find the middle index. if it is equal to the given element return it.
	2. As the array is sorted and has duplicates we cannot apply the above analogy, hence we need
	   to search on the both sides middle element of the array. with little improvement.
	3. if arr[mid]>mid as the array has duplicates we need to search on right side too but from arr[arr[mid]] to arr[end].
	4. if arr[mid]<mid as the array has duplicates we need to search on left side too but from arr[start]to arr[arr[mid]].
	
TimeComplexity: O(logn).
Space Complexity: O(logn).
*/
int findMagicElem_In_SortedArray(int* arr, int start, int end)
{
	if(start>end)
		return -1;
	int mid=(start+end)/2;
	if(arr[mid]==mid)
		return mid;
	
	int rightIndex=max(mid+1,arr[mid]);
	int right=findMagicElem_In_SortedArray(arr,rightIndex,end);
	if(right>=0)
		return right;
		
	int leftIndex=min(mid-1,arr[mid]);
	int left=findMagicElem_In_SortedArray(arr,start,leftIndex);
	return left;

}

int main() {
	int uniq_arr[]={-40,-20,-1,1,2,3,5,7,9,12,13};
	int dup_arr[]={-10,-5,2,2,2,3,4,8,9,12,13};
	int len=extent<decltype(dup_arr)>::value;
	//cout<<findMagicElem_In_UniqSortedArray(uniq_arr,0,len-1);
	cout<<findMagicElem_In_SortedArray(dup_arr,0,len-1);
	return 0;
}