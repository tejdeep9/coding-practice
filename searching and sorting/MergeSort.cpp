#include <iostream>
#include <vector>

using namespace std;

//Time complexity : O(nlogn) in all 3 cases (worst, avg, best)
//Spcae complexity : O(n)
void merge(vector<int>& nums, int l, int m, int r)
{
	int n1 = m-l+1;
	int n2= r-m;
	
	int arr1[n1], arr2[n2];
	int i, j, k=l;
	for(i=0; i < n1; i++)
		arr1[i] = nums[l+i];
	for(j=0; j < n2; j++)
		arr2[j] = nums[m+1+j];
	
	 i=0; j=0; 
	
	while( i < n1 && j < n2)
	{
		if(arr1[i] <= arr2[j])
		{
			nums[k++]=arr1[i++];
		}
		else
		{
			nums[k++]=arr2[j++];
		}
	}
	
	while( i < n1)
	{
		nums[k++]=arr1[i++];
	}
	
	while( j < n2)
	{
		nums[k++] =arr2[j++];
	}
	
}
void mergeSort(vector<int>& nums, int l , int r)
{
	if(l < r)
	{
		int m = (l+r)/2;
		mergeSort(nums, l, m);
		mergeSort(nums, m+1, r);
		merge(nums, l, m ,r);
	}
}

int main()
{
	vector<int> nums ={12, 11, 13, 5, 6, 7};
	mergeSort(nums,0, nums.size()-1);
	for(auto & a: nums)
		cout<< a << " ";
	cout<<endl;
}