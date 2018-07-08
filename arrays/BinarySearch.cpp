#include <iostream>
using namespace std;

int sorted_search(int* elements, int n, int target)
{
	int left=0, right=n-1;
	while(left<right)
	{
		int middle=(left+right)/2;
		if(elements[middle]==target) return middle;
		if(elements[middle]>target)
			right=middle-1;
		else
			left=middle+1;
	}
	
	if(elements[right]==target) return right;
	return -1;
	
}

int main() {
	
	int elements[]={2,4,7,9,17,23,56,78};
	cout<<sorted_search(elements,8,78)<<endl;
	// your code goes here
	return 0;
}