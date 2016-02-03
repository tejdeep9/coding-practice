#include <iostream>
#include <cstdlib>
using namespace std;
//time complexity is O(logn); space complexity is O(1);
int findPeakElement(int* arr, int n){
	int start=0, end =n-1;

	while(start<=end){
		int mid= (start+end)/2;
		if((mid==0||arr[mid]>=arr[mid-1])&&(mid==n-1||arr[mid]>=arr[mid+1]))
		{
			return arr[mid];
		}
		else if(arr[mid]<arr[mid-1])
		{
			end=mid-1;
		}
		else
		{
			start=mid+1;	
		}
	}
	return NULL;
}

int main() {
	int arr[]={5,10,15,20,25,30,45,65,50,35,1};
	int n=11;
	cout<<findPeakElement(arr,11);
	return 0;
}