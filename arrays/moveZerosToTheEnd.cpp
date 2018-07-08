#include <iostream>
#include <algorithm>
using namespace std;

void moveAllZerosToEndNoOrder(int* arr, int n)
{
	int left=0, right=n-1;
	
	while(left<right)
	{
		while(arr[left]!=0)
			left++;
		while(arr[right]==0)
			right--;
		if(left<right)
			swap(arr[left],arr[right]);
		left++;
		right--;
	}
}

void moveAllZerosToEndWithOrder(int* arr, int n)
{
	int index=0,swapIndex=0;
	while(index<n)
	{
		while(arr[index]!=0)
			index++;
			
		if(index<n)
			swapIndex=index;
		else
			break;
			
		while(arr[swapIndex]==0)
			swapIndex++;
			
		if(swapIndex<n)
			swap(arr[index],arr[swapIndex]);
		else
			break;
		index++;
	}
}

void simpleSoultion(int* arr, int n)
{
	int count=0;
	
	for(int i=1; i<n; i++)
	{
		if(arr[i]!=0)
			arr[count++]=arr[i];
	}
	
	while(count<n)
	arr[count++]=0;
}
int main() {
	int arr[]={0, 1, 0, 0, 0, 0, 9, 0, 0, 0, 0, 8, 4, 0, 0, 2, 0, 7, 0, 6, 0};
	int n=extent<decltype(arr)>::value;
	simpleSoultion(arr,n);
	
	for(int i=0; i<n ;i++)
		cout<<arr[i]<<'\t';
		cout<<endl;
	
	return 0;
}