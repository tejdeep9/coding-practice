/* 
algorithm:
1. declare a counter array with a size of maximum element in the input array.
2. initialize every element in the array to 0;
3. for each element in the input array, increment counter[elem];
4. after counting occurrences of the elements. modify the counter by making
	counter[i]+=counter[i-1] cumulatively. 
5. now the (counter[elem]-1) will give index of output array to place the elem.

TimeComplexity: O(n+k), n is size of input and k is the range of values.
Space Complexity :O(n+k).

Properties: 
1.it is linear time sorting algorithm, 
2.it is unsuitable when input is lesser in size than the range of values in the input for example, 5,10K,3 100.
3. it is often used as sub routine for Radix sort.
4. counting sort uses sort of hashing can find the occurrences of the object in O(1).
*/

#include <iostream>
#include <cstring>
#include <algorithm>

#define ASCII_SIZE 256
using namespace std;

int* CountingSort(int* arr,int len)
{
	int max=*max_element(arr,arr+len);
	int counter[max+1]={0};
	int* output=new int[len];
	
	for(int i=0; i<len ;i++)
		counter[arr[i]]++;

	for(int i=1;i<max+1;i++)
		counter[i]+=counter[i-1];
		
	for(int i=0;i<len;i++)
	{
		output[counter[arr[i]]-1]=arr[i];
		counter[arr[i]]--;
	}
	
	return output;
}

char* CountingSort(char* str)
{
	int counter[ASCII_SIZE]={0};
	int len=strlen(str);
	char* output=new char[len+1];
	for(int i=0;i<len;i++)
		counter[str[i]]++;
	
	for(int i=1;i<ASCII_SIZE;i++)
		counter[i]+=counter[i-1];
	
	for(int i=0;i<len;i++)
	{
		output[counter[str[i]]-1]=str[i];
		counter[str[i]]--;
	}	
	
	output[len]='\0';
	return output;
}
int main() {
	char str[]="practice";
	char* output=CountingSort(str);
	cout<<output<<endl;
	
	int arr[]={2,4,8,9,6,3,2,1,0,7,8,5};
	int len=extent<decltype(arr)>::value;
	int* result=CountingSort(arr,len);
	for(int i=0; i<len;i++)
		cout<<result[i]<<'\t';
	delete result;
	return 0;
}