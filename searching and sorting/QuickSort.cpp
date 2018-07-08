#include <iostream>
using namespace std;

//objective is to divide the array around the partition such that the elements on the left are less than pivot  
//and the elements on the right side are are greater than the pivot.
int Partition(int* arr, int left, int right)
{
    int i=left, j=right;
    
    int pivot= (arr[left]+arr[right])/2;
    
    while(i<=j)
    {
        //skip if element in the left partion is less than the pivot
        while( arr[i] < pivot)
            i++;
        //skip the element that are in the right are greater than the pivot
        while( arr[j] > pivot)
            j--;
            
        if(i<=j)
        {
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
            
            i++;
            j--;
        }
        
    }
    
    return i;
}
//space complexity: O(1);
//time complexity: O(n2);
void QuickSort(int* arr, int left, int right)
{
    int index= Partition(arr, left, right);
    
    if(left < index-1)
        QuickSort(arr,left,index-1);
    if(right > index)
        QuickSort(arr,index,right);
}

int main() {
	//int arr[]={1, 12, 5, 26, 7, 14, 3, 7, 2};
	int arr[]={5, 2, 3, 6, 12, 7, 14, 9, 10, 11};
	int n=sizeof(arr)/sizeof(int);
	QuickSort(arr, 0, n-1);
	
	for(int i=0; i<n; i++)
	    cout<<arr[i]<<" ";
	cout<<endl;
	return 0;
}
