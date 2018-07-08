#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int Partition(vector<int>& arr, int low, int high)
{
	int pivot=arr[high];
 
	int i=low;
	for(int j=low; j<=high-1; j++)
	{
		if(arr[j] <= pivot)
		{
			swap(arr[i],arr[j]);
			i++;
		}
	}
	swap(arr[i],arr[high]);
	return i;
}
 
void QuickSort(vector<int>& arr, int low, int high)
{
	if(low < high)
	{
	    int pivot =Partition(arr, low, high);
 
	    QuickSort(arr, low, pivot-1);
	    QuickSort(arr, pivot+1, high);
	}
}
 
 
int main() {
 
	vector<int> arr= {10,80,30,90,40,50,70};
	QuickSort(arr,0,arr.size()-1);
	for(auto& x: arr)
		cout<<x<<' ';
	cout<<endl;
	return 0;
}