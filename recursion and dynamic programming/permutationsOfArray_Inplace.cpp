#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

/* 
algorithm:
1. The idea is to swap the first element with itself and other elements in the array iteratively from left to right.
2. For each swap call the function recursively from element but one position to the end.
3. In the base case when left and right index match, print the string.
5. After calling function recursively again swap the elements to the original position iteratively.

Time Complexity: O(n*n!).
*/

void permutations_inplace(char* arr, int l, int r)
{
	if(l==r)
		cout<<arr<<endl;
	else
	{
		for(int i=l;i<=r;i++)
		{
			swap(arr[l],arr[i]);
			permutations_inplace(arr,l+1,r);
			swap(arr[l],arr[i]);
		}
	}
}
int main() {
	char str[]="ABC";
	int n=strlen(str);
	permutations_inplace(str,0,n-1);
	return 0;
}